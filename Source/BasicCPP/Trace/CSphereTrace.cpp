#include "CSphereTrace.h"
#include "Kismet/KismetSystemLibrary.h"
#include "Particles/ParticleSystemComponent.h"

ACSphereTrace::ACSphereTrace()
{
	RootComp = CreateDefaultSubobject<USceneComponent>("RootComp");
	RootComponent = RootComp;

	ParticleComp = CreateDefaultSubobject<UParticleSystemComponent>("ParticleComp");
	ParticleComp->SetupAttachment(RootComp);

	ConstructorHelpers::FObjectFinder<UParticleSystem> ParticleAsset(TEXT("/Game/Explosions/Particles/P_ImpactExplosion6"));
	if (ParticleAsset.Succeeded())
	{
		ParticleComp->SetTemplate(ParticleAsset.Object);
	}

	ParticleComp->bAutoActivate = false;

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
		ParticleComp->ResetParticles();
		ParticleComp->SetActive(true);

		for (const auto& Hit : Hits)
		{
			UPrimitiveComponent* OtherComp = Hit.GetComponent();
			if (OtherComp->IsSimulatingPhysics())
			{
				OtherComp->AddRadialImpulse(Start, 1000.f, 15e4 / OtherComp->GetMass(), ERadialImpulseFalloff::RIF_Constant);
			}
		}
	}
}
