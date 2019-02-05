// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UETestbedEditorTarget : TargetRules
{
	public UETestbedEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;

		ExtraModuleNames.AddRange( new string[] { "Interface", "Debug", "UETestbedBase", "Gameplay", "AI", "UETestbed", "UI", "UETestbedEditor" } );
	}
}
