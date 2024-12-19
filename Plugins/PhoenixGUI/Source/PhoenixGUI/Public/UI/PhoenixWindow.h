// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UI/PhoenixBaseWidget.h"
#include "Interfaces/Toggleable.h"
#include "PhoenixWindow.generated.h"

/**
 * 
 */

UCLASS()
class PHOENIXGUI_API UPhoenixWindow : public UPhoenixBaseWidget
{
	GENERATED_BODY()

public:

	UPhoenixWindow();

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (InstanceEditable = true), Category="Data")
	bool bIsPersistent = true;

	UPROPERTY(EditAnywhere, meta=(InstanceEditable=true), Category = "Data")
	FName WindowLookupName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (InstanceEditable = true), Category = "Data")
	FText WindowName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta=(InstanceEditable=true), Category = "Data")
	FVector2D Dimensions = FVector2D(1280.F, 720.F);

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (InstanceEditable = true), Category = "Data")
	bool bCanMove = false;

	UPROPERTY(BlueprintReadWrite, Category = "Data")
	bool bIsDragging = false;

	UPROPERTY(BlueprintReadWrite, Category = "Data")
	FVector2D DragOffset = FVector2d(0.0, 0.0);

	UPROPERTY(EditDefaultsOnly, Category="Data|Sounds")
	TObjectPtr<USoundBase> ToggleSound;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Window-Utility")
	void OpenWindow();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Window-Utility")
	void CloseWindow();

	//virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	class UPhoenixScreen* GetParentScreen();
private:
	class UPhoenixScreen* ParentScreen;
};
