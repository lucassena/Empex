// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Object.h"

#include "EmpexSettings.generated.h"

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
	GENERATED_BODY()


public:
	// UObject interface
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;

	UEmpexSettings(const FObjectInitializer& ObjectInitializer);
	~UEmpexSettings();

	float GetFactor() const { return Factor; }
	void SetFactor(float InRadius);
protected:
	/** Example float property */
	UPROPERTY(EditAnywhere, Category = "Global Settings")
	float Factor;
public:
	/** Min and Max FloatFoo range retrieved from config */
	float FactorMin;
	float FactorMax;

	/** Example boolean property */
	UPROPERTY(EditAnywhere, Category = "Global Settings", meta = (DisplayName = "Boolean Bar"))
	bool bBooleanBar;

	/** Example enum property */
	UPROPERTY(EditAnywhere, Category = "Global Settings")
	EEmpexEnumDataExample EnumDataExample;
};
