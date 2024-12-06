#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CLogTest.generated.h"

UCLASS()
class BASICCPP_API ACLogTest : public AActor
{
	GENERATED_BODY()
	
public:	
	ACLogTest();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

private:
	float RunningTime;

};
