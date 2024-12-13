#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimInstance.h"
#include "CAnimInstance.generated.h"

UCLASS()
class BASICCPP_API UCAnimInstance : public UAnimInstance
{
	GENERATED_BODY()

protected:
	virtual void NativeUpdateAnimation(float DeltaSeconds) override;
	virtual void NativeBeginPlay() override;
	
protected:
	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "OwnerPawn")
	float Speed;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "OwnerPawn")
	bool bEquipped;

private:
	APawn* OwnerPawn;
};
