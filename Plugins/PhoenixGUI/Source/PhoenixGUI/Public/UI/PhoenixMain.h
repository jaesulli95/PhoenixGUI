// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "GameplayTagContainer.h"
#include "PhoenixMain.generated.h"

/**
 * 
 */

class UPhoenixScreen;

UCLASS()
class PHOENIXGUI_API UPhoenixMain : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadOnly)
	FGameplayTagContainer MainTags;

	UPROPERTY(BlueprintReadOnly)
	TMap<FName, UPhoenixScreen*> Screens;

	UFUNCTION(BlueprintCallable)
	void AddScreen(UPhoenixScreen* Screen);

	UFUNCTION(BlueprintCallable)
	void ToggleScreen(FName ScreenName);

	UFUNCTION(BlueprintCallable)
	void CloseScreen(FName ScreenName);

private:

	TArray<FName> ScreenStack;
};
