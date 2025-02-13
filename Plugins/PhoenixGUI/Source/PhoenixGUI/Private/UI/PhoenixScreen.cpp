// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixScreen.h"
#include "UI/PhoenixWindow.h"
#include "Interfaces/Toggleable.h"
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

void UPhoenixScreen::CloseAllWindows()
{
    //Cycle through Windows Close all Windows

}

void UPhoenixScreen::SetEditState(EGuiState NewGuiState)
{
    GuiState = NewGuiState;
    BP_GuiStateChanged(GuiState);
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
    UE_LOG(LogTemp, Warning, TEXT("Number of Widgets Saved in Layout Data: %d"), LayoutData.Num());
    return LayoutData;
}

void UPhoenixScreen::AddToggleableWindow(IToggleable* ToggleableWindow)
{
    Toggleables.Add(ToggleableWindow);
}

void UPhoenixScreen::RemoveToggleableWindow(IToggleable* ToggleableWindow)
{
    Toggleables.Remove(ToggleableWindow);
}
