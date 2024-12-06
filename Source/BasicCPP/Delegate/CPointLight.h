#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CPointLight.generated.h"

class UPointLightComponent;

UCLASS()
class BASICCPP_API ACPointLight : public AActor
{
	GENERATED_BODY()

public:
	ACPointLight();

protected:
	virtual void BeginPlay() override;

private:
	void OnLights();
	void OffLights();


protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	USceneComponent* RootComp;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UPointLightComponent* LightComp1;

	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
	UPointLightComponent* LightComp2;
};
