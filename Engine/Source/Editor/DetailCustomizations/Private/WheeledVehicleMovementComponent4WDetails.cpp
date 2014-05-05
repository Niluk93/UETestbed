﻿// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "DetailCustomizationsPrivatePCH.h"
#include "WheeledVehicleMovementComponent4WDetails.h"
#include "ScopedTransaction.h"
#include "ObjectEditorUtils.h"
#include "Vehicles/WheeledVehicleMovementComponent4W.h"
#include "IDocumentation.h"
#include "SCurveEditor.h"

#define LOCTEXT_NAMESPACE "WheeledVehicleMovementComponent4WDetails"

//////////////////////////////////////////////////////////////
// This class customizes various settings in WheeledVehicleMovementComponent4W
//////////////////////////////////////////////////////////////

TSharedRef<IDetailCustomization> FWheeledVehicleMovementComponent4WDetails::MakeInstance()
{
	return MakeShareable(new FWheeledVehicleMovementComponent4WDetails);
}

void FWheeledVehicleMovementComponent4WDetails::CustomizeDetails(IDetailLayoutBuilder& DetailBuilder)
{
	DetailBuilder.GetObjectsBeingCustomized(SelectedObjects);

	//we only do fancy customization if we have one vehicle component selected
	if (SelectedObjects.Num() != 1)
	{
		return;
	}
	else if (UWheeledVehicleMovementComponent4W * VehicleComponent = Cast<UWheeledVehicleMovementComponent4W>(SelectedObjects[0].Get()))
	{
		SteeringCurveEditor = FSteeringCurveEditor(VehicleComponent);
	}
	else
	{
		return;
	}

	// See which categories are hidden
	TArray<FString> HideCategories;
	DetailBuilder.GetDetailsView().GetBaseClass()->GetHideCategories(HideCategories);
	
	IDetailCategoryBuilder& SteeringCategory = DetailBuilder.EditCategory("SteeringSetup");
	TSharedRef<IPropertyHandle> SteeringCurveHandle = DetailBuilder.GetProperty("SteeringCurve");
	SteeringCategory.AddProperty(SteeringCurveHandle).CustomWidget()
	.NameContent()
	[
		SteeringCurveHandle->CreatePropertyNameWidget()
	]
	.ValueContent()
	.MinDesiredWidth(125.f * 3.f)
	[
		SAssignNew(SteeringCurveWidget, SCurveEditor)
		.ViewMinInput(0.f)
		.ViewMaxInput(150.f)
		.ViewMinOutput(0.f)
		.ViewMaxOutput(1.f)
		.TimelineLength(150)
		.HideUI(false)
		.ZoomToFit(false)
		.DesiredSize(FVector2D(512, 128))
	];

	SteeringCurveWidget->SetCurveOwner(&SteeringCurveEditor);
}

TArray<FRichCurveEditInfoConst> FWheeledVehicleMovementComponent4WDetails::FSteeringCurveEditor::GetCurves() const
{
	TArray<FRichCurveEditInfoConst> Curves;
	Curves.Add(&VehicleComponent->SteeringCurve.EditorCurveData);

	return Curves;
}

TArray<FRichCurveEditInfo> FWheeledVehicleMovementComponent4WDetails::FSteeringCurveEditor::GetCurves()
{
	TArray<FRichCurveEditInfo> Curves;
	Curves.Add(&VehicleComponent->SteeringCurve.EditorCurveData);
	
	return Curves;
}

UObject * FWheeledVehicleMovementComponent4WDetails::FSteeringCurveEditor::GetOwner()
{
	return Owner;
}

void FWheeledVehicleMovementComponent4WDetails::FSteeringCurveEditor::ModifyOwner()
{
	if (Owner)
	{
		Owner->Modify();
	}
}

void FWheeledVehicleMovementComponent4WDetails::FSteeringCurveEditor::MakeTransactional()
{
	if (Owner)
	{
		Owner->SetFlags(Owner->GetFlags() | RF_Transactional);
	}
}

FWheeledVehicleMovementComponent4WDetails::FSteeringCurveEditor::FSteeringCurveEditor(UWheeledVehicleMovementComponent4W * InVehicle)
{
	VehicleComponent = InVehicle;
	Owner = VehicleComponent;
}

#undef LOCTEXT_NAMESPACE

