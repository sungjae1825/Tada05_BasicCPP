#include "CStaticMeshBase_Cylinder.h"
#include "Materials/MaterialInstanceConstant.h"

ACStaticMeshBase_Cylinder::ACStaticMeshBase_Cylinder()
{
	//Get Mesh Asset
	ConstructorHelpers::FObjectFinder<UStaticMesh> MeshAsset(TEXT("/Game/StaticMeshes/SM_Cylinder"));
	if (MeshAsset.Succeeded())
	{
		MeshComp->SetStaticMesh(MeshAsset.Object);
	}

	//Get Material Asset
	ConstructorHelpers::FObjectFinder<UMaterialInstanceConstant> MaterialAsset(TEXT("/Game/Materials/M_StaticMesh_Inst"));
	if (MaterialAsset.Succeeded())
	{
		MeshComp->SetMaterial(0, MaterialAsset.Object);
	}
}
