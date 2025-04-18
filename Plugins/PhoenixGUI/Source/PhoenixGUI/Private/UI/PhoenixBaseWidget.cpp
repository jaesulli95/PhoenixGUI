// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixBaseWidget.h"
#include "UI/PhoenixScreen.h"
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

	APlayerController* Controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);
	if (Controller) {
		
		if ((Controller->Tags.Find("EditUI") != INDEX_NONE)) {
			FEventReply EventReply = UWidgetBlueprintLibrary::DetectDragIfPressed(InMouseEvent, this, EKeys::LeftMouseButton);
			OnWidgetSelected.Broadcast(this);
			return EventReply.NativeReply;
		}
	
	}
	return FReply::Handled();
}
