// Fill out your copyright notice in the Description page of Project Settings.


#include "VictoryTriggerVolume.h"

void AVictoryTriggerVolume::ApplyEffects(AMazeCharacter* appliedCharacter)
{
	UE_LOG(LogTemp, Log, TEXT("level complete!"));
	Cast<AMazeCharacter>(appliedCharacter)->OpenVictoryScreen();

}
