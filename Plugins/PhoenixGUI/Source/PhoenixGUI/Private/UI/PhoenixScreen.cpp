// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixScreen.h"
#include "Interfaces/Toggleable.h"
#include "UI/PhoenixBaseWidget.h"
#include "Blueprint/WidgetLayoutLibrary.h"
#include "Components/CanvasPanelSlot.h"

UPhoenixWindow* UPhoenixScreen::GetWindow(FName WindowLookupName)
{
    if (PhoenixWindowsMap.Contains(WindowLookupName)) {
        return PhoenixWindowsMap[WindowLookupName];
    }
    return nullptr;
}

void UPhoenixScreen::ToggleWindow(FName WindowLookupName)
{
    UPhoenixWindow* _Window = GetWindow(WindowLookupName);
    if (_Window) {
        if (_Window->GetVisibility() == ESlateVisibility::Visible) {
            _Window->CloseWindow();
        }
        else if (_Window->GetVisibility() == ESlateVisibility::Hidden) {
            _Window->OpenWindow();
        }
    }
}

void UPhoenixScreen::AddWindow(UPhoenixWindow* Window)
{
    PhoenixWindowsMap.Add(Window->WindowLookupName, Window);
}

void UPhoenixScreen::ModifyOpenWindows(FName WindowName, bool bIsOpen)
{
    if (bIsOpen) {
        OpenedWindows.Add(WindowName);
        return;
    }
    OpenedWindows.Remove(WindowName);
}

void UPhoenixScreen::CloseAllWindows()
{
    //Cycle through Windows Close all Windows
    for (FName WindowName : OpenedWindows) {
        UPhoenixWindow* WindowRef = GetWindow(WindowName);
        if (WindowRef) {
            WindowRef->CloseWindow();
        }
    }
}

void UPhoenixScreen::SetEditState(EGuiState NewGuiState)
{
    if (bIsEditable) {
        GuiState = NewGuiState;
        BP_GuiStateChanged(GuiState);
    }
}

TMap<FName, FWidgetLayoutData> UPhoenixScreen::GetLayoutData(TArray<UPhoenixBaseWidget*> WidgetsToSave)
{
    TMap<FName, FWidgetLayoutData> LayoutData;
    int32 WidgetsNum = WidgetsToSave.Num();
    for (int32 i = 0; i < WidgetsNum; i++) {
        UCanvasPanelSlot* TmpCanvas = UWidgetLayoutLibrary::SlotAsCanvasSlot(WidgetsToSave[i]);
        LayoutData.Add(WidgetsToSave[i]->Name,
            FWidgetLayoutData(TmpCanvas->GetAnchors(), TmpCanvas->GetPosition(), TmpCanvas->GetAlignment()));
    }
    return LayoutData;
}

void UPhoenixScreen::SetLayoutData(TMap<FName, FWidgetLayoutData> LoadoutLayoutData)
{
    for (TPair<FName, FWidgetLayoutData> WData : LoadoutLayoutData) {
        if (PhoenixWidgets.Contains(WData.Key)) {

        }
    }
}

TArray<UPhoenixBaseWidget*> UPhoenixScreen::GetScreenWidgets()
{
    TArray<UPhoenixBaseWidget*> WidgetsOnScreen;
    PhoenixWidgets.GenerateValueArray(WidgetsOnScreen);
    return WidgetsOnScreen;
}

