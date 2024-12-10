#include "CBlueprintEvent.h"
#include "Kismet/GameplayStatics.h"
#include "Characters/CPlayer.h"

void ACBlueprintEvent::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &ACBlueprintEvent::BeginOverlap);
	OnActorEndOverlap.AddDynamic(this, &ACBlueprintEvent::EndOverlap);
}

void ACBlueprintEvent::BeginOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ChangeBodyColor();
}

void ACBlueprintEvent::EndOverlap(AActor* OverlappedActor, AActor* OtherActor)
{
	ResetBodyColor();
}

void ACBlueprintEvent::ResetBodyColor_Implementation()
{
	ACPlayer* Player = Cast<ACPlayer>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	if (!Player) return;

	Player->SetBodyColor(FLinearColor(0.450980, 0.403922, 0.360784));
}