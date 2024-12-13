#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CCube.generated.h"

UCLASS()
class BASICCPP_API ACCube : public AActor
{
	GENERATED_BODY()
	
public:	
	ACCube();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void Falling(int32 InIndex, FLinearColor InColor);

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USceneComponent* RootComp;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComps[3];

private:
	FVector OriginLocations[3];
};
