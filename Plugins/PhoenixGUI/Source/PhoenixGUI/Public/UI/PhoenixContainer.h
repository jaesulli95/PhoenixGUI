// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PhoenixContainer.generated.h"

/**
 * 
 */
UCLASS(Abstract)
class PHOENIXGUI_API UPhoenixContainer : public UUserWidget
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (InstanceEditable = true), Category = "Data")
	FName LookupName;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (InstanceEditable = true), Category = "Data")
	FText Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, meta = (InstanceEditable = true), Category = "Data")
	bool bCanMove = false;

	UPROPERTY(BlueprintReadWrite, Category = "Data")
	bool bIsDragging = false;

	UPROPERTY(BlueprintReadWrite, Category = "Data")
	FVector2D DragOffset = FVector2d(0.0, 0.0);
};
