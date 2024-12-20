#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CBullet.generated.h"

class UProjectileMovementComponent;


UCLASS()
class BASICCPP_API ACBullet : public AActor
{
	GENERATED_BODY()
	
public:	
	ACBullet();

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UProjectileMovementComponent* MoveComp;
};
