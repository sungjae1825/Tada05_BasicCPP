#include "CBoxBase.h"
#include "Components/BoxComponent.h"
#include "Components/TextRenderComponent.h"

ACBoxBase::ACBoxBase()
{
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = RootComp;

	BoxComp = CreateDefaultSubobject<UBoxComponent>("BoxComp");
	BoxComp->SetupAttachment(RootComp);
	BoxComp->bHiddenInGame = false;
	BoxComp->SetRelativeScale3D(FVector(3));

	TextRenderComp = CreateDefaultSubobject<UTextRenderComponent>("TextRenderComp");
	TextRenderComp->SetupAttachment(RootComp);
	TextRenderComp->SetRelativeLocation(FVector(0, 0, 100));
	TextRenderComp->SetRelativeRotation(FRotator(0, 180, 0));
	TextRenderComp->SetTextRenderColor(FColor::Black);
	TextRenderComp->SetHorizontalAlignment(EHTA_Center);
	TextRenderComp->SetText(GetName());
}

void ACBoxBase::BeginPlay()
{
	Super::BeginPlay();
	
}