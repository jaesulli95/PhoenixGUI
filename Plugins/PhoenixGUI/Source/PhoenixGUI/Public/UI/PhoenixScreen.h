// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/PhoenixBaseWidget.h"
#include "PhoenixWindow.h"
#include "Data/EditGuiMode.h"
#include "PhoenixScreen.generated.h"

/**
 * 
 */

UCLASS()
class PHOENIXGUI_API UPhoenixScreen : public UPhoenixBaseWidget
{
	GENERATED_BODY()

public:

	// ADD  IN THE ABILITY TOO STORE ALL WIDGET OF PHOENIXWIDGETS IN HERE

	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category="Data")
	FName PhoenixScreenName = FName("<PhoenixScreen>");

	//Widgets
	UPROPERTY(BlueprintReadOnly, Category="Data|Widgets")
	TMap<FName, UPhoenixWidget*> PhoenixWidgets;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Data")
	EEditGuiMode GuiMode = EEditGuiMode::EGM_Anchor; // By Default Use Anchor

	UPROPERTY(BlueprintReadOnly, Category = "Data")
	EGuiState GuiState = EGuiState::EGS_Active;

	UFUNCTION(BlueprintPure, BlueprintCallable, Category="Screen-Utility")
	UPhoenixWindow* GetWindow(FName WindowLookupName);

	UFUNCTION(BlueprintCallable, Category = "Screen-Utility")
	void ToggleWindow(FName WindowLookupName);

	UFUNCTION(BlueprintCallable, Category = "Screen-Utility")
	void AddWindow(class UPhoenixWindow* Window);

	UFUNCTION(BlueprintCallable, Category = "Screen-Utility")
	void CloseAllWindows();

	UFUNCTION(BlueprintCallable, Category = "Screen-Utility")
	void SetEditState(EGuiState NewGuiState);

	UFUNCTION(BlueprintImplementableEvent, Category = "Screen-Utility")
	void BP_GuiStateChanged(EGuiState State);

	UPROPERTY(BlueprintReadOnly, Category="Data")
	class UPhoenixWidget* CurrentEditingWidget;

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Screen-Utility")
	class UPhoenixWidget* GetCurrentEditWidget();

	UFUNCTION(BlueprintCallable, Category = "Screen-Utility")
	void SetCurrentEditWidget(class UPhoenixWidget* EditWidget);

	UFUNCTION(BlueprintImplementableEvent, Category = "Screen-Utility")
	void BP_EditWidgetSelected(const class UPhoenixWidget* PhoenixWidget);

private:
	TMap<FName, UPhoenixWindow*> PhoenixWindowsMap;
	TArray<IToggleable*> Toggleables;
	void AddToggleableWindow(IToggleable* ToggleableWindow);
	void RemoveToggleableWindow(IToggleable* ToggleableWindow);
};
