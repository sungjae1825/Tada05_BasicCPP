#pragma once

#include "CoreMinimal.h"
#include "Collision/CBoxBase.h"
#include "CBoxBase_ActorOverlap.generated.h"

UCLASS()
class BASICCPP_API ACBoxBase_ActorOverlap : public ACBoxBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	
	UFUNCTION()
	void ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor);
};
