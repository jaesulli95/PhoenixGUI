// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixWidget.h"
#include "UI/PhoenixScreen.h"
#include "Components/Image.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Blueprint/WidgetLayoutLibrary.h"

void UPhoenixWidget::WidgetSelected()
{
	UPhoenixScreen* Screen = GetParentScreen();
	if (Screen && Screen->GuiState== EGuiState::EGS_Editing) {
		Screen->SetCurrentEditWidget(this);
	}
}

void UPhoenixWidget::ApplyWidgetLayoutData(FWidgetLayoutData WLData)
{
	CurrentWidgetData = WLData;
}

FWidgetLayoutData UPhoenixWidget::GetWidgetLayoutData()
{
	return CurrentWidgetData;
}

void UPhoenixWidget::GuiFeedbackSetSelectedWidget(bool bSelected)
{
	if (SelectedEditImage == nullptr) {
		return;
	}
	if (bSelected) {
		SelectedEditImage->SetVisibility(ESlateVisibility::Visible);	
	}
	else {
		SelectedEditImage->SetVisibility(ESlateVisibility::Hidden);
	}

}

void UPhoenixWidget::SetDisplay(bool bShouldDisplay)
{
	if (bShouldDisplay) {
		SetVisibility(ESlateVisibility::Visible);
		return;
	}
	SetVisibility(ESlateVisibility::Hidden);
}
