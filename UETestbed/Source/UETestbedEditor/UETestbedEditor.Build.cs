// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class UETestbedEditor : ModuleRules
{
	public UETestbedEditor(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] { "UETestbedEditor/Public" });

        PrivateIncludePaths.AddRange(new string[] { "UETestbedEditor/Private" });
	
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });
		
		PrivateDependencyModuleNames.AddRange(new string[] { "UnrealEd", "Slate", "SlateCore" });
		
        PublicDependencyModuleNames.AddRange(new string[] { "Interface", "Debug", "UETestbedBase", "Gameplay", "AI", "UETestbed", "UI" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}
