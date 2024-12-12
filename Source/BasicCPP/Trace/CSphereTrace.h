#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSphereTrace.generated.h"

class UParticleSystemComponent;

UCLASS()
class BASICCPP_API ACSphereTrace : public AActor
{
	GENERATED_BODY()

public:
	ACSphereTrace();

public:
	UFUNCTION()
		void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		USceneComponent* RootComp;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		UParticleSystemComponent* ParticleComp;

};
