// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "EmpexSettings.generated.h"

/** Mesh paint color view modes (somewhat maps to EVertexColorViewMode engine enum.) */
UENUM()
enum class EEmpexEnumDataExample : uint8
{
	Foo		UMETA(DisplayName = "Foo"),
	Bar		UMETA(DisplayName = "Bar"),
	Foobar	UMETA(DisplayName = "Foobar"),
};

UCLASS()
class UEmpexSettings : public UObject
{
	GENERATED_UCLASS_BODY()


public:
	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	~UEmpexSettings();

	float GetFloatFoo() const { return FloatFoo; }
	void SetFloatFoo(float InRadius);
protected:
	/** Example float property */
	UPROPERTY(EditAnywhere, Category = CategoryOne, meta = (DisplayName = "Float Foo"))
	float FloatFoo;
public:
	/** Min and Max FloatFoo range retrieved from config */
	float FloatFooMin;
	float FloatFooMax;

	/** Example boolean property */
	UPROPERTY(EditAnywhere, Category = CategoryOne, meta = (DisplayName = "Boolean Bar"))
	bool bBooleanBar;

	/** Example enum property */
	UPROPERTY(EditAnywhere, Category = AnotherCategory)
	EEmpexEnumDataExample EnumDataExample;
};
