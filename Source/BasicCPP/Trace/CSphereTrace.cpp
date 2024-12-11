#include "CSphereTrace.h"
#include "Kismet/KismetSystemLibrary.h"

ACSphereTrace::ACSphereTrace()
{
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = RootComp;
}

void ACSphereTrace::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	FVector Start = GetActorLocation();
	FVector End = Start + FVector(10);

	TArray<TEnumAsByte<EObjectTypeQuery>> ObjectTypes;
	ObjectTypes.Add(ObjectTypeQuery4);

	TArray<AActor*> Ignores;

	TArray<FHitResult> Hits;

	if (UKismetSystemLibrary::SphereTraceMultiForObjects
	(
		GetWorld(),
		Start,
		End,
		1000.f,
		ObjectTypes,
		false,
		Ignores,
		EDrawDebugTrace::ForDuration,
		Hits,
		true
	))
	{
		for (const auto& Hit : Hits)
		{
			UPrimitiveComponent* OtherComp = Hit.GetComponent();
			if (OtherComp->IsSimulatingPhysics())
			{

				OtherComp->AddRadiusImpulse(Start, 1000.f, 15e6 / OtherComp->GetMass(), ERadialImpulseFalloff::RIF_Constant);
			}

			
		}
	}
}
