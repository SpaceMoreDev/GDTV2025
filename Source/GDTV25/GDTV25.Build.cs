// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GDTV25 : ModuleRules
{
	public GDTV25(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "NavigationSystem", "AIModule" });
    }
}
