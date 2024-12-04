#include "CStaticMeshBase_Sphere.h"
#include "Materials/MaterialInstanceConstant.h"
ACStaticMeshBase_Sphere::ACStaticMeshBase_Sphere()
{
	//Get Mesh Asset
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StaticMeshes/SM_Sphere"));
	// /Game -> ������ ����

	if (MeshAsset.Succeeded())
	{
		//Execute
		MeshAsset.Object;
		MeshComp->SetStaticMesh(MeshAsset.Object);
	}

	//Get Material Asset
	ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> MaterialAsset(TEXT("/Game/Materials/M_StaticMesh_Inst"));
	// ������ ���� ������Ʈ
	if (MaterialAsset.Succeeded())
	{
		MeshComp->SetMaterial(0, MaterialAsset.Object);
	}
	
}
