// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixBaseWidget.h"
#include "UI/PhoenixScreen.h"
#include "Data/WidgetLayoutData.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetInputLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "Components/CanvasPanelSlot.h"
#include "InputCoreTypes.h"
#include "Input/Reply.h"

FReply UPhoenixBaseWidget::NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent)
{
	if (!bSelectable) {
		return FReply::Handled();
	}

	//EDIT DRAG and EDIT_ANCHORS

	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (Controller) {
		if ((Controller->Tags.Find("EDIT") != INDEX_NONE) &&
			UKismetInputLibrary::PointerEvent_IsMouseButtonDown(InMouseEvent, EKeys::LeftMouseButton)) {
			OnWidgetSelected.Broadcast(this);
			return FReply::Handled();
		}

		if (Controller->Tags.Find("EDIT_DRAG") != INDEX_NONE) {
			UE_LOG(LogTemp, Warning, TEXT("Dragging FIRING"));
			FEventReply EventReply = UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton);
			return EventReply.NativeReply;
		}
	}
	return FReply::Handled();
}
