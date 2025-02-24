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

	UPROPERTY(BlueprintReadWrite)
	int32 PreviousScreen = 0;

	UPROPERTY(BlueprintReadOnly)
	FGameplayTagContainer MainTags;

	UPROPERTY(BlueprintReadOnly)
	TArray<UPhoenixScreen*> Screens;
};
