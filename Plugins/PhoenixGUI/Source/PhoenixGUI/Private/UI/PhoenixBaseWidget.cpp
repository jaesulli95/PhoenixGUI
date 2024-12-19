// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixBaseWidget.h"
#include "UI/PhoenixScreen.h"

void UPhoenixBaseWidget::SetParent(UPhoenixScreen* Parent)
{
	ParentScreen = Parent;
	if (ParentScreen) {
		UE_LOG(LogTemp, Warning, TEXT("Parent Screen Set"));
	}
}

UPhoenixScreen* UPhoenixBaseWidget::GetParentScreen()
{
	return ParentScreen;
}
