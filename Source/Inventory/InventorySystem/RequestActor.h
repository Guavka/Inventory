// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NameTypes.h"

#include "Inventory/InventorySystem/BaseInteractActor.h"
#include "Inventory/Character/BaseCharacter.h"

#include "Inventory/InventorySystem/Items/Models/ItemRequestStackData.h"

#include "RequestActor.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ARequestActor : public ABaseInteractActor
{
	GENERATED_BODY()

public:
	ARequestActor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FItemRequestStackData RequestItem;

	UFUNCTION(BlueprintImplementableEvent)
	void InteractResult(bool Result);

	void Interact_Implementation(ABaseCharacter *Interactor) override;
};