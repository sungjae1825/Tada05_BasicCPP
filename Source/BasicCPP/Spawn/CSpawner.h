#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSpawner.generated.h"

class ACStaticMeshBase;

UCLASS()
class BASICCPP_API ACSpawner : public AActor
{
	GENERATED_BODY()
	
public:	
	ACSpawner();

protected:
	virtual void BeginPlay() override;

private:
	UPROPERTY(EditAnywhere, Category = "ClassReference")
	UClass* EveryClassRef;

	UPROPERTY(EditAnywhere, Category = "ClassReference")
	TSubclassOf<ACStaticMeshBase> SpecificClassRef;

	UPROPERTY(EditAnywhere, Category = "ClassReference")
	TSubclassOf<ACStaticMeshBase> ClassesToSpawn[4];

private:
	ACStaticMeshBase* SpawendObjects[4];

};
