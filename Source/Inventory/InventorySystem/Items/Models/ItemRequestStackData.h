// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ItemRequestStackData.generated.h"

/**
 *
 */

USTRUCT(BlueprintType)
struct FItemRequestStackData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ItemRowName", MakeStructureDefaultValue = "None"))
	FName ItemRowName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Count", MakeStructureDefaultValue = "1"))
	uint8 Count;

	FItemRequestStackData()
	{
		ItemRowName = FName(TEXT("Name"));
		Count = 0;
	}

	FItemRequestStackData(FName name, uint8 count)
	{
		ItemRowName = name;
		Count = count;
	}
};
