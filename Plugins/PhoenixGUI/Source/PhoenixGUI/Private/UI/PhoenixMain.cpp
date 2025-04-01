// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixMain.h"
#include "UI/PhoenixScreen.h"

void UPhoenixMain::AddScreen(UPhoenixScreen* Screen)
{
	if (!Screen) {
		return;
	}

	Screens.Add(Screen->PhoenixScreenName, Screen);
	UE_LOG(LogTemp, Warning, TEXT("Added Screen: %s"), *Screen->PhoenixScreenName.ToString());
}

void UPhoenixMain::PushScreen(FName ScreenName) {
	if (!Screens.Contains(ScreenName)) {
		return;
	}

	//Push this too the TOP
	ScreenStack.Push(ScreenName);
	
	//This is going to instead call a function on the screen that will call an event
	//To open the screen, then a tag will be passed, each screen will only be able to process 
	//input if it has a gameplay tag GUI.Active
	Screens[ScreenName]->SetVisibility(ESlateVisibility::Visible);

	if (ScreenStack.Num() <= 1) {
		return;
	}

	FName PreviousScreen = ScreenStack.Last(1);
	Screens[PreviousScreen]->SetVisibility(ESlateVisibility::Hidden);
}

void UPhoenixMain::PopScreen()
{
	if (ScreenStack.Num() == 1) {
		return;
	}
	FName TopScreen = ScreenStack.Pop();
	Screens[TopScreen]->SetVisibility(ESlateVisibility::Hidden);

	FName Top = ScreenStack.Top();
	Screens[Top]->SetVisibility(ESlateVisibility::Visible);
}
