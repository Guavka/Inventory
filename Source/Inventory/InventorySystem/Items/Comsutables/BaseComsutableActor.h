// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Inventory/InventorySystem/Items/BaseItemActor.h"

#include "BaseComsutableActor.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ABaseComsutableActor : public ABaseItemActor
{
	GENERATED_BODY()

public:
	ABaseComsutableActor();
};
