#include "CAR4.h"
#include "DrawDebugHelpers.h"
#include "Kismet/GameplayStatics.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"
#include "Sound/SoundCue.h"
#include "Interfaces/CWeaponInterface.h"
#include "Utilities/CLog.h"
#include "CBullet.h"

static TAutoConsoleVariable<bool> CVarDebugLine(TEXT("Tada.DebugLine"), false, TEXT("Enable draw aim line"), ECVF_Cheat);

ACAR4::ACAR4()
{
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<USkeletalMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/Weapons/Meshes/AR4/SK_AR4"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetSkeletalMesh(MeshAsset.Object);
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> EquipMontageAsset(TEXT("/Game/Character/Animations/Rifle/Rifle_Equip_Montage"));
	if (EquipMontageAsset.Succeeded())
	{
		EquipMontage = EquipMontageAsset.Object;
	}

	ConstructorHelpers::FObjectFinder<UAnimMontage> UnequipMontageAsset(TEXT("/Game/Character/Animations/Rifle/Rifle_Unequip_Montage"));
	if (UnequipMontageAsset.Succeeded())
	{
		UnequipMontage = UnequipMontageAsset.Object;
	}

	ConstructorHelpers::FClassFinder<UCameraShake> CameraShakeClass(TEXT("/Game/Player/Shake_Fire"));
	if (CameraShakeClass.Succeeded())
	{
		FireCameraShakeClass = CameraShakeClass.Class;
	}

	ConstructorHelpers::FClassFinder<ACBullet> BulletClass_Asset(TEXT("/Game/Player/BP_CBullet"));
	if (BulletClass_Asset.Succeeded())
	{
		BulletClass = BulletClass_Asset.Class;
	}

	HolsterSocket = "Holster_AR4";
	HandSocket = "Hand_AR4";
}

void ACAR4::BeginPlay()
{
	Super::BeginPlay();

	OwnerCharacter = Cast<ACharacter>(GetOwner());

	AttachToComponent
	(
		OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		HolsterSocket
	);
}

void ACAR4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!bAiming) return;

	ICWeaponInterface* OwenrInterface = Cast<ICWeaponInterface>(OwnerCharacter);
	if (!OwenrInterface) return;

	FVector Start, End, Direction;
	OwenrInterface->GetAimInfo(Start, End, Direction);

	bool bDrawDebug = CVarDebugLine.GetValueOnGameThread();
	if (bDrawDebug)
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, -1.f, 0, 3.f);
	}

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	QueryParams.AddIgnoredActor(OwnerCharacter);

	FHitResult Hit;
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_PhysicsBody, QueryParams))
	{
		if (Hit.GetComponent()->IsSimulatingPhysics())
		{
			OwenrInterface->OnTarget();
			return;
		}
	}

	OwenrInterface->OffTarget();
}

void ACAR4::Begin_Aim()
{
	bAiming = true;
}

void ACAR4::End_Aim()
{
	bAiming = false;
}

void ACAR4::Equip()
{
	if (bEquipped) return;
	if (bPlayingMontage) return;

	bEquipped = true;
	bPlayingMontage = true;

	OwnerCharacter->PlayAnimMontage(EquipMontage, 2.f);
}

void ACAR4::Begin_Equip()
{
	AttachToComponent
	(
		OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		HandSocket
	);
}

void ACAR4::End_Equip()
{
	bPlayingMontage = false;
}

void ACAR4::Unequip()
{
	if (!bEquipped) return;
	if (bPlayingMontage) return;

	bEquipped = false;
	bPlayingMontage = true;

	OwnerCharacter->PlayAnimMontage(UnequipMontage, 2.f);
}

void ACAR4::Begin_Unequip()
{
	AttachToComponent
	(
		OwnerCharacter->GetMesh(),
		FAttachmentTransformRules(EAttachmentRule::KeepRelative, true),
		HolsterSocket
	);
}

void ACAR4::End_Unequip()
{
	bPlayingMontage = false;
}

void ACAR4::Begin_Fire()
{
	if (!bEquipped) return;
	if (bPlayingMontage) return;
	if (!bAiming) return;
	if (bFiring) return;

	bFiring = true;

	Firing();
}

void ACAR4::End_Fire()
{
	bFiring = false;
}

void ACAR4::Firing()
{
	//Play CameraShake
	APlayerController* PC = OwnerCharacter->GetController<APlayerController>();
	if (PC)
	{
		PC->PlayerCameraManager->PlayCameraShake(FireCameraShakeClass);
	}

	//Play Cosmetic
	FVector MuzzleLocation = MeshComp->GetSocketLocation("MuzzleFlash");

	if (ensure(MuzzleVFX))
	{
		UGameplayStatics::SpawnEmitterAttached(MuzzleVFX, MeshComp, "MuzzleFlash");
	}

	if (ensure(EjectVFX))
	{
		UGameplayStatics::SpawnEmitterAttached(EjectVFX, MeshComp, "EjectBullet");
	}

	if (ensure(FireSound))
	{
		UGameplayStatics::PlaySoundAtLocation(GetWorld(), FireSound, MuzzleLocation);
	}

	//LineTrace
	ICWeaponInterface* OwenrInterface = Cast<ICWeaponInterface>(OwnerCharacter);
	if (!OwenrInterface) return;

	FVector Start, End, Direction;
	OwenrInterface->GetAimInfo(Start, End, Direction);

	bool bDrawDebug = CVarDebugLine.GetValueOnGameThread();
	if (bDrawDebug)
	{
		DrawDebugLine(GetWorld(), Start, End, FColor::Red, false, -1.f, 0, 3.f);
	}

	FCollisionQueryParams QueryParams;
	QueryParams.AddIgnoredActor(this);
	QueryParams.AddIgnoredActor(OwnerCharacter);

	FHitResult Hit;
	if (GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_Visibility, QueryParams))
	{
		if (Hit.GetComponent()->IsSimulatingPhysics())
		{
			FVector ImpactDirection = (Hit.GetActor()->GetActorLocation() - OwnerCharacter->GetActorLocation()).GetSafeNormal();

			Hit.GetComponent()->AddImpulseAtLocation(ImpactDirection * 3000.f, OwnerCharacter->GetActorLocation());
		}
	}

	//Spawn Bullet
	if (BulletClass)
	{
		GetWorld()->SpawnActor<ACBullet>(BulletClass, MuzzleLocation, Direction.Rotation());
	}
}

