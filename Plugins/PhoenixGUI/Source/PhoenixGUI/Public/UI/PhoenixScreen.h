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

class UPhoenixWidget;

USTRUCT(BlueprintType, Blueprintable)
struct FWidgetLayoutData {
	GENERATED_BODY()
public:
	/*
	* Anchors
	* Alignment
	* Size
	* Position
	*/
	UPROPERTY(BlueprintReadWrite, Category = "Anchor-Data")
	FAnchors Anchors;

	UPROPERTY(BlueprintReadWrite, Category = "Anchor-Data")
	FVector2D Position;

	UPROPERTY(BlueprintReadWrite, Category = "Anchor-Data")
	FVector2D Alignment;

	FWidgetLayoutData() {

	}

	FWidgetLayoutData(FAnchors V_Anchors, FVector2D V_Position, FVector2D V_Alignment) {
		Anchors = V_Anchors;
		Position = V_Position;
		Alignment = V_Alignment;
	}
};

UCLASS()
class PHOENIXGUI_API UPhoenixScreen : public UUserWidget
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

	UFUNCTION(BlueprintCallable, Category="Screen-Utility")
	void ModifyOpenWindows(FName WindowName, bool bIsOpen);

	UFUNCTION(BlueprintCallable, Category = "Screen-Utility")
	void CloseAllWindows();

	UFUNCTION(BlueprintCallable, Category = "Screen-Utility")
	void SetEditState(EGuiState NewGuiState);

	UFUNCTION(BlueprintImplementableEvent, Category = "Screen-Utility")
	void BP_GuiStateChanged(EGuiState State);


	//Get Layout Data of Current Loadout and return. Will be used for saving the Layout Loadout
	UFUNCTION(BlueprintCallable, Category="Screen-Utility")
	TMap<FName, FWidgetLayoutData> GetLayoutData(TArray<UPhoenixBaseWidget*> WidgetsToSave);

	UFUNCTION(BlueprintCallable, Category="Screen-Utility")
	void SetLayoutData(TMap<FName, FWidgetLayoutData> LoadoutLayoutData);
};
