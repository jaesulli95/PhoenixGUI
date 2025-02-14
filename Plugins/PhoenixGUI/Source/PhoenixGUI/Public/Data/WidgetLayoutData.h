// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/Layout/Anchors.h"
#include "WidgetLayoutData.generated.h"


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
