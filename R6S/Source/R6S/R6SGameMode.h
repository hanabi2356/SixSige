// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "R6SGameMode.generated.h"

UCLASS(minimalapi)
class AR6SGameMode : public AGameModeBase
{
	GENERATED_BODY()
	virtual void StartPlay()override;

public:
	AR6SGameMode();
};



