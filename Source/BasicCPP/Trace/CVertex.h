#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CVertex.generated.h"

UCLASS()
class BASICCPP_API ACVertex : public AActor
{
	GENERATED_BODY()
	
public:	
	ACVertex();


protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Component")
		UStaticMeshComponent* MeshComp;
};
