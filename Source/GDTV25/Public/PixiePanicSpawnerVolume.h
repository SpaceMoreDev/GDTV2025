// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GameFramework/Volume.h"
#include "PixiePanicSpawnerVolume.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class GDTV25_API APixiePanicSpawnerVolume : public AActor
{
	GENERATED_BODY()
public:
	APixiePanicSpawnerVolume();

protected:
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn;

	UPROPERTY(EditAnywhere, Category = "Debug")
	bool bShowDebug = false;
	
	UPROPERTY(EditAnywhere, Category = "Spawning")
	float SpawnRadius = 900.f;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	float SpawnInterval = 2.f;

	UPROPERTY(EditAnywhere, Category = "Spawning")
	bool bHasLimit = true;
	
	UPROPERTY(EditAnywhere, Category = "Spawning")
	int SpawnLimit = 10;
	
private:
	FTimerHandle SpawnTimerHandle;
	FVector Center;
	int SpawnCount = 0;
	
	void SpawnActorInCircle();
	void UpdateVolumeSize();
	void Reset(int NewLimit);
};

