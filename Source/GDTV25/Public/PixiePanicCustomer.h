// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PixiePanicPickables.h"
#include "PixiePanicCustomer.generated.h"

class UWidgetComponent;
class USphereComponent;

UCLASS()
class GDTV25_API APixiePanicCustomer : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APixiePanicCustomer();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditDefaultsOnly)
	USkeletalMeshComponent *SkeletalMesh;
	UPROPERTY(EditDefaultsOnly)
	USphereComponent* Collision;
	UPROPERTY(EditDefaultsOnly)
	UWidgetComponent* Widget;

	EPickableType NeedType;

	class APixiePanicPlayerCharacter* Player;
	
};
