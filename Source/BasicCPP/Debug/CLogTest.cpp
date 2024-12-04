#include "CLogTest.h"
#include "Utilities/CLog.h"

ACLogTest::ACLogTest()
{
	PrimaryActorTick.bCanEverTick = true;

}

void ACLogTest::BeginPlay()
{
	Super::BeginPlay();

	CLog::Print(777);
	CLog::Print(888, 1);
	CLog::Print(999, 2, 20.f);
	CLog::Print(666, 2, 20.f, FColor::Green);
	CLog::Print("Hell World");
	CLog::Print(GetActorLocation());
	CLog::Print(GetActorRotation());

	CLog::Log(1000);
	CLog::Log(PI);
	CLog::Log("Hell World");
	CLog::Log(FVector(100, 100, 100));
	CLog::Log(FRotator(90, 90, 90));
	CLog::Log(__FILE__);
	PrintLine();
}

void ACLogTest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	RunningTime += DeltaTime;
	CLog::Print(RunningTime, 7);

	CLog::Print(GetWorld()->TimeSeconds, 8, 10.f, FColor::Red);
}
