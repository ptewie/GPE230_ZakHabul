// Fill out your copyright notice in the Description page of Project Settings.

#include "PickupHealth.h"
#include "MazeCharacter.h"



void APickupHealth::ApplyEffects(AMazeCharacter* appliedCharacter)
{
	UE_LOG(LogTemp, Log, TEXT("player actor! upgrading speed!!"));
	Cast<AMazeCharacter>(appliedCharacter)->HealPlayer(healthAmount);
}
