#include "CGameModeBase.h"
#include "Characters/CPlayer.h"

ACGameModeBase::ACGameModeBase()
{
	ConstructorHelpers::FClassFinder<APawn> PlayerClass(TEXT("/Game/Player/BP_CPlayer"));
	if (PlayerClass.Succeeded())
	{
		DefaultPawnClass = PlayerClass.Class;
	}
	
}