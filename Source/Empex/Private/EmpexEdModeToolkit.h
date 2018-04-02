// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SWidget.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "EditorModes.h"
#include "Toolkits/BaseToolkit.h"
#include "EditorModeManager.h"
#include "SEmpexEditModeTools.h"

class FEmpexEdModeToolkit : public FModeToolkit
{
public:

	FEmpexEdModeToolkit()
	{
		SAssignNew(ModeTools, SEmpexEditModeTools);
	}
	
	/** FModeToolkit interface */
	virtual void Init(const TSharedPtr<IToolkitHost>& InitToolkitHost) override;

	/** IToolkit interface */
	virtual FName GetToolkitFName() const override;
	virtual FText GetBaseToolkitName() const override;
	virtual class FEdMode* GetEditorMode() const override;
	virtual TSharedPtr<class SWidget> GetInlineContent() const override { return ModeTools; }

private:
	TSharedPtr<SWidget> ToolkitWidget;

	TSharedPtr<SEmpexEditModeTools> ModeTools;

};
