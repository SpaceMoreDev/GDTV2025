// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Trace/Detail/EventNode.h"
#include "PixiePanicPlayerCharacter.generated.h"


class APixiePanicPickables;

UCLASS()

class GDTV25_API APixiePanicPlayerCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APixiePanicPlayerCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	APixiePanicPickables* CurrentPickable;

	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void PickUP(APixiePanicPickables* Pickable);
	void Throw();

	UPROPERTY(BlueprintReadOnly, Category = "Animations")
	bool bIsPickingUp = false;
	
	FVector LastMovementInput = FVector::ZeroVector;
private:
	void MoveForward(float Value);
	void MoveRight(float Value);
	void PlayerRotation(float Dir);
};
