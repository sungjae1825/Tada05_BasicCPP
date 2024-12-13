#include "CCone.h"

ACCone::ACCone()
{
	MeshComp =  CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	MeshComp->SetRelativeScale3D(FVector(0.5f));
	MeshComp->SetSimulatePhysics(true);
	MeshComp->SetCollisionObjectType(ECollisionChannel::ECC_PhysicsBody);

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StaticMeshes/SM_Cone"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
	}

	ConstructorHelpers::FObjectFinder<UMaterial> MaterialAsset(TEXT("/Game/Materials/M_StaticMesh"));
	if (MaterialAsset.Succeeded())
	{
		MeshComp->SetMaterial(0, MaterialAsset.Object);
	}
}