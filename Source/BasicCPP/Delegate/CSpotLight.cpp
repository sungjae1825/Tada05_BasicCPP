#include "CSpotLight.h"
#include "Components/SpotLightComponent.h"

ACSpotLight::ACSpotLight()
{
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = RootComp;


	for (int32 i = 0; i < 3; i++)
	{
		FString CompName;
		CompName.Append("SpotLightComp");
		CompName.Append(FString::FromInt(i + 1));

		SpotLightComps[i] = CreateDefaultSubobject<USpotLightComponent>(FName(CompName));
		SpotLightComps[i]->SetupAttachment(RootComp);
	}
}

void ACSpotLight::BeginPlay()
{
	Super::BeginPlay();

}

void ACSpotLight::OnLight(int32 InIndex, FLinearColor InColor)
{
}
