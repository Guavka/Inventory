#include "EquipmentComponent.h"
#include "Inventory/Character/BaseCharacter.h"

void UEquipmentComponent::BeginPlay()
{
    OwnerCharacter = GetOwner<ABaseCharacter>();
}