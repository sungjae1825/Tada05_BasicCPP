#include "CSphereTrace_Trigger.h"

void ACSphereTrace_Trigger::BeginPlay()
{
	Super::BeginPlay();

	SphereTraceObject;

	OnActorBeginOverlap.AddDynamic(SphereTraceObject, &ACSphereTrace::BeginOverlap);
}