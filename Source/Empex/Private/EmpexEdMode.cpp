// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "EmpexEdMode.h"
#include "EmpexEdModeToolkit.h"
#include "Toolkits/ToolkitManager.h"
#include "SEmpexEditModeTools.h"
#include "EmpexSettings.h"
#include "EditorModeManager.h"
#include "Empex.h"

const FEditorModeID FEmpexEdMode::EM_EmpexEdModeId = TEXT("EM_EmpexEdMode");

#define LOCTEXT_NAMESPACE "EmpexEdMode"

FEmpexEdMode::FEmpexEdMode()
{
	Settings = NewObject<UEmpexSettings>(GetTransientPackage(), *LOCTEXT("SettingsName", "EmpexEdMode Settings").ToString());
	Settings->AddToRoot();
}

FEmpexEdMode::~FEmpexEdMode()
{
	Settings->RemoveFromRoot();
}

void FEmpexEdMode::SetObjects(const TArray<TWeakObjectPtr<>>& InSelectedObjects, const TArray<FGuid>& InObjectBindings)
{
	check(InSelectedObjects.Num() == InObjectBindings.Num());

	SetObjects_Internal(); 
}

void FEmpexEdMode::SetObjects_Internal()
{
	TArray<TWeakObjectPtr<>> SelectedObjects;
	SelectedObjects.Insert(Settings, 0);

	StaticCastSharedPtr<SEmpexEditModeTools>(Toolkit->GetInlineContent())->SetDetailsObjects(SelectedObjects);
}

void FEmpexEdMode::Enter()
{
	// Call parent implementation
	FEdMode::Enter();

	if (!Toolkit.IsValid() && UsesToolkits())
	{
		Toolkit = MakeShareable(new FEmpexEdModeToolkit);
		Toolkit->Init(Owner->GetToolkitHost());
	}

	SetObjects_Internal();
}

void FEmpexEdMode::Exit()
{
	if (Toolkit.IsValid())
	{
		FToolkitManager::Get().CloseToolkit(Toolkit.ToSharedRef());
		Toolkit.Reset();
	}

	// Call base Exit method to ensure proper cleanup
	FEdMode::Exit();
}

bool FEmpexEdMode::UsesToolkits() const
{
	return true;
}

void FEmpexEdMode::RefreshObjects()
{
	SetObjects_Internal();
}

#undef LOCTEXT_NAMESPACE
