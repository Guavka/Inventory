#include "RequestActor.h"

#include "Inventory/InventorySystem/Components/InventoryComponent.h"

#include "Inventory/InventorySystem/Items/Models/ItemRequestStackData.h"

ARequestActor::ARequestActor()
{
}

void ARequestActor::Interact_Implementation(ABaseCharacter *Interactor)
{
	auto component = Interactor->GetComponentByClass(UInventoryComponent::StaticClass());
	
	if (UInventoryComponent *inventory = Cast<UInventoryComponent>(component))
	{
		InteractResult(inventory->TryTakeItems(FItemRequestStackData(RequestItem)));
	}
}