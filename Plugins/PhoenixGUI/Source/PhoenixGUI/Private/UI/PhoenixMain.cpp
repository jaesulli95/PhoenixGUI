// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixMain.h"
#include "UI/PhoenixScreen.h"
#include "Kismet/GameplayStatics.h"


void UPhoenixMain::AddScreen(UPhoenixScreen* Screen)
{
	if (!Screen) {
		return;
	}

	Screen->ScreenOpened.AddDynamic(this, &UPhoenixMain::ScreenOpened);
	Screen->ScreenClosed.AddDynamic(this, &UPhoenixMain::ScreenClosed);
	Screens.Add(Screen->PhoenixScreenName, Screen);
}

void UPhoenixMain::PushScreen(FName ScreenName) {
	if (!Screens.Contains(ScreenName)) {
		return;
	}
	
	//This is going to instead call a function on the screen that will call an event
	//To open the screen, then a tag will be passed, each screen will only be able to process 
	//input if it has a gameplay tag GUI.Active
	ScreenStack.Push(ScreenName);
	Screens[ScreenName]->SetVisibility(ESlateVisibility::Visible);
	Screens[ScreenName]->Execute_EventOpen(Screens[ScreenName]);


	if (ScreenStack.Num() <= 1) {
		return;
	}

	FName PreviousScreen = ScreenStack.Last(1);
	Screens[PreviousScreen]->SetVisibility(ESlateVisibility::Hidden);
	Screens[PreviousScreen]->Execute_EventClose(Screens[PreviousScreen]);

}

void UPhoenixMain::PopScreen()
{
	if (ScreenStack.Num() == 1) {
		return;
	}

	FName TopScreen = ScreenStack.Pop();
	Screens[TopScreen]->SetVisibility(ESlateVisibility::Hidden);
	Screens[TopScreen]->Execute_EventClose(Screens[TopScreen]);

	FName Top = ScreenStack.Top();
	Screens[Top]->SetVisibility(ESlateVisibility::Visible);
	Screens[Top]->Execute_EventOpen(Screens[Top]);
}

//Empty Functions incase they are needed some day
void UPhoenixMain::ScreenOpened() {

}

void UPhoenixMain::ScreenClosed() {

}

void UPhoenixMain::SetIsEditing(bool _bIsEditingUI)
{
	bIsEditingUI = _bIsEditingUI;
	APlayerController* controller = UGameplayStatics::GetPlayerController(GetWorld(), 0);

	if (!controller) {
		return;
	}

	if (bIsEditingUI) {
		controller->Tags.Add(FName("EditUI"));
		return;
	}

	controller->Tags.Remove(FName("EditUI"));
}
