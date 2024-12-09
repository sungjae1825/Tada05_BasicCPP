#include "CCube.h"
#include "Kismet/GameplayStatics.h"
#include "Materials/MaterialInstanceConstant.h"
#include "CMulticast.h"

ACCube::ACCube()
{
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = RootComp;

	UStaticMesh* Mesh = nullptr;
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StaticMeshes/SM_Cube"));
	if (MeshAsset.Succeeded())
	{
		Mesh = MeshAsset.Object;
	}

	UMaterialInstanceConstant* Material = nullptr;
	ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> MaterialAsset(TEXT("/Game/Materials/M_StaticMesh_Inst"));
	if (MaterialAsset.Succeeded())
	{
		Material = MaterialAsset.Object;
	}

	for (int32 i = 0; i < 3; i++)
	{
		FString CompName;
		CompName.Append("MeshComp");
		CompName.Append(FString::FromInt(i + 1));

		MeshComps[i] = CreateDefaultSubobject<UStaticMeshComponent>(FName(CompName));
		MeshComps[i]->SetupAttachment(RootComp);

		MeshComps[i]->SetStaticMesh(Mesh);
		MeshComps[i]->SetMaterial(0, Material);

		MeshComps[i]->SetRelativeLocation(FVector(0, i * 150, 0));
		MeshComps[i]->SetSimulatePhysics(false);
	}
}

void ACCube::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < 3; i++)
	{
		OriginLocations[i] = MeshComps[i]->GetComponentToWorld().GetLocation();
		MeshComps[i]->SetVectorParameterValueOnMaterials("BaseColor", FVector(0.3f));
	}


	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACMulticast::StaticClass(), Actors);

	if (Actors.Num() < 1)
	{
		return;
	}

	ACMulticast* Trigger = Cast<ACMulticast>(Actors[0]);
	if (Trigger)
	{
		Trigger->OnMulticastOverlap.AddUFunction(this, "Falling");
	}
}

void ACCube::Falling(int32 InIndex, FLinearColor InColor)
{
	for (int32 i = 0; i < 3; i++)
	{
		MeshComps[i]->SetVectorParameterValueOnMaterials("BaseColor", FVector(0.3f));

		MeshComps[i]->SetWorldLocation(OriginLocations[i]);
		MeshComps[i]->SetSimulatePhysics(false);
	}

	MeshComps[InIndex]->SetSimulatePhysics(true);

	FVector Vector = FVector(InColor.R, InColor.G, InColor.B);
	MeshComps[InIndex]->SetVectorParameterValueOnMaterials("BaseColor", Vector);

}
