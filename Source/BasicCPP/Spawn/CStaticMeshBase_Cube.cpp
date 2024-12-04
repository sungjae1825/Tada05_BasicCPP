#include "CStaticMeshBase_Cube.h"
#include "Materials/MaterialInstanceConstant.h"
ACStaticMeshBase_Cube::ACStaticMeshBase_Cube()
{
	//Get Mesh Asset
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StaticMeshes/SM_Cube"));
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
