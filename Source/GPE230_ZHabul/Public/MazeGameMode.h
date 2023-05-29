// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameFramework/DefaultPawn.h"
#include "MazeCharacter.h"
#include "MazeGameMode.generated.h"

/**********************************
 * GAMEMODE INITIALIZATION 
 ***********************************/

UCLASS()
class GPE230_ZHABUL_API AMazeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	void InitGameState() override;

private:
	UPROPERTY(EditAnywhere, NoClear)
		TSubclassOf <AMazeCharacter> DefualtPlayerCharater = AMazeCharacter::StaticClass();

	
};
