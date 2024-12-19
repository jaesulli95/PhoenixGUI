// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/PhoenixBaseWidget.h"
#include "Components/Image.h"
#include "PhoenixWidget.generated.h"

/**
 * 
 */

class UCanvasPanelSlot;

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
	UPROPERTY(BlueprintReadWrite, Category="Anchor-Data")
	FAnchors Anchors;

	UPROPERTY(BlueprintReadWrite, Category = "Anchor-Data")
	FVector2D Position;

	UPROPERTY(BlueprintReadWrite, Category = "Anchor-Data")
	FVector2D Alignment;

	FWidgetLayoutData() {

	}
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWidgetEditSelectedDelegate, UPhoenixWidget*, PhoenixWidget);

UCLASS()
class PHOENIXGUI_API UPhoenixWidget : public UPhoenixBaseWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(BlueprintReadOnly, meta = (BindWidgetOptional), Category="Data")
	TObjectPtr<UImage> SelectedEditImage;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Data")
	FString WidgetDisplayName;

	UPROPERTY(BlueprintReadOnly, Category = "Data")
	FWidgetLayoutData CurrentWidgetData;

	UPROPERTY(BlueprintReadWrite, Category = "Data")
	bool bDisplay = true;

	UFUNCTION(BlueprintCallable, Category="Widget-Utility")
	void WidgetSelected();

	UFUNCTION(BlueprintCallable, Category = "Widget-Utility")
	void ApplyWidgetLayoutData(FWidgetLayoutData WLData);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Widget-Utility")
	FWidgetLayoutData GetWidgetLayoutData();

	UFUNCTION(BlueprintCallable, Category = "Widget-Utility")
	void GuiFeedbackSetSelectedWidget(bool bSelected);

	UFUNCTION(BlueprintCallable, Category = "Widget-Utility")
	void SetDisplay(bool bShouldDisplay);
};
