#include "CPlayer.h"
#include "Utilities/CLog.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Weapons/CAR4.h"

ACPlayer::ACPlayer()
{
	PrimaryActorTick.bCanEverTick = true;

	//Mesh Comp
	ConstructorHelpers::FObjectFinder<USkeletalMesh> MeshAsset(TEXT("/Game/Character/Mesh/SK_Mannequin"));
	if (MeshAsset.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(MeshAsset.Object);
	}
	GetMesh()->SetRelativeLocation(FVector(0, 0, -88));
	GetMesh()->SetRelativeRotation(FRotator(0, -90, 0));

	ConstructorHelpers::FClassFinder<UAnimInstance> AnimInstanceClass(TEXT("/Game/Player/ABP_CPlayer"));
	if (AnimInstanceClass.Succeeded())
	{
		GetMesh()->SetAnimInstanceClass(AnimInstanceClass.Class);
	}

	//SpringArm Comp
	SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(GetCapsuleComponent());
	SpringArmComp->SetRelativeLocation(FVector(0, 0, 60));
	SpringArmComp->bUsePawnControlRotation = true;
	SpringArmComp->SocketOffset = FVector(0, 60, 0);

	//Camera Comp
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	//Movement Comp
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;

	//Weapon Class
	ConstructorHelpers::FClassFinder<ACAR4> WeaponClass(TEXT("/Game/Player/BP_CAR4"));
	if (WeaponClass.Succeeded())
	{
		AR4Class = WeaponClass.Class;
	}

}

void ACPlayer::BeginPlay()
{
	Super::BeginPlay();

	if (AR4Class)
	{
		FActorSpawnParameters SpawnParams;
		SpawnParams.Owner = this;
		AR4 = GetWorld()->SpawnActor<ACAR4>(AR4Class, SpawnParams);
		AR4->Equip();
	}

}

void ACPlayer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACPlayer::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ACPlayer::OnMoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACPlayer::OnMoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &ACPlayer::OnTurn);
	PlayerInputComponent->BindAxis("LookUp", this, &ACPlayer::OnLookUp);

	PlayerInputComponent->BindAction("Sprint", IE_Pressed, this, &ACPlayer::OnSprint);
	PlayerInputComponent->BindAction("Sprint", IE_Released, this, &ACPlayer::OffSprint);

	PlayerInputComponent->BindAction("Rifle", IE_Pressed, this, &ACPlayer::OnRifle);

	PlayerInputComponent->BindAction("Aim", IE_Pressed, this, &ACPlayer::OnAim);
	PlayerInputComponent->BindAction("Aim", IE_Released, this, &ACPlayer::OffAim);
}

void ACPlayer::OnMoveForward(float Axis)
{
	FRotator ControlRot = FRotator(0, GetControlRotation().Yaw, 0);
	FVector Direction = FQuat(ControlRot).GetForwardVector().GetSafeNormal2D();

	AddMovementInput(Direction, Axis);
}

void ACPlayer::OnMoveRight(float Axis)
{
	FRotator ControlRot = FRotator(0, GetControlRotation().Yaw, 0);
	FVector Direction = FQuat(ControlRot).GetRightVector().GetSafeNormal2D();

	AddMovementInput(Direction, Axis);
}

void ACPlayer::OnTurn(float Axis)
{
	AddControllerYawInput(Axis);
}

void ACPlayer::OnLookUp(float Axis)
{
	AddControllerPitchInput(Axis);
}

void ACPlayer::OnSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 600.f;
}

void ACPlayer::OffSprint()
{
	GetCharacterMovement()->MaxWalkSpeed = 400.f;
}

void ACPlayer::OnRifle()
{
	if (AR4->IsEquipped())
	{
		OffAim();

		AR4->Unequip();
		return;
	}

	AR4->Equip();
}

void ACPlayer::OnAim()
{
	if (!AR4->IsEquipped()) return;
	if (AR4->IsPlayingMontage()) return;

	bUseControllerRotationYaw = true;
	GetCharacterMovement()->bOrientRotationToMovement = false;

	SpringArmComp->TargetArmLength = 150.f;
	SpringArmComp->SocketOffset = FVector(0, 30, 10);

	AR4->Begin_Aim();

	ZoomIn();
}

void ACPlayer::OffAim()
{
	if (!AR4->IsEquipped()) return;
	if (AR4->IsPlayingMontage()) return;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;

	SpringArmComp->TargetArmLength = 300.f;
	SpringArmComp->SocketOffset = FVector(0, 60, 0);

	ZoomOut();

	AR4->End_Aim();
}

void ACPlayer::SetBodyColor(FLinearColor InColor)
{
	FVector BodyColor = FVector(InColor.R, InColor.G, InColor.B);

	GetMesh()->SetVectorParameterValueOnMaterials("BodyColor", BodyColor);
}