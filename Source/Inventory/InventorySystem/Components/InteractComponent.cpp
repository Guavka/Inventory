#include "InteractComponent.h"
#include "Inventory/InventorySystem/BaseInteractActor.h"
#include "Inventory/Character/BaseCharacter.h"

void UInteractComponent::StartInteract()
{
    TArray<AActor *> overlapArray;

    OwnerCharacter->GetOverlappingActors(overlapArray, TSubclassOf<ABaseInteractActor>());

    for (uint8 i = 0; i < overlapArray.Num(); ++i)
    {
        if (auto interactObj = Cast<ABaseInteractActor>(overlapArray[i]))
            interactObj->Interact_Implementation(OwnerCharacter);
    }
}

void UInteractComponent::BeginPlay()
{
    OwnerCharacter = GetOwner<ABaseCharacter>();
}
