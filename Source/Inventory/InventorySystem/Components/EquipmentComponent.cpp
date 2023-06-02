#include "EquipmentComponent.h"
#include "Inventory/Character/BaseCharacter.h"
#include "Engine/EngineTypes.h"

void UEquipmentComponent::BeginPlay()
{
    OwnerCharacter = GetOwner<ABaseCharacter>();
}

void UEquipmentComponent::EquipItem(ABaseEquipItemActor *item)
{
    /*ToggleEquipment<AHeadEquipItemActor>(HeadActor, item, HeadSocket);
    ToggleEquipment<ABodyEquipItemActor>(BodyActor, item, BodySocket);
    ToggleEquipment<ALegsEquipItemActor>(LegsActor, item, LegsSocket);
    ToggleEquipment<ALeftEquipItemActor>(LeftHandActor, item, LeftSocket);
    ToggleEquipment<ARightEquipItemActor>(RightHandActor, item, RightSocket);
    */
   if (auto castedItem = Cast<AHeadEquipItemActor>(item))
    {
        if (HeadActor == nullptr)
        {
            HeadActor = castedItem;
            AttachActor(HeadActor, HeadSocket);
            return;
        }

        if (item->GetClass() == HeadActor->GetClass())
        {
            HeadActor->Destroy();
            item->Destroy();
        }
    }
}

template <typename To>
void UEquipmentComponent::ToggleEquipment(To *equipmentItem, ABaseEquipItemActor *item, FName socket)
{
    if (auto castedItem = Cast<To>(item))
    {
        if (equipmentItem == nullptr)
        {
            equipmentItem = castedItem;
            AttachActor(equipmentItem, socket);
            return;
        }

        if (item->GetClass() == equipmentItem->GetClass())
        {
            equipmentItem->Destroy();
            item->Destroy();
        }
    }
}
