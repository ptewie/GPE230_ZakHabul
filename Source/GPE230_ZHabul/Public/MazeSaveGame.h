// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MazeSaveGame.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_ZHABUL_API UMazeSaveGame : public USaveGame
{
	GENERATED_BODY()
	

public:
	UPROPERTY(EditAnywhere)
	int furthestCompletedLevelOld;
	UPROPERTY(EditAnywhere)
	float masterVolumeSettingOld;
	UPROPERTY(EditAnywhere)
	float musicVolumeSettingOld;
	UPROPERTY(EditAnywhere)
	float sfxVolumeSettingOld;        //For some reason these classes refuse to be blueprint callable, this is whole C++ class sort of redundent because of that, sadly. 
									 // save game is hjandled with the Blueprint MazeSaveGameBP in Engine

};
