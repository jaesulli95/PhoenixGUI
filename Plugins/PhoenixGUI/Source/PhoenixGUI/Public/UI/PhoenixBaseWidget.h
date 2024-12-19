// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PhoenixBaseWidget.generated.h"

/**
 * 
 */
UCLASS(ABSTRACT)
class PHOENIXGUI_API UPhoenixBaseWidget : public UUserWidget
{
	GENERATED_BODY()
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category="Data")
	FName Name;

	UFUNCTION(BlueprintCallable, Category="Widget-Utility")
	void SetParent(class UPhoenixScreen* Parent);

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Widget-Utility")
	UPhoenixScreen* GetParentScreen();


private:

	class UPhoenixScreen* ParentScreen;
};
