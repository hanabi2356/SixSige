// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;


public class R6STarget : TargetRules
{
	public R6STarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V5;
		IncludeOrderVersion = EngineIncludeOrderVersion.Unreal5_4;
        bOverrideBuildEnvironment = true;
        bUndefinedIdentifierErrors = false;
        ExtraModuleNames.Add("R6S");
	}
}
