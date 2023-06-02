#pragma once

#include "InteractInterface.generated.h"

class ABaseCharacter;

UINTERFACE(Blueprintable, MinimalAPI)
class UInteractInterface : public UInterface
{
	GENERATED_BODY()
};

class IInteractInterface
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Trigger Interaction")
	void Interact(ABaseCharacter* Interactor);
};