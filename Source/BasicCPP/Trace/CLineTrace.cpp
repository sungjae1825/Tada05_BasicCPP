#include "CLineTrace.h"
#include "Components/TextRenderComponent.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "DrawDebugHelpers.h"

ACLineTrace::ACLineTrace()
{
	PrimaryActorTick.bCanEverTick = true;

	TextRenderComp = CreateDefaultSubobject<UTextRenderComponent>("TextRenderComp");
	RootComponent = TextRenderComp;

	TextRenderComp->SetTextRenderColor(FColor::Red);
	TextRenderComp->SetHorizontalAlignment(EHTA_Center);
	TextRenderComp->SetText(GetName());
}

void ACLineTrace::BeginPlay()
{
	Super::BeginPlay();
	
	if (VertexClass)
	{
		TArray<AActor*> Actors;
		UGameplayStatics::GetAllActorsOfClass(GetWorld(), VertexClass, Actors);

		if (Actors.Num() < 1) return;

		for (int32 i = 0; i < 2; i++)
		{
			Vertices[i] = Actors[i];
		}
	}

	OnLineTraceResult.AddDynamic(this, &ACLineTrace::LineTraced);
}

void ACLineTrace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector Start = Vertices[0]->GetActorLocation();
	FVector End = Vertices[1]->GetActorLocation();

	TArray<AActor*> Ignores;
	Ignores.Add(Vertices[0]);
	Ignores.Add(Vertices[1]);

	FHitResult Hit;

	if (UKismetSystemLibrary::LineTraceSingleByProfile
	(
		GetWorld(),
		Start,
		End,
		"Pawn",
		false,
		Ignores,
		EDrawDebugTrace::ForOneFrame,
		Hit,
		true
	))
	{
		OnLineTraceResult.Broadcast(Hit.GetActor(), FLinearColor::Red);
	}
}

void ACLineTrace::LineTraced(AActor* InActor, FLinearColor InColor)
{
	DrawDebugString
	(
		GetWorld(),
		FVector(0, 0, 120),
		InActor->GetName(),
		InActor,
		InColor.ToFColor(true),
		GetWorld()->GetDeltaSeconds(),
		false,
		2.f
	);
}

