// Copyright Epic Games, Inc. All Rights Reserved.

#include "AICompanionGameMode.h"
#include "AICompanionCharacter.h"
#include "UObject/ConstructorHelpers.h"

AAICompanionGameMode::AAICompanionGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}
