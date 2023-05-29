// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeGameMode.h"

void AMazeGameMode::InitGameState()
{
	Super::InitGameState();

	//if you have no overide for the defualt pawn class
	if (DefaultPawnClass == ADefaultPawn::StaticClass()) 
	{
		//set the defualt pawn to the custom c++ class
		DefaultPawnClass = DefualtPlayerCharater;
	}
}


