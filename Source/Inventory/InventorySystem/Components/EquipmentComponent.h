// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "EquipmentComponent.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UEquipmentComponent : public UActorComponent
{
    GENERATED_BODY()

public:

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
    class ABaseCharacter *OwnerCharacter;

protected:
    virtual void BeginPlay();
};
