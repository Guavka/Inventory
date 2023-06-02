// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "ItemUIData.generated.h"

/**
 *
 */

USTRUCT(BlueprintType)
struct FItemUIData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (DisplayName = "Name", MakeStructureDefaultValue = "Item"))
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (DisplayName = "Description"))
	FString Description;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (DisplayName = "Icon", MakeStructureDefaultValue = "None"))
	TObjectPtr<UTexture2D> Icon;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (DisplayName = "StackSize", MakeStructureDefaultValue = "1"))
	uint8 StackSize;

	UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, meta = (DisplayName = "Count", MakeStructureDefaultValue = "1"))
	uint8 Count;

	FItemUIData()
	{
		Name = "Item";
		Description = "Description";
		Icon = nullptr;
		StackSize = 1;
		Count = 1;
	}

	FItemUIData(FString name, FString description, UTexture2D *icon, uint8 maxStackSize, uint8 count)
	{
		Name = name;
		Description = description;
		Icon = icon;
		StackSize = maxStackSize;
		Count = count;
	}
};
