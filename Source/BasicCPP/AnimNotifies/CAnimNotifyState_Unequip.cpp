#include "CAnimNotifyState_Unequip.h"
#include "Interfaces/CWeaponInterface.h"
#include "Weapons/CAR4.h"

FString UCAnimNotifyState_Unequip::GetNotifyName_Implementation() const
{
	return "Unequip";
}

void UCAnimNotifyState_Unequip::NotifyBegin(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation, float TotalDuration)
{
	Super::NotifyBegin(MeshComp, Animation, TotalDuration);
	
	ICWeaponInterface* OwnerInterface = Cast<ICWeaponInterface>(MeshComp->GetOwner());
	if (!OwnerInterface) return;

	ACAR4* Weapon = OwnerInterface->GetWeapon();
	if (!Weapon) return;
	
	Weapon->Begin_Unequip();
}

void UCAnimNotifyState_Unequip::NotifyEnd(USkeletalMeshComponent* MeshComp, UAnimSequenceBase* Animation)
{
	Super::NotifyEnd(MeshComp, Animation);

	ICWeaponInterface* OwnerInterface = Cast<ICWeaponInterface>(MeshComp->GetOwner());
	if (!OwnerInterface) return;

	ACAR4* Weapon = OwnerInterface->GetWeapon();
	if (!Weapon) return;

	Weapon->End_Unequip();
}
