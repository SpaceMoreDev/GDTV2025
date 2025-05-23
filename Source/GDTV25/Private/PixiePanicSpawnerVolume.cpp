// Fill out your copyright notice in the Description page of Project Settings.


#include "PixiePanicSpawnerVolume.h"

#include "DrawDebugHelpers.h"
#include "Components/BrushComponent.h"

APixiePanicSpawnerVolume::APixiePanicSpawnerVolume()
{
	PrimaryActorTick.bCanEverTick = false;
}

void APixiePanicSpawnerVolume::BeginPlay()
{
	Super::BeginPlay();
	
	Center = GetActorLocation();

	// UpdateVolumeSize();
	GetWorldTimerManager().SetTimer(SpawnTimerHandle, this, &APixiePanicSpawnerVolume::SpawnActorInCircle, SpawnInterval, true);
	if (bShowDebug)
	{
		DrawDebugCircle(GetWorld(),Center,SpawnRadius,128,FColor::Red,true,-1,0,5,
			FVector(0,1,0),
			FVector(1,0,0));
	}
}

void APixiePanicSpawnerVolume::SpawnActorInCircle()
{
	if (!ActorToSpawn) return;

	if (bHasLimit && SpawnCount >= SpawnLimit)
	{
		UE_LOG(LogTemp, Warning, TEXT("Timer stopped!"));
		GetWorldTimerManager().PauseTimer(SpawnTimerHandle);
		return;
	}

	if (bHasLimit)
	{
		SpawnCount++;
	}

	// Define inner exclusion zone (e.g., 100.f units)
	const float InnerExclusionRadius = 1000.f;

	// Get random radius between exclusion zone and spawn radius
	float Radius = FMath::FRandRange(InnerExclusionRadius, SpawnRadius);

	// Get random angle
	float Angle = FMath::FRandRange(0.f, 2 * PI);

	// Calculate position
	FVector SpawnOffset = FVector(FMath::Cos(Angle), FMath::Sin(Angle), 0.f) * Radius;
	FVector SpawnLocation = Center + SpawnOffset;

	// Spawn the actor
	FActorSpawnParameters Params;
	GetWorld()->SpawnActor<AActor>(ActorToSpawn, SpawnLocation, FRotator::ZeroRotator, Params);
}


void APixiePanicSpawnerVolume::Reset(int NewLimit = 10)
{
	SpawnLimit = NewLimit;
	SpawnCount = 0;
	
	GetWorldTimerManager().UnPauseTimer(SpawnTimerHandle);
	UE_LOG(LogTemp, Warning, TEXT("Timer started!"))
}