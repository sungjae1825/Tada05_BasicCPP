#include "CAR4.h"
#include "Components/SkeletalMeshComponent.h"
#include "GameFramework/Character.h"

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


	HolsterSocket = "Holster_AR4";
	HandSocket = "Hand_AR4";
}

void ACAR4::BeginPlay()
{
	Super::BeginPlay();
	OwnerCharacter = Cast<ACharacter>(GetOwner());
	AttachToComponent(OwnerCharacter->GetMesh(), FAttachmentTransformRules(EAttachmentRule::KeepRelative, true), HolsterSocket);

	AttachToComponent();

}

void ACAR4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

