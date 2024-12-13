#include "CEvent.h"
#include "Kismet/KismetMathLibrary.h"

void ACEvent::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACEvent::BeginOverlap);
}

void ACEvent::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	OnParticleEvent.Broadcast(UKismetMathLibrary::RandomIntegerInRange(0, 2));
}
