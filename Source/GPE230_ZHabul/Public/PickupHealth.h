// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Pickup.h"
#include "PickupHealth.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_ZHABUL_API APickupHealth : public APickup
{

	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere)
		float healthAmount;


	virtual void ApplyEffects(AMazeCharacter*) override;
};
