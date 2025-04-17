// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PhoenixBaseWidget.generated.h"

/**
 * 
 */
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FWidgetSelectedDelegate, UPhoenixBaseWidget*, Widget);

UCLASS(ABSTRACT)
class PHOENIXGUI_API UPhoenixBaseWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Data")
	FName Name;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Data")
	FString WidgetDisplayName;

	UPROPERTY(BlueprintReadWrite, Category = "Data")
	bool bDisplay = true;

	UPROPERTY(BlueprintAssignable, BlueprintCallable)
	FWidgetSelectedDelegate OnWidgetSelected;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Data")
	bool bSelectable = true;

	UPROPERTY(BlueprintReadOnly, EditDefaultsOnly, Category = "Data")
	FVector2D ScaleLimits = FVector2D(.5, 2.0);
	
	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Utilities")
	void StartEditWidget();

	UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category="Utilities")
	void EndEditWidget();

	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	
};
