// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UObject/NameTypes.h"

#include "Inventory/InventorySystem/InteractInterface.h"

#include "BaseInteractActor.generated.h"

class ABaseCharacter;
class IInteractInterface;

UCLASS(Blueprintable, BlueprintType)
class ABaseInteractActor : public AActor, public IInteractInterface
{
	GENERATED_BODY()


public:
	ABaseInteractActor();

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	class USphereComponent *Sphere;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Components")
	class UStaticMeshComponent *StaticMesh;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Default")
	TObjectPtr<USceneComponent> DefaultSceneRoot;

protected:
	void InitComponents();
};
