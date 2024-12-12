#include "CSphereTrace_Trigger.h"
#include "Kismet/GameplayStatics.h"
#include "CSphereTrace.h"

void ACSphereTrace_Trigger::BeginPlay()
{
	Super::BeginPlay();

	TArray<AActor*> Actors;
	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ACSphereTrace::StaticClass(), Actors);

	if (Actors.Num() < 1) return;

	ACSphereTrace* SphereTraceObject = Cast<ACSphereTrace>(Actors[0]);
	if (!SphereTraceObject) return;

	OnActorBeginOverlap.AddDynamic(SphereTraceObject, &ACSphereTrace::BeginOverlap);
}