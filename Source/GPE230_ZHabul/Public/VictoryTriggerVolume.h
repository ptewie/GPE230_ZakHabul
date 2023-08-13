// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "VictoryTriggerVolume.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_ZHABUL_API AVictoryTriggerVolume : public APickup
{
	GENERATED_BODY()
	
	virtual void ApplyEffects(AMazeCharacter*) override;
};
