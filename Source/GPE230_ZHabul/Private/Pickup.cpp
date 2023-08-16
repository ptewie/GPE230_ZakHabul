// Fill out your copyright notice in the Description page of Project Settings.

#include "Pickup.h"
#include "Components/ShapeComponent.h"
#include "Components/BoxComponent.h" //Forgot which one i specifcally needed for pick ups so i just threw all of em in
#include "Components/MeshComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
APickup::APickup()
{
 	
	PrimaryActorTick.bCanEverTick = true;

	PickupRoot = CreateDefaultSubobject<USceneComponent>(TEXT("PickupRoot"));
	RootComponent = PickupRoot;

	PickupMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PickupMesh"));
	PickupMesh->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);

	PickupBox = CreateDefaultSubobject<UBoxComponent>(TEXT("PickupBox"));
	PickupBox->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f)); //can be edited in editor
	PickupBox->SetGenerateOverlapEvents(true);


	PickupBox->OnComponentBeginOverlap.AddDynamic(this, &APickup::OnPlayerEnterPickupBox);
	PickupBox->AttachToComponent(PickupRoot, FAttachmentTransformRules::SnapToTargetNotIncludingScale);
}

// Called when the game starts or when spawned
void APickup::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APickup::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APickup::OnPlayerEnterPickupBox(UPrimitiveComponent* OverlappedComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor->IsA(AMazeCharacter::StaticClass())) 
	{		
		ApplyEffects(Cast<AMazeCharacter>(OtherActor));
		UGameplayStatics::PlaySound2D(this, _pickupSound);

		UE_LOG(LogTemp, Log, TEXT("Pickup Collected! Destroying object"));
		Destroy(); //When walked into box, destroy the pickup
	} 
	else
		UE_LOG(LogTemp, Log, TEXT("Not player actor! DENIED!")); //If not player actor, stay the same
}

void APickup::ApplyEffects(AMazeCharacter*)
{
	UE_LOG(LogTemp, Log, TEXT("DEFAULT RESPONSE: Applying Effects!"));
}


