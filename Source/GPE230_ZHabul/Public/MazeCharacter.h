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


/***********************************
*  VARIABLE DECLARATIONS
***********************************/
private:
	UPROPERTY(EditAnywhere)
		float moveSpeed;
	UPROPERTY(EditAnywhere)
		float rotationSpeed;
	UPROPERTY(EditAnywhere)
		UAnimSequence* _deathAnim;
	UPROPERTY(EditAnywhere)
		bool _isDead = false;

protected:
	/// <summary>
	/// The current health of the actor
	/// </summary>
	float _currentHealth;

public:
	/// <summary>
	/// The maximum and starting health for actor
	/// </summary>
	UPROPERTY(EditAnywhere)
		float maxHealth;

public:
	// Sets default values for this character's properties
	AMazeCharacter();
	 
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
		AActor* DamageCauser) override; //Gotta overide most of the stuff that comes from actor
	virtual void Die();


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


// Function stubs 
private:
	void MoveFB(float value); //Float parameter is scale from input axes
	void MoveLR(float value);
	void Rotate(float value);



};