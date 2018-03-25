// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "DeclarativeSyntaxSupport.h"

class IDetailsView;

class SEmpexEditModeTools : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SEmpexEditModeTools) {}
	SLATE_END_ARGS()

	void Construct(const FArguments& InArgs);

	/** Set the objects to be displayed in the details panel */
	void SetDetailsObjects(const TArray<TWeakObjectPtr<>>& InObjects);

private:
	/** The details view we do most of our work within */
	TSharedPtr<IDetailsView> DetailsView;

	/** Display set up for property */
	bool ShouldShowPropertyOnDetailCustomization(const struct FPropertyAndParent& InPropertyAndParent) const;
	bool IsReadOnlyPropertyOnDetailCustomization(const struct FPropertyAndParent& InPropertyAndParent) const;
};
