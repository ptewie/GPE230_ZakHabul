// Fill out your copyright notice in the Description page of Project Settings.


#include "MazeCharacter.h"

// Sets default values
AMazeCharacter::AMazeCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void AMazeCharacter::OpenGameOverScreen()
{
	_gameOverScreenInstance->AddToViewport();
	ShowMouseCursor();
	
	
}

void AMazeCharacter::PauseGameplay(bool bIsPaused)
{
	_controller->SetPause(bIsPaused);
}

void AMazeCharacter::ShowMouseCursor()
{
	_controller->bShowMouseCursor = true;
}

// Called when the game starts or when spawned
void AMazeCharacter::BeginPlay()
{
	Super::BeginPlay();

	_controller = Cast<APlayerController>(GetController()); //getting player controller

	_currentHealth = maxHealth; // setting intial max health

	//creating widgets from intial vars
	_playerHUDInstance = CreateWidget(GetWorld(), _playerHUDTemplate);
	_playerHUDInstance->AddToViewport(); //Hud should spawn as soon as player does, so it's added to the viewport here

	_gameOverScreenInstance = CreateWidget(GetWorld(), _gameOverScreenTemplate);
	_victoryScreenInstance = CreateWidget(GetWorld(), _victoryScreenTemplate);
	
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
	OpenGameOverScreen();

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

void AMazeCharacter::OpenVictoryScreen()
{
	UE_LOG(LogTemp, Log, TEXT("victory screen called"));
	_victoryScreenInstance->AddToViewport();
	ShowMouseCursor();
	PauseGameplay(true);



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

void AMazeCharacter::ActivateStunParticleSystem()
{
	if (_stunSystem)
	{
		USceneComponent* AttachComp = GetDefaultAttachComponent();

		//Spawns instance of particle system and attaches to player
		UNiagaraComponent* NiagaraComp = UNiagaraFunctionLibrary::SpawnSystemAttached(_stunSystem, AttachComp, NAME_None,
			FVector(0), FRotator(0), EAttachLocation::Type::KeepRelativeOffset, true);

		//Activate the system
		NiagaraComp->Activate();
	
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Player attempted to use sun ability, but no template particle system has been found"));
	}
}

float AMazeCharacter::HealPlayer(float healthHealed)
{
	if (!_isDead)
	{
		if ((_currentHealth + healthHealed) >= maxHealth)
		{
			_currentHealth = maxHealth;

		}
		else
		{
			_currentHealth += healthHealed;

		}
		UE_LOG(LogTemp, Log, TEXT("current health: %f, healedhealth: %f"), _currentHealth, healthHealed);
		return healthHealed;

	}
	else
		return 0;
}

float AMazeCharacter::SpeedPlayer(float speedIncreased)
{
	if (!_isDead)
	{
		moveSpeed += speedIncreased;
	}
	UE_LOG(LogTemp, Log, TEXT("movespeed is now: %f, increased by %f"), moveSpeed, speedIncreased);
	return speedIncreased;
}





