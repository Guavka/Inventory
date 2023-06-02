// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

#include "Inventory/InventorySystem/BaseInteractActor.h"
#include "Inventory/Character/BaseCharacter.h"

#include "Inventory/InventorySystem/Items/Models/ItemRequestStackData.h"

#include "BaseItemActor.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ABaseItemActor : public ABaseInteractActor
{
	GENERATED_BODY()

public:
	ABaseItemActor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FItemRequestStackData ItemInfo;

	void Interact_Implementation(ABaseCharacter *Interactor) override;

	UFUNCTION(BlueprintImplementableEvent)
    void StartUseItem();
};
