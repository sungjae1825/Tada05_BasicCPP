#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CParticle.generated.h"

UCLASS()
class BASICCPP_API ACParticle : public AActor
{
	GENERATED_BODY()
	
public:	
	ACParticle();

protected:
	virtual void BeginPlay() override;

private:
	void SpawnRandomParticle(int32 InIndex);

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USceneComponent* RootComp;

	UPROPERTY(EditAnywhere, Category = "Particle")
	UParticleSystem* Particles[3];
};
