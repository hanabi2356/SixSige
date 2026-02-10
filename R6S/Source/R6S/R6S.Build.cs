// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class R6S : ModuleRules
{
	public R6S(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
        bEnableUndefinedIdentifierWarnings = false;
        PublicDependencyModuleNames.AddRange(new string[] { 
			"Core", 
			"CoreUObject", 
			"Engine", 
			"InputCore", 
			"EnhancedInput"
		});
	}
}
