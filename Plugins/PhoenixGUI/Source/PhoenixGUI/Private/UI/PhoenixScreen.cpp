// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixScreen.h"
#include "UI/PhoenixWidget.h"
#include "UI/PhoenixWindow.h"
#include "Interfaces/Toggleable.h"

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

void UPhoenixScreen::SaveLoadout(TArray<class UPhoenixBaseWidget> WidgetsToSave)
{
}

void UPhoenixScreen::AddToggleableWindow(IToggleable* ToggleableWindow)
{
    Toggleables.Add(ToggleableWindow);
}

void UPhoenixScreen::RemoveToggleableWindow(IToggleable* ToggleableWindow)
{
    Toggleables.Remove(ToggleableWindow);
}
