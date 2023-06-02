// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "InteractComponent.generated.h"

UCLASS(Blueprintable, BlueprintType)
class UInteractComponent : public UActorComponent
{
    GENERATED_BODY()

public:
    UFUNCTION(BlueprintCallable)
    void StartInteract();

    UPROPERTY(BlueprintReadWrite, EditDefaultsOnly, Category = "Default")
    class ABaseCharacter *OwnerCharacter;

protected:
    virtual void BeginPlay();
};
