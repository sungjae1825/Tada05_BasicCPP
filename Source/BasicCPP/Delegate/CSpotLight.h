#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CSpotLight.generated.h"

class USpotLightComponent;

UCLASS()
class BASICCPP_API ACSpotLight : public AActor
{
	GENERATED_BODY()
	
public:	
	ACSpotLight();

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void OnLight(int32 InIndex, FLinearColor InColor);

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USceneComponent* RootComp;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USpotLightComponent* SpotLightComps[3];

};
