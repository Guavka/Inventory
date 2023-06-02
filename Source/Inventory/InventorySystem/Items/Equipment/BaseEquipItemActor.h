// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Inventory/InventorySystem/Items/BaseItemActor.h"

#include "BaseEquipItemActor.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ABaseEquipItemActor : public ABaseItemActor
{
	GENERATED_BODY()

public:
	ABaseEquipItemActor();

    UFUNCTION(BlueprintImplementableEvent)
    void EquipItem();
};
