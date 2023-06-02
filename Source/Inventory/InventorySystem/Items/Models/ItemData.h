// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "Inventory/InventorySystem/Items/BaseItemActor.h"

#include "ItemData.generated.h"

/**
 *
 */

USTRUCT(BlueprintType)
struct FItemData : public FTableRowBase
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Name", MakeStructureDefaultValue = "Item"))
	FString Name;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Description"))
	FString Description;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "Icon", MakeStructureDefaultValue = "None"))
	TObjectPtr<UTexture2D> Icon;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "IsStackable", MakeStructureDefaultValue = "False"))
	bool IsStackable;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "MaxStackSize", MakeStructureDefaultValue = "1"))
	uint8 MaxStackSize;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, meta = (DisplayName = "ActorClass", MakeStructureDefaultValue = "None"))
	TSubclassOf<ABaseItemActor> ActorClass;

	FItemData()
	{
		Name = "Item";
		Description = "Description";
		Icon = nullptr;
		IsStackable = false;
		MaxStackSize = 1;
		ActorClass = nullptr;
	}

	FItemData(FItemData* data)
	{
		Name = data->Name;
		Description = data->Description;
		Icon = data->Icon;
		IsStackable = data->IsStackable;
		MaxStackSize = data->MaxStackSize;
		ActorClass = data->ActorClass;
	}

	FItemData(FString name, FString description, UTexture2D *icon, bool isStackable, uint8 maxStackSize, TSubclassOf<ABaseItemActor> actorClass)
	{
		Name = name;
		Description = description;
		Icon = icon;
		IsStackable = isStackable;
		MaxStackSize = maxStackSize;
		ActorClass = actorClass;
	}
};
