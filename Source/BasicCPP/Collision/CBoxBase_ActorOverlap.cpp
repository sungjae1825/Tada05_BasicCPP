#include "CBoxBase_ActorOverlap.h"
#include "Utilities/CLog.h"

void ACBoxBase_ActorOverlap::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACBoxBase_ActorOverlap::ActorBeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ACBoxBase_ActorOverlap::ActorEndOverlap);
}

void ACBoxBase_ActorOverlap::ActorBeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	CLog::Log(FString(__FUNCTION__) + " called " +  GetNameSafe(OtherActor));
}

void ACBoxBase_ActorOverlap::ActorEndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	CLog::Log(FString(__FUNCTION__) + " called " + GetNameSafe(OtherActor));
}
