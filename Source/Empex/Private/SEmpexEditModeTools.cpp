// Fill out your copyright notice in the Description page of Project Settings.

#include "SEmpexEditModeTools.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "PropertyHandle.h"
#include "ModuleManager.h"
#include "EditorModeManager.h"
#include "SScrollBox.h"

#define LOCTEXT_NAMESPACE "EmpexEditModeTools"

void SEmpexEditModeTools::Construct(const FArguments& InArgs)
{
	// initialize settings view
	FDetailsViewArgs DetailsViewArgs;
	{
		DetailsViewArgs.bAllowSearch = true;
		DetailsViewArgs.bHideSelectionTip = true;
		DetailsViewArgs.bLockable = false;
		DetailsViewArgs.bSearchInitialKeyFocus = true;
		DetailsViewArgs.bUpdatesFromSelection = false;
		DetailsViewArgs.bShowOptions = true;
		DetailsViewArgs.bShowModifiedPropertiesOption = true;
		DetailsViewArgs.bShowActorLabel = false;
		DetailsViewArgs.bCustomNameAreaLocation = true;
		DetailsViewArgs.bCustomFilterAreaLocation = true;
		DetailsViewArgs.NameAreaSettings = FDetailsViewArgs::HideNameArea;
		DetailsViewArgs.bAllowMultipleTopLevelObjects = true;
		DetailsViewArgs.bShowScrollBar = false; // Don't need to show this, as we are putting it in a scroll box
	}

	DetailsView = FModuleManager::GetModuleChecked<FPropertyEditorModule>("PropertyEditor").CreateDetailView(DetailsViewArgs);
	DetailsView->SetIsPropertyVisibleDelegate(FIsPropertyVisible::CreateSP(this, &SEmpexEditModeTools::ShouldShowPropertyOnDetailCustomization));
	DetailsView->SetIsPropertyReadOnlyDelegate(FIsPropertyReadOnly::CreateSP(this, &SEmpexEditModeTools::IsReadOnlyPropertyOnDetailCustomization));

	ChildSlot
	[
		SNew(SScrollBox)
		+ SScrollBox::Slot()
		[
			SNew(SVerticalBox)
			+ SVerticalBox::Slot()
			.Padding(15, 12, 0, 12)
			[
				SNew(STextBlock)
				.Text(LOCTEXT("Empex_Tip", "This is a simple text!"))
			]
			+ SVerticalBox::Slot()
			.AutoHeight()
			[
				DetailsView.ToSharedRef()
			]
		]
	];
}

bool SEmpexEditModeTools::ShouldShowPropertyOnDetailCustomization(const FPropertyAndParent & InPropertyAndParent) const
{
	return true;
}

bool SEmpexEditModeTools::IsReadOnlyPropertyOnDetailCustomization(const FPropertyAndParent & InPropertyAndParent) const
{
	return false;
}

void SEmpexEditModeTools::SetDetailsObjects(const TArray<TWeakObjectPtr<>>& InObjects)
{
	DetailsView->SetObjects(InObjects);
}

#undef LOCTEXT_NAMESPACE
