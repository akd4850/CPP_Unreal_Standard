// Copyright Epic Games, Inc. All Rights Reserved.

#include "ArenaBattle_KMSGameMode.h"
#include "ArenaBattle_KMSCharacter.h"
#include "UObject/ConstructorHelpers.h"

AArenaBattle_KMSGameMode::AArenaBattle_KMSGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
