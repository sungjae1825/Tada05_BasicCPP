#include "CStaticMeshBase.h"

ACStaticMeshBase::ACStaticMeshBase()
{
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>("MeshComp");
	//NewObject<T>();					-> �÷��� ��ư ������ ���
	//CreateDefaultSubobject<T>();		-> �����ڿ��� ���
	RootComponent = MeshComp;  //R ���


}