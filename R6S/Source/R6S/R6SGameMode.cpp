// Copyright Epic Games, Inc. All Rights Reserved.

#include "R6SGameMode.h"
#include "R6SCharacter.h"
#include "UObject/ConstructorHelpers.h"

void AR6SGameMode::StartPlay()
{
	Super::StartPlay();
	

	if (GEngine != nullptr)
	{
		GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Cyan, TEXT("Hello World"));
	}
}

AR6SGameMode::AR6SGameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}
