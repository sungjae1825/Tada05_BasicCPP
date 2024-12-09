#include "CPointLight.h"
#include "Components/PointLightComponent.h"
#include "Kismet/GameplayStatics.h"
#include "CDelegate.h"

ACPointLight::ACPointLight()
{
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = RootComp;

	LightComp1 = CreateDefaultSubobject<UPointLightComponent>("LightComp1");
	LightComp1->SetupAttachment(RootComp);
	LightComp1->SetIntensity(1e+4f);
	LightComp1->SetAttenuationRadius(200.f);
	LightComp1->SetLightColor(FLinearColor(1.f, 0.5f, 0.f));

	LightComp2 = CreateDefaultSubobject<UPointLightComponent>("LightComp2");
	LightComp2->SetupAttachment(RootComp);
	LightComp2->SetIntensity(1e+4f);
	LightComp2->SetAttenuationRadius(200.f);
	LightComp2->SetLightColor(FLinearColor(1.f, 0.5f, 0.f));
	LightComp2->SetRelativeLocation(FVector(0, 200, 0));

}

void ACPointLight::BeginPlay()
{
	Super::BeginPlay();

	LightComp1->SetVisibility(false);
	LightComp2->SetVisibility(false);

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACDelegate::StaticClass(), Actors);

	if (Actors.Num() < 1)
	{
		return;
	}

	ACDelegate* DelegateObject = Cast<ACDelegate>(Actors[0]);
	if (DelegateObject)
	{
		DelegateObject->OnBoxTriggerBeginOveralp.BindUObject(this, &ACPointLight::OnLights);
		DelegateObject->OnBoxTriggerEndOveralp.BindUObject(this, &ACPointLight::OffLights);
		DelegateObject->OnBoxTriggerOveralpOneParam.BindUFunction(this, "SetLight1Color");
	}
}

void ACPointLight::OnLights()
{
	LightComp2->SetVisibility(true);
}

void ACPointLight::OffLights()
{
	LightComp1->SetVisibility(false);
	LightComp2->SetVisibility(false);
}

FString ACPointLight::SetLight1Color(FLinearColor InColor)
{
	LightComp1->SetVisibility(true);
	LightComp1->SetLightColor(InColor);

	return InColor.ToString();
}
