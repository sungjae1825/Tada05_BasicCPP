#include "CParticle.h"
#include "Kismet/GameplayStatics.h"
#include "CEvent.h"

ACParticle::ACParticle()
{
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = RootComp;
}

void ACParticle::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACEvent::StaticClass(), Actors);

	if (Actors.Num() < 1) return;
	
	ACEvent* Trigger = Cast<ACEvent>(Actors[0]);
	if (Trigger)
	{
		Trigger->OnParticleEvent.AddUObject(this, &ACParticle::SpawnRandomParticle);
	}
}

void ACParticle::SpawnRandomParticle(int32 InIndex)
{
	FTransform TM;
	TM.SetLocation(GetActorLocation());

	if (!Particles[InIndex]) return;

	UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), Particles[InIndex], TM);
}
