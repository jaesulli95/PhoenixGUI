// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Interfaces/Toggleable.h"
#include "PhoenixWindow.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FWindowToggleDelegate, FName, WindowName , bool, bIsOpen);


UCLASS()
class PHOENIXGUI_API UPhoenixWindow : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (InstanceEditable = true), Category="Data")
	bool bIsPersistent = true;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta=(InstanceEditable=true), Category = "Data")
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

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category="Data|Sounds")
	TObjectPtr<USoundBase> ToggleSound;

	UPROPERTY(BlueprintAssignable, BlueprintCallable, Category="Window-Utility")
	FWindowToggleDelegate WindowToggled;

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Window-Utility")
	void OpenWindow();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Window-Utility")
	void CloseWindow();
};
