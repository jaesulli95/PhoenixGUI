// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "Toggleable.generated.h"

// This class does not need to be modified.
UINTERFACE(Blueprintable)
class UToggleable : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class PHOENIXGUI_API IToggleable
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="UI|Interfaces")
	void EventOpen();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "UI|Interfaces")
	void EventClose();
};
