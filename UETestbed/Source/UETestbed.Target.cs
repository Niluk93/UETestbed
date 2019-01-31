// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;
using System.Collections.Generic;

public class UETestbedTarget : TargetRules
{
	public UETestbedTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;

		ExtraModuleNames.AddRange( new string[] { "UETestbed" } );

		if(bBuildEditor)
        {
            ExtraModuleNames.AddRange(new string[] { "UETestbedEditor" });
        }
	}
}

/**
 * Follow module rules while adding new modules
 * New modules added should be added to a layer here as reference
 * 
 * Module Rules-
 *		Modules within the same layer should not depend on each other
 *		Modules within each layer should only depend on modules in layers below them
 *		
 * Module Layers-
 * Editor - UETestedEditor
 * Presentation - UI. Possibly Animation and Audio will go here too
 * Primary - UETestbed
 * Secondary- Gameplay, AI
 * Base - UETestbedBase
 * Debug - Debug
 * Interface - Interface
 * Plugins - Any plugins we end up using 
 */