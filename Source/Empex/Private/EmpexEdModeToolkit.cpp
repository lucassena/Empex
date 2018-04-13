// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "EmpexEdModeToolkit.h"
#include "EmpexEdMode.h"
#include "Engine/Selection.h"
#include "Widgets/Input/SButton.h"
#include "Widgets/Text/STextBlock.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "PropertyHandle.h"
#include "EditorModeManager.h"
#include "SScrollBox.h"

#define LOCTEXT_NAMESPACE "FEmpexEdModeToolkit"

FEmpexEdModeToolkit::FEmpexEdModeToolkit()
{
	SAssignNew(ModeTools, SEmpexEditModeTools);
}

void FEmpexEdModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost)
{
	FModeToolkit::Init(InitToolkitHost);
}

FName FEmpexEdModeToolkit::GetToolkitFName() const
{
	return FName("EmpexEdMode");
}

FText FEmpexEdModeToolkit::GetBaseToolkitName() const
{
	return NSLOCTEXT("EmpexEdModeToolkit", "DisplayName", "EmpexEdMode Tool");
}

class FEdMode* FEmpexEdModeToolkit::GetEditorMode() const
{
	return GLevelEditorModeTools().GetActiveMode(FEmpexEdMode::EM_EmpexEdModeId);
}

TSharedPtr<SWidget> FEmpexEdModeToolkit::GetInlineContent() const
{
	return ModeTools;
}

#undef LOCTEXT_NAMESPACE
