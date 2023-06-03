#include "EquipmentComponent.h"
#include "Inventory/Character/BaseCharacter.h"
#include "Engine/EngineTypes.h"

void UEquipmentComponent::BeginPlay()
{
    OwnerCharacter = GetOwner<ABaseCharacter>();
}

void UEquipmentComponent::EquipItem(ABaseEquipItemActor *item)
{
    if (auto castedItem = Cast<AHeadEquipItemActor>(item))
    {
        if (HeadActor != NULL)
        {
            if (castedItem->GetClass() == HeadActor->GetClass())
            {
                castedItem->Destroy();
                HeadActor->Destroy();
                HeadActor = NULL;
                return;
            }
            HeadActor->Destroy();
            HeadActor = NULL;
        }

        HeadActor = castedItem;
        AttachActor(HeadActor, HeadSocket);
        return;
    }
    if (auto castedItem = Cast<ABodyEquipItemActor>(item))
    {
        if (BodyActor != NULL)
        {
            if (castedItem->GetClass() == BodyActor->GetClass())
            {
                castedItem->Destroy();
                BodyActor->Destroy();
                BodyActor = NULL;
                return;
            }
            BodyActor->Destroy();
            BodyActor = NULL;
        }

        BodyActor = castedItem;
        AttachActor(BodyActor, BodySocket);
        return;
    }
    if (auto castedItem = Cast<ALegsEquipItemActor>(item))
    {
        if (LegsActor != NULL)
        {
            if (castedItem->GetClass() == LegsActor->GetClass())
            {
                castedItem->Destroy();
                LegsActor->Destroy();
                LegsActor = NULL;
                return;
            }
            LegsActor->Destroy();
            LegsActor = NULL;
        }

        LegsActor = castedItem;
        AttachActor(LegsActor, LegsSocket);
        return;
    }
    if (auto castedItem = Cast<ALeftEquipItemActor>(item))
    {
        if (LeftHandActor != NULL)
        {
            if (castedItem->GetClass() == LeftHandActor->GetClass())
            {
                castedItem->Destroy();
                LeftHandActor->Destroy();
                LeftHandActor = NULL;
                return;
            }
            LeftHandActor->Destroy();
            LeftHandActor = NULL;
        }

        LeftHandActor = castedItem;
        AttachActor(LeftHandActor, LeftSocket);
        return;
    }
    if (auto castedItem = Cast<ARightEquipItemActor>(item))
    {
        if (RightHandActor != NULL)
        {
            if (castedItem->GetClass() == RightHandActor->GetClass())
            {
                castedItem->Destroy();
                RightHandActor->Destroy();
                RightHandActor = NULL;
                return;
            }
            RightHandActor->Destroy();
            RightHandActor = NULL;
        }

        RightHandActor = castedItem;
        AttachActor(RightHandActor, RightSocket);
        return;
    }
}

void UEquipmentComponent::UnEquipItem(ABaseEquipItemActor *item)
{
    if (auto castedItem = Cast<AHeadEquipItemActor>(item))
    {
        if (HeadActor != NULL)
        {
            if (castedItem->GetClass() == HeadActor->GetClass())
            {
                HeadActor->Destroy();
                HeadActor = NULL;
            }
        }
        return;
    }
    if (auto castedItem = Cast<ABodyEquipItemActor>(item))
    {
        if (BodyActor != NULL)
        {
            if (castedItem->GetClass() == BodyActor->GetClass())
            {
                BodyActor->Destroy();
                BodyActor = NULL;
            }
        }
        return;
    }
    if (auto castedItem = Cast<ALegsEquipItemActor>(item))
    {
        if (LegsActor != NULL)
        {
            if (castedItem->GetClass() == LegsActor->GetClass())
            {
                LegsActor->Destroy();
                LegsActor = NULL;
            }
        }
        return;
    }
    if (auto castedItem = Cast<ALeftEquipItemActor>(item))
    {
        if (LeftHandActor != NULL)
        {
            if (castedItem->GetClass() == LeftHandActor->GetClass())
            {
                LeftHandActor->Destroy();
                LeftHandActor = NULL;
            }
        }
        return;
    }
    if (auto castedItem = Cast<ARightEquipItemActor>(item))
    {
        if (RightHandActor != NULL)
        {
            if (castedItem->GetClass() == RightHandActor->GetClass())
            {
                RightHandActor->Destroy();
                RightHandActor = NULL;
            }
        }
        return;
    }
}

void UEquipmentComponent::ToggleEquipment(ABaseEquipItemActor *equipmentItem, ABaseEquipItemActor *item, FName socket)
{
    if (equipmentItem != NULL)
    {
        if (item->GetClass() == equipmentItem->GetClass())
        {
            item->Destroy();
            equipmentItem->Destroy();
            equipmentItem = NULL;
            return;
        }
        equipmentItem->Destroy();
        equipmentItem = NULL;
    }

    equipmentItem = item;
    AttachActor(equipmentItem, socket);
}
