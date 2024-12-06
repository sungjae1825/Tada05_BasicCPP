#pragma once

#include "CoreMinimal.h"
#include "Collision/CBoxBase.h"
#include "CDelegate.generated.h"

DECLARE_DELEGATE(FBoxTriggerOveralp);

//2. Type�� ����ȭ
//3. ���ε�(������ �Լ� �����ϴ� ����)
//4. �ݹ�(ȣ��)

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
