#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CLineTrace.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FLineTraceResult, AActor*, InActor, FLinearColor, InColor);

class UTextRenderComponent;

UCLASS()
class BASICCPP_API ACLineTrace : public AActor
{
	GENERATED_BODY()

public:
	ACLineTrace();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(BlueprintAssignable)
		FLineTraceResult OnLineTraceResult;

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		UTextRenderComponent* TextRenderComp;

	UPROPERTY(EditDefaultsOnly, Category = "Vertex")
		TSubclassOf<AActor> VertexClass;

private:
	UFUNCTION()
		void LineTraced(AActor* InActor, FLinearColor InColor);

private:
	AActor* Vertices[2];
};
