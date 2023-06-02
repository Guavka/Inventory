// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Inventory/InventorySystem/Items/Equipment/BaseEquipItemActor.h"


#include "BodyEquipItemActor.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ABodyEquipItemActor : public ABaseEquipItemActor
{
	GENERATED_BODY()

public:
	ABodyEquipItemActor();
};
