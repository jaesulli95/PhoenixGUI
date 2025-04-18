// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/PhoenixWindow.h"
#include "Interfaces/Toggleable.h"
#include "GameplayTagContainer.h"
#include "PhoenixScreen.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScreenOpenedDelegate);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FScreenClosedDelegate);

class UPhoenixBaseWidget;

UCLASS()
class PHOENIXGUI_API UPhoenixScreen : public UUserWidget, public IToggleable
{
	GENERATED_BODY()

public:

	// ADD  IN THE ABILITY TOO STORE ALL WIDGET OF PHOENIXWIDGETS IN HERE

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FName PhoenixScreenName = FName("<PhoenixScreen>");

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Data")
	bool bIsEditable = true;

	//Widgets
	UPROPERTY(BlueprintReadOnly, Category="Data|Widgets")
	TMap<FName, UPhoenixBaseWidget*> PhoenixWidgets;

	UPROPERTY(BlueprintReadOnly, Category="Data|Widgets")
	TMap<FName, UPhoenixWindow*> PhoenixWindowsMap;

	UPROPERTY(BlueprintReadOnly, Category="Data|Widgets")
	TArray<FName> OpenedWindows;

	UPROPERTY(BlueprintReadWrite, Category="Data")
	FGameplayTagContainer ScreenTags;

	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Screen-Utility")
	UPhoenixWindow* GetWindow(FName WindowLookupName);

	UFUNCTION(BlueprintCallable, Category = "Screen-Utility")
	void ToggleWindow(FName WindowLookupName);

	UFUNCTION(BlueprintCallable, Category = "Screen-Utility")
	void AddWindow(class UPhoenixWindow* Window);

	UFUNCTION(BlueprintCallable, Category="Screen-Utility")
	void ModifyOpenWindows(FName WindowName, bool bIsOpen);

	UFUNCTION(BlueprintCallable, Category = "Screen-Utility")
	void CloseAllWindows();


	UFUNCTION(BlueprintCallable, BlueprintPure, Category="Screen-Utility")
	TArray< UPhoenixBaseWidget*> GetScreenWidgets();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Screen-Utility")
	bool AreWindowsOpen();

	//EVENTS
	UPROPERTY(BlueprintAssignable, BlueprintCallable, VisibleDefaultsOnly, Category="Screen|Events")
	FScreenOpenedDelegate ScreenOpened;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, VisibleDefaultsOnly, Category="Screen|Events")
	FScreenClosedDelegate ScreenClosed;
};
