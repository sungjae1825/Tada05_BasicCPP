#include "CStaticMeshBase.h"

ACStaticMeshBase::ACStaticMeshBase()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	//NewObject<T>();					-> 플레이 버튼 누르면 사용
	//CreateDefaultSubobject<T>();		-> 생성자에서 사용
	RootComponent = MeshComp;  //R 밸류


}