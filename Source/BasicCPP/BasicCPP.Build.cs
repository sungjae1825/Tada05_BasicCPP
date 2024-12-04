// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class BasicCPP : ModuleRules
{
	public BasicCPP(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;


		PublicIncludePaths.Add(ModuleDirectory);

	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });




	}
}
