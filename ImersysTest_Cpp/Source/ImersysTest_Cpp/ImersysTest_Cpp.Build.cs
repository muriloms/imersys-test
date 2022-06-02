// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ImersysTest_Cpp : ModuleRules
{
	public ImersysTest_Cpp(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
