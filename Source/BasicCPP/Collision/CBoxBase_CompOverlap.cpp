#include "CBoxBase_CompOverlap.h"
#include "Components/PointLightComponent.h"
#include "Components/BoxComponent.h"

ACBoxBase_CompOverlap::ACBoxBase_CompOverlap()
{
	PointLightComp = CreateDefaultSubobject<UPointLightComponent>("PointLightComp");
	PointLightComp->SetupAttachment(RootComp);
	PointLightComp->SetLightColor(FLinearColor::Green);
}

void ACBoxBase_CompOverlap::BeginPlay()
{
	Super::BeginPlay();

	PointLightComp->SetVisibility(false);

	BoxComp->OnComponentBeginOverlap.AddDynamic(this, &ACBoxBase_CompOverlap::CompBeginOverlap);
	BoxComp->OnComponentEndOverlap.AddDynamic(this, &ACBoxBase_CompOverlap::CompEndOverlap);
}

void ACBoxBase_CompOverlap::CompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	PointLightComp->SetVisibility(true);
}

void ACBoxBase_CompOverlap::CompEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	PointLightComp->SetVisibility(false);
}
