// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "PickupSpeed.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_ZHABUL_API APickupSpeed : public APickup
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere)
		float speedAmount;


	virtual void ApplyEffects(AMazeCharacter*) override;
};
