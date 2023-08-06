// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "LockAndKey.generated.h"

/**
 * 
 */
UCLASS()
class GPE230_ZHABUL_API ALockAndKey : public ATriggerBox
{
	GENERATED_BODY()
	

public:
	ALockAndKey();

	UFUNCTION() //makes sure the actor that overlaps with trigger box as player
		void CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor); 
	
	UFUNCTION() //if the overlapping actor is the player, it calls the open door function
		void OpenDoor();


};
