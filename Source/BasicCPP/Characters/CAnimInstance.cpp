#include "CAnimInstance.h"

void UCAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	if (OwnerPawn == nullptr)
	{
		return;
	}

	Speed = OwnerPawn->GetVelocity().Size2D();
}

void UCAnimInstance::NativeBeginPlay()
{
	Super::NativeBeginPlay();

	OwnerPawn = TryGetPawnOwner();
}