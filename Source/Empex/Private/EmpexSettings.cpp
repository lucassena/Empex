// Fill out your copyright notice in the Description page of Project Settings.

#include "EmpexSettings.h"

UEmpexSettings::UEmpexSettings(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer),
	FloatFoo(128.0f),
	bBooleanBar(true),
	EnumDataExample(EEmpexEnumDataExample::Foo)
{
	const float FloatFooClampMin = 0.01f, FloatFooClampMax = 250000.0f;

	FloatFooMin = 1.f;
	FloatFooMax = 256.f;
	FloatFoo = (float)FMath::Clamp(FloatFoo, FloatFooClampMin, FloatFooClampMax);
}

UEmpexSettings::~UEmpexSettings()
{
}

void UEmpexSettings::SetFloatFoo(float InRadius)
{
	FloatFoo = (float)FMath::Clamp(InRadius, FloatFooMin, FloatFooMax);
}

void UEmpexSettings::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.Property && PropertyChangedEvent.Property->GetFName() == GET_MEMBER_NAME_CHECKED(UEmpexSettings, FloatFoo))
	{
		FloatFoo = (float)FMath::Clamp(FloatFoo, FloatFooMin, FloatFooMax);
	}
}
