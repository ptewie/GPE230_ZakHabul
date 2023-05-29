// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MazeCharacter.generated.h"

/***********************************
 * PLAYER INITIALIZATION
 ***********************************/
UCLASS()
class GPE230_ZHABUL_API AMazeCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMazeCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

/***********************************
* MOVEMENT VARIABLE DECLARATIONS 
***********************************/
private:
	UPROPERTY(EditAnywhere)
		float moveSpeed;
	UPROPERTY(EditAnywhere)
		float rotationSpeed;

// Function stubs 
private:
	void MoveFB(float value); //Float parameter is scale from input axes
	void MoveLR(float value);
	void Rotate(float value);



};
