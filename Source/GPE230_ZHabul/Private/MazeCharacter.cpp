// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCharacter.h"

// Sets default values
AMazeCharacter::AMazeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();
	_currentHealth = maxHealth;
	
}
/// <summary>
/// apply incoming damage to health and check if the player was killed
/// </summary>
/// <param name="DamageAmount">The amount of damage</param>
/// <param name="DamageEvent"></param>
/// <param name="EventInstigator"></param>
/// <param name="DamageCauser"></param>
/// <returns></returns>
float AMazeCharacter::TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator, AActor* DamageCauser)
{
	if (!_isDead)
	{
		//Subtract incoming damage
		_currentHealth -= DamageAmount;

		UE_LOG(LogTemp, Log, TEXT("player took %f damage. %f health remaining"), DamageAmount, _currentHealth); //Debug log

		if (_currentHealth <= 0)
			Die();

		return DamageAmount;
	}
	else
		return 0;
}

void AMazeCharacter::Die()
{
	_isDead = true;
	_currentHealth = 0;
	moveSpeed = 0;
	rotationSpeed = 0; //placeholder for now

	GetMesh()->PlayAnimation(_deathAnim, false);

	//TODO: trigger game over state and prompt the player to restart the level
}

// Called every frame
void AMazeCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMazeCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	// Linking input to Character controls. 
	PlayerInputComponent->BindAxis(TEXT("MoveFB"), this, &AMazeCharacter::MoveFB);
	PlayerInputComponent->BindAxis(TEXT("MoveLR"), this, &AMazeCharacter::MoveLR);
	PlayerInputComponent->BindAxis(TEXT("Rotate"), this, &AMazeCharacter::Rotate);

}

//Movement Input
void AMazeCharacter::MoveFB(float value)
{
	AddMovementInput(GetActorForwardVector(), value * moveSpeed);
}

void AMazeCharacter::MoveLR(float value)
{
	AddMovementInput(-GetActorRightVector(), value * moveSpeed);
}

void AMazeCharacter::Rotate(float value)
{
	AddControllerYawInput(value * rotationSpeed);
}



