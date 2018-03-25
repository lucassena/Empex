// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Styling/SlateStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "IPluginManager.h"

class FEmpexEditorStyle
	: public FSlateStyleSet
{
public:
	FEmpexEditorStyle()
		: FSlateStyleSet("EmpexEditorStyle")
	{
		const FVector2D Icon16x16(16.0f, 16.0f);
		const FVector2D Icon20x20(20.0f, 20.0f);
		const FVector2D Icon24x24(24.0f, 24.0f);
		const FVector2D Icon40x40(40.0f, 40.0f);
		SetContentRoot(IPluginManager::Get().FindPlugin("Empex")->GetBaseDir() / TEXT("Resources"));

		Set("EmpexEdMode", new FSlateImageBrush(RootToContentDir(TEXT("DefaultIcon40.png")), Icon40x40));
		Set("EmpexEdMode.Small", new FSlateImageBrush(RootToContentDir(TEXT("DefaultIcon40.png")), Icon20x20));

		FSlateStyleRegistry::RegisterSlateStyle(*this);
	}

	static FEmpexEditorStyle& Get()
	{
		static FEmpexEditorStyle Inst;
		return Inst;
	}

	~FEmpexEditorStyle()
	{
		FSlateStyleRegistry::UnRegisterSlateStyle(*this);
	}
};
