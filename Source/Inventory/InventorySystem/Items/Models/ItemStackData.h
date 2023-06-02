// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Inventory/InventorySystem/Items/Models/ItemData.h"

#include "ItemStackData.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FItemStackData
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="ItemRowName", MakeStructureDefaultValue="None"))
	struct FItemData ItemData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(DisplayName="Count", MakeStructureDefaultValue="1"))
	uint8 Count;

	FItemStackData()
	{
		ItemData = FItemData();
		Count = 0;
	}

	FItemStackData(FItemData data, uint8 count)
	{
		ItemData = data;
		Count = count;
	}
};
