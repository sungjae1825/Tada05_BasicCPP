#include "CDelegate.h"
#include "Utilities/CLog.h"

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

	if (OnBoxTriggerOveralpOneParam.IsBound())
	{
		FLinearColor RandomColor = FLinearColor::MakeRandomColor();
		RandomColor.A = 1.f;

		FString String = OnBoxTriggerOveralpOneParam.Execute(RandomColor);

		CLog::Print(String, -1, 10.f, RandomColor.ToFColor(true));
	}
}

void ACDelegate::EndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	if (OnBoxTriggerEndOveralp.IsBound())
	{
		OnBoxTriggerEndOveralp.Execute();
	}
}
