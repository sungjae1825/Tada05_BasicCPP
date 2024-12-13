#pragma once

#include "CoreMinimal.h"
#include "Collision/CBoxBase.h"
#include "CEvent.generated.h"

UCLASS()
class BASICCPP_API ACEvent : public ACBoxBase
{
	GENERATED_BODY()

public:
	DECLARE_EVENT_OneParam(ACEvent, FParticleEvent, int32);

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	FParticleEvent OnParticleEvent;
	
};
