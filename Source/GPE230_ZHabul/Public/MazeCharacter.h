// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"

#include "NiagaraFunctionLibrary.h"
#include "NiagaraComponent.h"

#include "Blueprint/UserWidget.h"

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
	UPROPERTY(EditAnywhere)
		UNiagaraSystem* _stunSystem;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _gameOverScreenTemplate;  //UI Template Instances!
	UUserWidget* _gameOverScreenInstance;
	UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _victoryScreenTemplate;
	UUserWidget* _victoryScreenInstance;
UPROPERTY(EditAnywhere)
	TSubclassOf<UUserWidget> _playerHUDTemplate;
	UUserWidget* _playerHUDInstance;
UPROPERTY(EditAnywhere)
		TSubclassOf<UUserWidget> _pauseMenuTemplate;
	UUserWidget* _pauseMenuInstance;


public:
	/// <summary>
	/// The current health of the actor
	/// </summary>
	UPROPERTY(BlueprintReadOnly)
	float _currentHealth;

public:
	/// <summary>
	/// The maximum and starting health for actor
	/// </summary>
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
		float maxHealth;


public:
	// Sets default values for this character's properties
	AMazeCharacter();
	 
protected:
	virtual void Die();
	/// <summary>
	/// The controller that manages this character! Assigned in BeginPlay() for MazeCharacter
	/// <summary>
	APlayerController* _controller;

	virtual void OpenGameOverScreen(); 
	virtual void PauseGameplay(bool bIsPaused); //Controlling UI!
	virtual void ShowMouseCursor();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual float TakeDamage(float DamageAmount, FDamageEvent const& DamageEvent, AController* EventInstigator,
		AActor* DamageCauser) override; //Gotta override most of the stuff that comes from actor


public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void OpenVictoryScreen(); //UI!




// Function stubs 
private:
	void MoveFB(float value); //Float parameter is scale from input axes
	void MoveLR(float value);

	void Rotate(float value);

	UFUNCTION(BlueprintCallable)
	void ActivateStunParticleSystem();
	
public:
	UFUNCTION(BlueprintCallable)
	float HealPlayer(float healthHealed);
	UFUNCTION(BlueprintCallable)
	float SpeedPlayer(float speedIncreased);

};