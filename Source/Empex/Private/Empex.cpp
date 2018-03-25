// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "Empex.h"
#include "EmpexEdMode.h"
#include "EmpexEditorStyle.h"

#define LOCTEXT_NAMESPACE "FEmpexModule"

void FEmpexModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	FEditorModeRegistry::Get().RegisterMode<FEmpexEdMode>(
		FEmpexEdMode::EM_EmpexEdModeId, 
		LOCTEXT("EmpexEdModeName", "Empex - Editor Mode Plugin Example"), 
		FSlateIcon(FEmpexEditorStyle::Get().GetStyleSetName(), "EmpexEdMode", "EmpexEdMode.Small"),
		true);
}

void FEmpexModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
	FEditorModeRegistry::Get().UnregisterMode(FEmpexEdMode::EM_EmpexEdModeId);
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEmpexModule, Empex)
