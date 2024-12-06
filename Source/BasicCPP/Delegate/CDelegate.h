#pragma once

#include "CoreMinimal.h"
#include "Collision/CBoxBase.h"
#include "CDelegate.generated.h"

DECLARE_DELEGATE(FBoxTriggerOveralp);

//2. Type을 변수화
//3. 바인딩(변수에 함수 저장하는 행위)
//4. 콜백(호출)

UCLASS()
class BASICCPP_API ACDelegate : public ACBoxBase
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;

private:
	UFUNCTION()
	void BeginOverlap(AActor* OverlappedActor, AActor* OtherActor);
	UFUNCTION()
	void EndOverlap(AActor* OverlappedActor, AActor* OtherActor);

public:
	FBoxTriggerOveralp OnBoxTriggerBeginOveralp;
	FBoxTriggerOveralp OnBoxTriggerEndOveralp;



};
