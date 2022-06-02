// Copyright Epic Games, Inc. All Rights Reserved.

#include "ImersysTest_CppGameMode.h"
#include "ImersysTest_CppCharacter.h"
#include "UObject/ConstructorHelpers.h"

AImersysTest_CppGameMode::AImersysTest_CppGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
