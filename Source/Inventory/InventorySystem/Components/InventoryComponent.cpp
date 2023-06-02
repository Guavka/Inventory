#include "InventoryComponent.h"

#include "Inventory/Character/BaseCharacter.h"

UInventoryComponent::UInventoryComponent()
{
    
}

void UInventoryComponent::BeginPlay()
{
    OwnerCharacter = GetOwner<ABaseCharacter>();

    ItemsArray.Init(FItemStackData(), InventorySize);

    for (uint8 i = 0; i < DefaultItemsArray.Num(); ++i)
    {
        FName LocalRowName = DefaultItemsArray[i].ItemRowName;
        FItemData *OutRow = ItemsDataTable->FindRow<FItemData>(LocalRowName, "");

        FItemStackData newItem = FItemStackData(OutRow, DefaultItemsArray[i].Count);
        AddItem(newItem);
    }
}

bool UInventoryComponent::CreateStack(FItemStackData NewItem)
{
    int index = -1;
    FItemData newItemData;

    for (uint8 i = 0; i < ItemsArray.Num(); ++i)
    {
        newItemData = NewItem.ItemData;
        if (ItemsArray[i].Count == 0)
        {
            index = i;
            break;
        }
    }

    if (index == -1)
        return false;

    if (NewItem.Count > newItemData.MaxStackSize)
    {
        ItemsArray[index].ItemData = newItemData;
        ItemsArray[index].Count = newItemData.MaxStackSize;
        NewItem.Count -= newItemData.MaxStackSize;
        return AddItem(NewItem);
    }

    ItemsArray[index] = NewItem;
    return true;
}

bool UInventoryComponent::AddToStack(FItemStackData NewItem, uint8 SlotIndex)
{
    auto stackSlot = ItemsArray[SlotIndex];
    auto currentStackCount = stackSlot.Count;
    auto newCount = currentStackCount + NewItem.Count;
    if (newCount > stackSlot.Count)
    {
        ItemsArray[SlotIndex].Count = stackSlot.ItemData.MaxStackSize;

        newCount = NewItem.Count - (stackSlot.ItemData.MaxStackSize - currentStackCount);
        return AddItem(FItemStackData(NewItem.ItemData, newCount));
    }
    ItemsArray[SlotIndex] = FItemStackData(NewItem.ItemData, newCount);
    return true;
}

void UInventoryComponent::RemoveStack(uint8 SlotIndex)
{
    ItemsArray[SlotIndex] = FItemStackData();
    OnInventaryUpdated.Broadcast();
}

int UInventoryComponent::HasPartialStack(FItemStackData NewItem)
{
    int slotIndex = -1;
    bool isFind = false;
    for (uint8 i = 0; i < ItemsArray.Num(); ++i)
    {
        auto item = ItemsArray[i];
        auto itemData = ItemsArray[i].ItemData;

        isFind = itemData.ActorClass == NewItem.ItemData.ActorClass && item.Count < itemData.MaxStackSize;
        if (isFind)
        {
            slotIndex = i;
            break;
        }
    }
    return slotIndex;
}

bool UInventoryComponent::AddItem(FItemStackData NewItem)
{
    if (NewItem.ItemData.IsStackable)
    {
        int index = HasPartialStack(NewItem);
        if (index != -1)
        {
            if (AddToStack(NewItem, index))
            {
                OnInventaryUpdated.Broadcast();
                return true;
            }
        }
    }
    if (CreateStack(NewItem))
    {
        OnInventaryUpdated.Broadcast();
        return true;
    }

    return false;
}

void UInventoryComponent::ThrowItem(uint8 SlotIndex)
{
    auto actorClass = ItemsArray[SlotIndex].ItemData.ActorClass;

    auto location = OwnerCharacter->SpawnPoint->GetComponentLocation();
    auto rotation = OwnerCharacter->SpawnPoint->GetComponentRotation();

    auto actor = GetWorld()->SpawnActor<ABaseItemActor>(actorClass, location, rotation);
    actor->Count = ItemsArray[SlotIndex].Count;

    RemoveStack(SlotIndex);
}

void UInventoryComponent::UseItem(uint8 SlotIndex)
{
    auto localItemData = ItemsArray[SlotIndex].ItemData;
    auto actorClass = ItemsArray[SlotIndex].ItemData.ActorClass;

    FActorSpawnParameters parameters;
    parameters.Owner = OwnerCharacter;

    auto actor = GetWorld()->SpawnActor<ABaseItemActor>(actorClass, OwnerCharacter->GetActorLocation(), OwnerCharacter->GetActorRotation(), parameters);
    actor->Count = 1;
}

bool UInventoryComponent::TryTakeItems(FItemRequestStackData ItemData)
{
    auto localItemData = ItemsDataTable->FindRow<FItemData>(ItemData.ItemRowName, "");
    uint8 localNeededCount = ItemData.Count;
    uint8 localCount = 0;

    for (uint8 i = 0; i < ItemsArray.Num(); ++i)
    {
        if (localItemData->ActorClass == ItemsArray[i].ItemData.ActorClass)
            localCount += ItemsArray[i].Count;
    }

    if (localCount < localNeededCount)
        return false;

    for (uint8 i = 0; i < ItemsArray.Num(); ++i)
    {
        auto item = ItemsArray[i];
        if (localItemData->ActorClass != item.ItemData.ActorClass)
            continue;

        if (localNeededCount >= item.Count)
        {
            localNeededCount -= item.Count;
            RemoveStack(i);
        }
        else
        {
            ItemsArray[i] = FItemStackData(localItemData, item.Count - localNeededCount);
            localNeededCount = 0;
        }

        if (localNeededCount == 0)
            break;
    }
    OnInventaryUpdated.Broadcast();
    return true;
}
