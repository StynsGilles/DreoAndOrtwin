// Copyright Epic Games, Inc. All Rights Reserved.

#include "OneInTheFlipperGameMode.h"
#include "OneInTheFlipperCharacter.h"
#include "UObject/ConstructorHelpers.h"

AOneInTheFlipperGameMode::AOneInTheFlipperGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
