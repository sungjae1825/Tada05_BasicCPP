#include "CBullet.h"
#include "GameFramework/ProjectileMovementComponent.h"

ACBullet::ACBullet()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	RootComponent = MeshComp;

	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StaticMeshes/SM_Sphere"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
	}
	ConstructorHelpers::FObjectFinder<UMaterial>MaterialAsset(TEXT("/Game/Materials/M_Bullet"));

	if (MaterialAsset.Succeeded())
	{
		MeshComp->SetMaterial(0, MaterialAsset.Object);
	}

	
	MeshComp->SetWorldScale3D(FVector(1.f, 0.025f, 0.025f));
	MeshComp->SetCollisionProfileName("NoCollision");
	MeshComp->CastShadow = false;

	MoveComp = CreateDefaultSubobject<UProjectileMovementComponent>("MoveComp");
	MoveComp->InitialSpeed = 20000;
	MoveComp->MaxSpeed = 20000;
	MoveComp->ProjectileGravityScale = 0;

	InitialLifeSpan = 3.f;

}


