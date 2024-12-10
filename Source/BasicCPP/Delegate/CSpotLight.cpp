#include "CSpotLight.h"
#include "Components/SpotLightComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CMulticast.h"

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

		SpotLightComps[i]->SetRelativeLocation(FVector(0, i * 150, 0));
		SpotLightComps[i]->SetRelativeRotation(FRotator(-90, 0, 0));
		SpotLightComps[i]->SetIntensity(1e+5f);
		SpotLightComps[i]->SetOuterConeAngle(25.f);
	}
}

void ACSpotLight::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACMulticast::StaticClass(), Actors);

	if (Actors.Num() > 0)
	{
		ACMulticast* Trigger = Cast<ACMulticast>(Actors[0]);
		
		if (Trigger)
		{
			Trigger->OnMulticastOverlap.AddUFunction(this, "OnLight");
		}
	}
}

void ACSpotLight::OnLight(int32 InIndex, FLinearColor InColor)
{
	for (int32 i = 0; i < 3; i++)
	{
		SpotLightComps[i]->SetLightColor(FLinearColor::White);
	}

	SpotLightComps[InIndex]->SetLightColor(InColor);
}
