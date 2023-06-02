// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NameTypes.h"

#include "Inventory/InventorySystem/BaseInteractActor.h"
#include "Inventory/Character/BaseCharacter.h"

#include "BaseItemActor.generated.h"


UCLASS(Blueprintable, BlueprintType)
class ABaseItemActor : public ABaseInteractActor
{
	GENERATED_BODY()

public:
	ABaseItemActor();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	FName RowName;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Default")
	uint8 Count;

	void Interact_Implementation(ABaseCharacter *Interactor) override;

protected:
	class UDataTable* DataTable;
};
