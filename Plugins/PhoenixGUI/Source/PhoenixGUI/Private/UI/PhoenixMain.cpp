// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixMain.h"
#include "UI/PhoenixScreen.h"

void UPhoenixMain::AddScreen(UPhoenixScreen* Screen)
{
	if (!Screen) {
		return;
	}

	Screens.Add(Screen->PhoenixScreenName, Screen);
}

void UPhoenixMain::ToggleScreen(FName ScreenName) {
	if (!Screens.Contains(ScreenName)) {
		return;
	}

	//Toggle The Screen Here
	Screens[ScreenName]->SetVisibility(ESlateVisibility::Visible);

	//Add To The Stack
	ScreenStack.Add(ScreenName);
}

void UPhoenixMain::CloseScreen(FName ScreenName)
{
	FName LastScreen = ScreenStack.Last(0);
	if (LastScreen == ScreenName) {
		ScreenStack.Pop(true);
		Screens[ScreenName]->SetVisibility(ESlateVisibility::Hidden);
	}
	else {
		//Wrong Screen Name
		return;
	}
}
