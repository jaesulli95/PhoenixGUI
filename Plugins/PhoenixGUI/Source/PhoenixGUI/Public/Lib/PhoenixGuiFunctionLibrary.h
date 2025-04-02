// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "PhoenixGuiFunctionLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PHOENIXGUI_API UPhoenixGuiFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
public:
	UFUNCTION(BlueprintCallable)
	static void PushScreenToView(FName ScreenName);

	UFUNCTION(BlueprintCallable)
	static void PopScreenFromView(FName ScreenName);

	UFUNCTION(BlueprintCallable)
	static void PushScreenWidgetToView(class UPhoenixScreen* Screen);
};
