#include "CDelegate.h"

void ACDelegate::BeginPlay()
{
	Super::BeginPlay();


	OnActorBeginOverlap.AddDynamic(this, &ACDelegate::BeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ACDelegate::EndOverlap);

	
}

void ACDelegate::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnBoxTriggerBeginOveralp.IsBound())
	{
		OnBoxTriggerBeginOveralp.Execute();
	}
}

void ACDelegate::EndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnBoxTriggerEndOveralp.IsBound())
	{
		OnBoxTriggerEndOveralp.Execute();
	}
}
