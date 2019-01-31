// Fill out your copyright notice in the Description page of Project Settings.

#include "UETestbedEditor.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_MODULE(FUETestbedEditorModule, UETestbedEditor );

DEFINE_LOG_CATEGORY(UETestbedEditor)

#define LOCTEXT_NAMESPACE "UETestbedEditor"

void FUETestbedEditorModule::StartupModule()
{
	UE_LOG(UETestbedEditor, Log, TEXT("UETestbedEditor : StartupModule"));
}

void FUETestbedEditorModule::ShutdownModule()
{
	UE_LOG(UETestbedEditor, Log, TEXT("UETestbedEditor : ShutdownModule"));
}

#undef LOCTEXT_NAMESPACE
