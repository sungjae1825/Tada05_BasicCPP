#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CAR4.generated.h"

class USkeletalMeshComponent;
class ACharacter;
class UAnimMontage;
class ACBullet;
class UParticleSystem;
class USoundCue;

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
	FORCEINLINE USkeletalMeshComponent* GetMeshComp() { return MeshComp; }

	void Begin_Aim();
	void End_Aim();

	void Equip();
	void Begin_Equip();
	void End_Equip();

	void Unequip();
	void Begin_Unequip();
	void End_Unequip();

	void Begin_Fire();
	void End_Fire();

	//Todo. 나중에 설명하겠음
	UFUNCTION()
		void Firing();

private:
	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HolsterSocket;

	UPROPERTY(EditDefaultsOnly, Category = "Socket")
		FName HandSocket;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		UAnimMontage* EquipMontage;

	UPROPERTY(EditDefaultsOnly, Category = "Montages")
		UAnimMontage* UnequipMontage;

	UPROPERTY(EditDefaultsOnly, Category = "CameraShake")
		TSubclassOf<UCameraShake> FireCameraShakeClass;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		TSubclassOf<ACBullet> BulletClass;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		UParticleSystem* MuzzleVFX;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		UParticleSystem* EjectVFX;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		UParticleSystem* ImpactVFX;

	UPROPERTY(EditDefaultsOnly, Category = "Effect")
		USoundCue* FireSound;

private:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		USkeletalMeshComponent* MeshComp;

private:
	ACharacter* OwnerCharacter;

	bool bEquipped;
	bool bPlayingMontage;
	bool bAiming;
	bool bFiring;
};
