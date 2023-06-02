#include "BaseItemActor.h"

#include "Inventory/InventorySystem/Components/InventoryComponent.h"

#include "Inventory/InventorySystem/Items/Models/ItemRequestStackData.h"

ABaseItemActor::ABaseItemActor()
{
}

void ABaseItemActor::Interact_Implementation(ABaseCharacter *Interactor)
{
    auto component = Interactor->GetComponentByClass(UInventoryComponent::StaticClass());
    if (UInventoryComponent *inventory = Cast<UInventoryComponent>(component))
    {
        if (inventory->TryAddItem(FItemRequestStackData(ItemInfo)))
        {
            Destroy();
        }
    }
}