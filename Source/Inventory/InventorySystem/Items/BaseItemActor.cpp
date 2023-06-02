#include "BaseItemActor.h"
#include "Inventory/InventorySystem/Items/Models/ItemData.h"
#include "Inventory/InventorySystem/Items/Models/ItemStackData.h"
#include "Inventory/InventorySystem/Components/InventoryComponent.h"

ABaseItemActor::ABaseItemActor()
{
    Count = 1;
}

void ABaseItemActor::Interact_Implementation(ABaseCharacter *Interactor)
{
    FItemData *OutRow = DataTable->FindRow<FItemData>(RowName, "");

    FItemStackData newItem = FItemStackData(OutRow, Count);

    auto component = Interactor->GetComponentByClass(UInventoryComponent::StaticClass());
    if (UInventoryComponent *inventory = Cast<UInventoryComponent>(component))
    {
        if (inventory->AddItem(newItem))
        {
            Destroy();
        }
    }
}