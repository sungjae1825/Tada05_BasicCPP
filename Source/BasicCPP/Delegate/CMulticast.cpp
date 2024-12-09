#include "CMulticast.h"
#include "Kismet/KismetMathLibrary.h"


void ACMulticast::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACMulticast::OnBeginOverlap);
}

void ACMulticast::OnBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	int32 RandomIndex = UKismetMathLibrary::RandomIntegerInRange(0, 2);
	FLinearColor RandomColor = FLinearColor::MakeRandomColor();


	OnMulticastOverlap.Broadcast(RandomIndex, RandomColor);
}
