// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PixiePanicBaseEnemy.generated.h"

class UCapsuleComponent;
class AAIController;
UCLASS()
class GDTV25_API APixiePanicBaseEnemy : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	APixiePanicBaseEnemy();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	void SetTarget(AActor* NewTarget);
	AAIController* CurrentController;
public:	

	virtual void Tick(float DeltaTime) override;
	
	UPROPERTY(EditAnywhere, Category="AI")
	float AcceptanceRadius = 100.f;
	AActor* Target = nullptr;
};
