// Fill out your copyright notice in the Description page of Project Settings.


#include "PickupSpeed.h"

void APickupSpeed::ApplyEffects(AMazeCharacter* appliedCharacter)
{
		UE_LOG(LogTemp, Log, TEXT("player actor! speeding up!"));
		Cast<AMazeCharacter>(appliedCharacter)->SpeedPlayer(speedAmount);
}
