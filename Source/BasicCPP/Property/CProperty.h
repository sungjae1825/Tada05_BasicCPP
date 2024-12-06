#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CProperty.generated.h"

UCLASS()
class BASICCPP_API ACProperty : public AActor
{
	GENERATED_BODY()
	
public:	
	ACProperty();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(VisibleDefaultsOnly, Category = "MyVariable")
	int32 NumberA;

	UPROPERTY(VisibleInstanceOnly, Category = "MyVariable")
	int32 NumberB;

	UPROPERTY(VisibleAnywhere, Category = "MyVariable")
	int32 NumberC;


	UPROPERTY(EditDefaultsOnly, Category = "MyVariable")
	float RealA;

	UPROPERTY(EditInstanceOnly, Category = "MyVariable")
	float RealB;

	UPROPERTY(EditAnywhere, Category = "MyVariable")
	float RealC;

protected:
	//Type your name ^_^
	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "MyVariable")
	FString MyName;
};
