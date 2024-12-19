// Copyright Epic Games, Inc. All Rights Reserved.

#include "PhoenixPluginsGameMode.h"
#include "PhoenixPluginsCharacter.h"
#include "UObject/ConstructorHelpers.h"

APhoenixPluginsGameMode::APhoenixPluginsGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
