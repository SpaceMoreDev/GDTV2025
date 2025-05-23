// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PixiePanicCamera.generated.h"

class APixiePanicPlayerCharacter;
class UCameraComponent;

UCLASS()
class GDTV25_API APixiePanicCamera : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APixiePanicCamera();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	
	UPROPERTY(EditDefaultsOnly)
	USceneComponent* CameraContainer;
	
	UPROPERTY(EditAnywhere, Category="Follow Options")
	float RotationSpeed = 2.0f;
	UPROPERTY(EditAnywhere, Category="Follow Options")
	float MovementSpeed = 1.5f;
	

	

	UPROPERTY(EditAnywhere, Category="Follow Options")
	APawn* FollowTarget;
	
	UPROPERTY(EditDefaultsOnly)
	UCameraComponent* CameraComp;
	float TargetY = 0;
	float TargetX = 0;
	

public:
	
	UPROPERTY(EditAnywhere, Category="Follow Options")
	float ForwardThreshold = 1500.0;
	
	UPROPERTY(EditAnywhere, Category="Follow Options")
	float HorizontalThreshold = 500.0f;
	
	void SetTarget(APawn* Target);
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	
};

