// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"



UENUM(BlueprintType)
enum class EEditGuiMode : uint8 {
	EGM_None UMETA(DisplayName = "None"),
	EGM_Anchor UMETA(DisplayName = "Anchor"),
	EGM_Mouse UMETA(DisplayName = "Mouse")
};

UENUM(BlueprintType)
enum class EGuiState : uint8 {
	EGS_Active UMETA(DisplayName="Active"),
	EGS_Editing UMETA(DisplayName="Edit")
};