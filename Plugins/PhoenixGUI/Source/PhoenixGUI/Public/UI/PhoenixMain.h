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
	TMap<FName, UPhoenixScreen*> Screens; //Stores References to Screens

	UFUNCTION(BlueprintCallable)
	void AddScreen(UPhoenixScreen* Screen);

	UFUNCTION(BlueprintCallable)
	void PushScreen(FName ScreenName); //Rename to PushScreen-- layer

	UFUNCTION(BlueprintCallable)
	void PopScreen(); //Rename to PopScreen also know as delayering

	UFUNCTION(BlueprintCallable)
	void ScreenOpened();

	UFUNCTION(BlueprintCallable)
	void ScreenClosed();

private:

	TArray<FName> ScreenStack;
};
