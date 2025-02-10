// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixBaseWidget.h"
#include "UI/PhoenixScreen.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetInputLibrary.h"
#include "InputCoreTypes.h"
#include "Input/Reply.h"

FReply UPhoenixBaseWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (!bSelectable) {
		return FReply::Handled();
	}

	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (Controller) {
		if ((Controller->Tags.Find("EDIT") != INDEX_NONE) &&
			UKismetInputLibrary::PointerEvent_IsMouseButtonDown(InMouseEvent, EKeys::LeftMouseButton)) {
			UE_LOG(LogTemp, Warning, TEXT("This Is Being Clicked"))
		}
	}
	return FReply::Handled();
}
