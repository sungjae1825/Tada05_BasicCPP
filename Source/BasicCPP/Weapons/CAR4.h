#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CAR4.generated.h"

class USkeletalMeshComponent;
class ACharacter;
class UAnimMontage;

UCLASS()
class BASICCPP_API ACAR4 : public AActor
{
	GENERATED_BODY()

public:
	ACAR4();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

public:
	FORCEINLINE bool IsEquipped() { return bEquipped; }
	FORCEINLINE bool IsPlayingMontage() { return bPlayingMontage; }
	FORCEINLINE bool IsAiming() { return bAiming; }

	void Begin_Aim();
	void End_Aim();


	void Equip();
	void Begin_Equip();
	void End_Equip();

	void Unequip();
	void Begin_Unequip();
	void End_Unequip();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HolsterSocket;

	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HandSocket;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		UAnimMontage* EquipMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		UAnimMontage* UnequipMontage;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		USkeletalMeshComponent* MeshComp;

private:
	ACharacter* OwnerCharacter;

	bool bEquipped;
	bool bPlayingMontage;
	bool bAiming;
};
