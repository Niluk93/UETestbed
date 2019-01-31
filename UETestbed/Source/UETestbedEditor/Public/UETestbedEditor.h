// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Modules/ModuleInterface.h"
#include "Modules/ModuleManager.h"
#include "UnrealEd.h"

DECLARE_LOG_CATEGORY_EXTERN(UETestbedEditor, All, All)

class FUETestbedEditorModule final : public IModuleInterface
{
public:
	void StartupModule() final;
	void ShutdownModule() final;
};
