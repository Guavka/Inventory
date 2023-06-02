// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Inventory/InventorySystem/Items/Models/ItemStackData.h"
#include "Inventory/InventorySystem/Items/Models/ItemRequestStackData.h"
#include "Inventory/InventorySystem/Items/Models/ItemData.h"

#include "InventoryComponent.generated.h"

struct FItemData;

UCLASS(Blueprintable, BlueprintType)
class UInventoryComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UInventoryComponent();

    UFUNCTION(BlueprintCallable)
    bool AddItem(FItemStackData NewItem);

    UFUNCTION(BlueprintCallable)
    void ThrowItem(uint8 SlotIndex);

    UFUNCTION(BlueprintCallable)
    void UseItem(uint8 SlotIndex);

    UFUNCTION(BlueprintCallable)
    bool TryTakeItems(FItemRequestStackData ItemData);

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
    TArray<struct FItemRequestStackData> DefaultItemsArray;

    UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Default")
    uint8 InventorySize;

    UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
    TArray<struct FItemStackData> ItemsArray;

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
    class ABaseCharacter *OwnerCharacter;

    DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnInventaryUpdated);
    UPROPERTY(BlueprintAssignable, EditDefaultsOnly, Category = "Default")
    FOnInventaryUpdated OnInventaryUpdated;
    

protected:
    class UDataTable *ItemsDataTable;

    virtual void BeginPlay();

    UFUNCTION(BlueprintCallable)
    bool CreateStack(FItemStackData NewItem);

    UFUNCTION(BlueprintCallable)
    bool AddToStack(FItemStackData NewItem, uint8 SlotIndex);

    UFUNCTION(BlueprintCallable)
    void RemoveStack(uint8 SlotIndex);

    int HasPartialStack(FItemStackData NewItem);
};
