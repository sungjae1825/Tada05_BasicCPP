#include "CProperty.h"

ACProperty::ACProperty()
{
	NumberA = 10;
	NumberB = 20;
	NumberC = 30;

	RealA = 111.1f;
	RealB = 222.2f;
	RealC = 333.3f;

	MyName = "someddk";
}

void ACProperty::BeginPlay()
{
	Super::BeginPlay();

	//UE_LOG
	UE_LOG(LogTemp, Warning, TEXT("[UE_LOG] NumberA = %d, RealA = %f"), NumberA, RealA);

	//GLog->Log
	GLog->Log
	(
		ELogVerbosity::Error,
		FString::Printf(TEXT("[GLog->Log] NumberB = %d, RealB = %f"), NumberB, RealB)
	);

	//ScreenDebugMessage
	FString Message = FString::Printf(TEXT("[DebugMessage] NumberC = %d, RealC = %f"), NumberC, RealC);
	GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Green, Message);

}