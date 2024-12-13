#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CCone.generated.h"

UCLASS()
class BASICCPP_API ACCone : public AActor
{
	GENERATED_BODY()
	
public:	
	ACCone();

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;
};
