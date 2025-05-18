// Copyright Epic Games, Inc. All Rights Reserved.

#include "GDTV25GameMode.h"
#include "GDTV25PlayerController.h"
#include "GDTV25Character.h"
#include "UObject/ConstructorHelpers.h"

AGDTV25GameMode::AGDTV25GameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGDTV25PlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != nullptr)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}