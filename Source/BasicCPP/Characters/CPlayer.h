#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Interfaces/CWeaponInterface.h"
#include "CPlayer.generated.h"

class USpringArmComponent;
class UCameraComponent;
class ACAR4;

UCLASS()
class BASICCPP_API ACPlayer : public ACharacter, public ICWeaponInterface
{
	GENERATED_BODY()

public:
	ACPlayer();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void OnMoveForward(float Axis);
	void OnMoveRight(float Axis);

	void OnTurn(float Axis);
	void OnLookUp(float Axis);

	void OnSprint();
	void OffSprint();

	void OnRifle();

	void OnAim();
	void OffAim();

protected:
	UFUNCTION(BlueprintImplementableEvent)
		void ZoomIn();

	UFUNCTION(BlueprintImplementableEvent)
		void ZoomOut();

public:
	FORCEINLINE ACAR4* GetWeapon() { return AR4; };

public:
	UFUNCTION(BlueprintCallable)
		void SetBodyColor(FLinearColor InColor);

protected:
	UPROPERTY(VisibleDefaultsOnly, Category = "Components")
		USpringArmComponent* SpringArmComp;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Components")
		UCameraComponent* CameraComp;

private:
	UPROPERTY(EditDefaultsOnly, Category = "Weapons")
		TSubclassOf<ACAR4> AR4Class;

	ACAR4* AR4;

};
