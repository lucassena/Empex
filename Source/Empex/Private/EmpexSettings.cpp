// Fill out your copyright notice in the Description page of Project Settings.

#include "EmpexSettings.h"

UEmpexSettings::UEmpexSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	Factor(200.0f),
	bBooleanBar(false),
	EnumDataExample(EEmpexEnumDataExample::Foo)
{
	const float FactorClampMin = 1.0f, FactorClampMax = 4096.0f;

	FactorMin = 1.f;
	FactorMax = 4096.f;
	Factor = (float)FMath::Clamp(Factor, FactorClampMin, FactorClampMax);
}

UEmpexSettings::~UEmpexSettings()
{
}

void UEmpexSettings::SetFactor(float InRadius)
{
	Factor = (float)FMath::Clamp(InRadius, FactorMin, FactorMax);
}

void UEmpexSettings::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UEmpexSettings, Factor))
	{
		Factor = (float)FMath::Clamp(Factor, FactorMin, FactorMax);
	}
}
