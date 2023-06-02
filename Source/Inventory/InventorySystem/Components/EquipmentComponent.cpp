#include "EquipmentComponent.h"
#include "Inventory/Character/BaseCharacter.h"

void UEquipmentComponent::BeginPlay()
{
    OwnerCharacter = GetOwner<ABaseCharacter>();
}

void UEquipmentComponent::EquipItem(ABaseEquipItemActor *item)
{
    if (auto head = Cast<AHeadEquipItemActor>(item))
    {
        HeadActor = head;
        return;
    }

    if (auto body = Cast<ABodyEquipItemActor>(item))
    {
        BodyActor = body;
        return;
    }

    if (auto legs = Cast<ALegsEquipItemActor>(item))
    {
        LegsActor = legs;
        return;
    }

    if (auto left = Cast<ALeftEquipItemActor>(item))
    {
        LeftHandActor = left;
        return;
    }

    if (auto right = Cast<ARightEquipItemActor>(item))
    {
        RightHandActor = right;
        return;
    }
}

void UEquipmentComponent::UnEquipItem(ABaseEquipItemActor *item)
{
    if (auto head = Cast<AHeadEquipItemActor>(item))
    {
        HeadActor = nullptr;
        return;
    }

    if (auto body = Cast<ABodyEquipItemActor>(item))
    {
        BodyActor = nullptr;
        return;
    }

    if (auto legs = Cast<ALegsEquipItemActor>(item))
    {
        LegsActor = nullptr;
        return;
    }

    if (auto left = Cast<ALeftEquipItemActor>(item))
    {
        LeftHandActor = nullptr;
        return;
    }

    if (auto right = Cast<ARightEquipItemActor>(item))
    {
        RightHandActor = nullptr;
        return;
    }
}
