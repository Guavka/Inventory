// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Inventory/InventorySystem/Items/Equipment/HeadEquipItemActor.h"
#include "Inventory/InventorySystem/Items/Equipment/BodyEquipItemActor.h"
#include "Inventory/InventorySystem/Items/Equipment/LegsEquipItemActor.h"
#include "Inventory/InventorySystem/Items/Equipment/LeftEquipItemActor.h"
#include "Inventory/InventorySystem/Items/Equipment/RightEquipItemActor.h"

#include "Inventory/Character/BaseCharacter.h"

#include "EquipmentComponent.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UEquipmentComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
    class AHeadEquipItemActor *HeadActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
    class ABodyEquipItemActor *BodyActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
    class ALegsEquipItemActor *LegsActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
    class ALeftEquipItemActor *LeftHandActor;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
    class ARightEquipItemActor *RightHandActor;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
    class ABaseCharacter *OwnerCharacter;

    UFUNCTION(BlueprintCallable)
    void EquipItem(ABaseEquipItemActor *item);

    UFUNCTION(BlueprintCallable)
    void UnEquipItem(ABaseEquipItemActor *item);

protected:
    virtual void BeginPlay();
};
