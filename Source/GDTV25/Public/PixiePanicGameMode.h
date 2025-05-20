// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PixiePanicGameMode.generated.h"


class APixiePanicCamera;
/**
 * 
 */
UCLASS()
class GDTV25_API APixiePanicGameMode : public AGameModeBase
{
	GENERATED_BODY()


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="Setup")
	FVector CameraLocation = FVector(0, 0, 1500);
	
};
