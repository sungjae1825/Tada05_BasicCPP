#pragma once

#include "CoreMinimal.h"
#include "Collision/CBoxBase.h"
#include "CMulticast.generated.h"

DECLARE_MULTICAST_DELEGATE_TwoParams(FMulticastOverlap, int32, FLinearColor);


UCLASS()
class BASICCPP_API ACMulticast : public ACBoxBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	FMulticastOverlap OnMulticastOverlap;
};
