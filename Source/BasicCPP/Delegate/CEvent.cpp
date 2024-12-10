#include "CEvent.h"
#include "Kismet/KismetMathLibrary.h"


void ACEvent::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACEvent::BeginOverlap);
}

void ACEvent::BeginOverlap(AActor* OverlapActor, AActor* OtherActor)
{
	OnParticleEvent.Broadcast(UKismetMathLibrary::RandomIntegerInRange(0, 2));
}
