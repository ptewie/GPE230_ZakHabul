// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MazeCharacter.h"
#include "Sound/SoundWave.h"
#include "Kismet/GameplayStatics.h"
#include "Pickup.generated.h"

UCLASS()
class GPE230_ZHABUL_API APickup : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APickup();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere)
	USceneComponent* PickupRoot;

	//Static mesh for pickup
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* PickupMesh;

	UPROPERTY(EditAnywhere)
	UShapeComponent* PickupBox;
	
	UPROPERTY(EditAnywhere)
	USoundWave* _pickupSound;

	UFUNCTION()
	//When overlap event happens, activate function
	virtual void OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep,
		const FHitResult& SweepResult);

	virtual void ApplyEffects(AMazeCharacter*);


};
