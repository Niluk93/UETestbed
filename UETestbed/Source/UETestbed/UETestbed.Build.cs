// Fill out your copyright notice in the Description page of Project Settings.

using UnrealBuildTool;

public class UETestbed : ModuleRules
{
	public UETestbed(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicIncludePaths.AddRange(new string[] { "UETestbed/Public" });

        PrivateIncludePaths.AddRange(new string[] { "UETestbed/Private" });

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore" });

		PrivateDependencyModuleNames.AddRange(new string[] {  });
		
        PublicDependencyModuleNames.AddRange(new string[] { "Interface", "Debug", "UETestbedBase", "Gameplay", "AI" });
		// Uncomment if you are using Slate UI
		// PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });
		
		// Uncomment if you are using online features
		// PrivateDependencyModuleNames.Add("OnlineSubsystem");

		// To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
	}
}
