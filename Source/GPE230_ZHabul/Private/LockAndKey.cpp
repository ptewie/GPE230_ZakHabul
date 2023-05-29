// Fill out your copyright notice in the Description page of Project Settings.

#include "MazeCharacter.h"
#include "LockAndKey.h"

ALockAndKey::ALockAndKey() //no parameters because this is active by defualt
{
	OnActorBeginOverlap.AddDynamic(this, &ALockAndKey::CheckActorType); // NOTE: & means memory address
}


/// Check if the other actor in this trigger is a MazeCharacter, If it is, open the door. 
void ALockAndKey::CheckActorType(class AActor* OverlappedActor, class AActor* OtherActor) //will define trigger box as overlapped actor and 
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass())) //If maze character, do the open door function
	{
		OpenDoor();
	} 
}

void ALockAndKey::OpenDoor()
{
	this->Destroy(); //TODO: Make it destroy with a particle effect or something instead of just blipping out of existance
}