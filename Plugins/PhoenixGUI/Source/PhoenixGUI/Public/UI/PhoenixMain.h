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

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Data")
	bool bIsEditable = false;

	UPROPERTY(BlueprintReadOnly,  Category = "Data")
	bool bIsEditingUI = false;


	UPROPERTY(BlueprintReadOnly, Category="Data")
	TMap<FName, UPhoenixScreen*> Screens; //Stores References to Screens

	UFUNCTION(BlueprintCallable, Category="Main|Utility")
	void AddScreen(UPhoenixScreen* Screen);

	UFUNCTION(BlueprintCallable, Category = "Main|Utility")
	void PushScreen(FName ScreenName); //Rename to PushScreen-- layer

	UFUNCTION(BlueprintCallable, Category = "Main|Utility")
	void PopScreen(); //Rename to PopScreen also know as delayering

	UFUNCTION(BlueprintCallable, Category = "Main|Utility")
	void ScreenOpened();

	UFUNCTION(BlueprintCallable, Category = "Main|Utility")
	void ScreenClosed();

	UFUNCTION(BlueprintCallable, Category="Main|Edit|Utility")
	void SetIsEditing(bool _bIsEditingUI);

private:

	TArray<FName> ScreenStack;
};
