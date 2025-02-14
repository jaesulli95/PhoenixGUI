// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixBaseWidget.h"
#include "UI/PhoenixScreen.h"
#include "Data/WidgetLayoutData.h"
#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetInputLibrary.h"
#include "Blueprint/WidgetLayoutLibrary.h"
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
		if ((Controller->Tags.Find("EDIT") != INDEX_NONE) &&
			UKismetInputLibrary::PointerEvent_IsMouseButtonDown(InMouseEvent, EKeys::LeftMouseButton)) {
			OnWidgetSelected.Broadcast(this);
		}
	}
	return FReply::Handled();
}

void UPhoenixBaseWidget::ApplyWidgetLayoutData(FWidgetLayoutData Data)
{
	UCanvasPanelSlot* Canvas = UWidgetLayoutLibrary::SlotAsCanvasSlot(this);
	if (Canvas) {
		Canvas->SetAnchors(Data.Anchors);
		Canvas->SetAlignment(Data.Alignment);
		Canvas->SetPosition(Data.Position);
	}
}
