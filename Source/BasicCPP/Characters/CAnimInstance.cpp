#include "CAnimInstance.h"
#include "Interfaces/CWeaponInterface.h"
#include "Weapons/CAR4.h"

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (!OwnerPawn) return;

	Speed = OwnerPawn->GetVelocity().Size2D();
	Direction = CalculateDirection(OwnerPawn->GetVelocity(), OwnerPawn->GetControlRotation());
	Pitch = OwnerPawn->GetBaseAimRotation().Pitch;

	ICWeaponInterface* OwnerInterface = Cast<ICWeaponInterface>(OwnerPawn);
	if (!OwnerInterface) return;

	bEquipped = OwnerInterface->GetWeapon()->IsEquipped();
	bAiming = OwnerInterface->GetWeapon()->IsAiming();
}

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwnerPawn = TryGetPawnOwner();
}