#include "CSpawner.h"
#include "CStaticMeshBase.h"
#include "Kismet/KismetMathLibrary.h"

ACSpawner::ACSpawner()
{

}

void ACSpawner::BeginPlay()
{
	Super::BeginPlay();

	//Spawn Actors
	FTransform TM;
	for (int32 i = 0; i < 4; i++)
	{
		if (!ClassesToSpawn[i])
		{
			FString Err = "missing class reference index[";
			Err.Append(FString::FromInt(i));
			Err.Append("] of array");

			GLog->Log(ELogVerbosity::Error, Err);

			continue;
		}

		SpawnedObjects[i] = GetWorld()->SpawnActor<ACStaticMeshBase>(ClassesToSpawn[i], TM);

		FVector Origin = GetActorLocation();
		SpawnedObjects[i]->SetActorLocation(Origin + FVector(0, i * 200, 0));
	}

	//Change Color

	FTimerHandle ChagneColorTimer;
	FTimerDelegate TimerDelegate;
	TimerDelegate.BindLambda([&]()
		{
			for (const auto& Object : SpawnedObjects)
			{
				UStaticMeshComponent* MeshComp = Cast<UStaticMeshComponent>(Object->GetComponentByClass(UStaticMeshComponent::StaticClass()));
				if (MeshComp)
				{
					FVector RandomVector = UKismetMathLibrary::RandomUnitVector();

					MeshComp->SetVectorParameterValueOnMaterials("BaseColor", RandomVector);

					MeshComp->SetScalarParameterValueOnMaterials("Metallic", RandomVector.X);
					MeshComp->SetScalarParameterValueOnMaterials("Roughness", RandomVector.Y);
				}
			}
		});
	GetWorld()->GetTimerManager().SetTimer(ChagneColorTimer, TimerDelegate, 1.f, true);
}