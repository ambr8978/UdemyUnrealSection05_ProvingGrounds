// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "S05_ProvingGroundsGameMode.h"
#include "S05_ProvingGroundsHUD.h"
#include "S05_ProvingGroundsCharacter.h"
#include "UObject/ConstructorHelpers.h"

AS05_ProvingGroundsGameMode::AS05_ProvingGroundsGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPersonCPP/Blueprints/FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	HUDClass = AS05_ProvingGroundsHUD::StaticClass();
}
