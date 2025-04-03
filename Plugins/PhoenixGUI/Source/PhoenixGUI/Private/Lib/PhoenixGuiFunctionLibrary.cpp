// Fill out your copyright notice in the Description page of Project Settings.


#include "Lib/PhoenixGuiFunctionLibrary.h"
#include "Blueprint/WidgetBlueprintLibrary.h"
#include "UI/PhoenixMain.h"

void UPhoenixGuiFunctionLibrary::PushScreenToView(FName ScreenName) {
	UPhoenixMain* MainRef = nullptr;

	for (TObjectIterator<UUserWidget> Itr; Itr; ++Itr) {
		UUserWidget* LiveWidget = *Itr;

		if (LiveWidget->GetClass()->IsChildOf(UPhoenixMain::StaticClass())) {
			MainRef = Cast<UPhoenixMain>(LiveWidget);
			break;
		}
	}

	if (MainRef) {
		MainRef->PushScreen(ScreenName);
	}

}

void UPhoenixGuiFunctionLibrary::PopScreenFromView(FName ScreenName) {
	UPhoenixMain* MainRef = nullptr;

	for (TObjectIterator<UUserWidget> Itr; Itr; ++Itr) {
		UUserWidget* LiveWidget = *Itr;

		if (LiveWidget->GetClass()->IsChildOf(UPhoenixMain::StaticClass())) {
			MainRef = Cast<UPhoenixMain>(LiveWidget);
			break;
		}
	}

	if (MainRef) {
		MainRef->PopScreen();
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("No Phoenix Main Ref"));
	}
}

