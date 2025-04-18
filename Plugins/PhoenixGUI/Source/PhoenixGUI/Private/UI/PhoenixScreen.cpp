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

TArray<UPhoenixBaseWidget*> UPhoenixScreen::GetScreenWidgets()
{
    TArray<UPhoenixBaseWidget*> WidgetsOnScreen;
    PhoenixWidgets.GenerateValueArray(WidgetsOnScreen);
    return WidgetsOnScreen;
}

bool UPhoenixScreen::AreWindowsOpen()
{
    return (OpenedWindows.Num() == 0);
}

