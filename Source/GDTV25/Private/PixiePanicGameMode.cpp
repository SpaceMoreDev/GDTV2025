// Fill out your copyright notice in the Description page of Project Settings.


#include "PixiePanicGameMode.h"

#include "PixiePanicCamera.h"
#include "kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"


void APixiePanicGameMode::BeginPlay()
{
	Super::BeginPlay();
	if (UWorld* World = GetWorld())
	{
		FActorSpawnParameters SpawnParams;

		APlayerController* PlayerController = UGameplayStatics::GetPlayerController(GetWorld(), 0);
		APawn* PlayerTarget = PlayerController->GetPawn();
		FVector SpawnLocation = PlayerTarget->GetActorLocation() + CameraLocation;
		
		APixiePanicCamera* SpawnedCamera = World->SpawnActor<APixiePanicCamera>(APixiePanicCamera::StaticClass(), SpawnLocation, FRotator::ZeroRotator, SpawnParams);

		
		
		if (SpawnedCamera)
		{
			SpawnedCamera->SetTarget(PlayerTarget);
			SpawnedCamera->SetActorTickEnabled(true);
			PlayerController->SetViewTarget(SpawnedCamera);
			UE_LOG(LogTemp, Warning, TEXT("Spawned Camera"));
		}
	}
}
