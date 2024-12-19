// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PhoenixWindow.h"
#include "UI/PhoenixScreen.h"


UPhoenixWindow::UPhoenixWindow() {
	Visibility = ESlateVisibility::Visible;
}

UPhoenixScreen* UPhoenixWindow::GetParentScreen()
{
	return ParentScreen;
}
