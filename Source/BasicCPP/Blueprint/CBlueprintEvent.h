#pragma once

#include "CoreMinimal.h"
#include "Collision/CBoxBase.h"
#include "CBlueprintEvent.generated.h"

UCLASS()
class BASICCPP_API ACBlueprintEvent : public ACBoxBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

protected:
	UFUNCTION(BlueprintImplementableEvent)
	void ChangeBodyColor();

	UFUNCTION(BlueprintNativeEvent)
	void ResetBodyColor();
private:
	UFUNCTION()
		void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);

	UFUNCTION()
		void EndOverlap(AActor* OverlappedActor, AActor* OtherActor);

};
