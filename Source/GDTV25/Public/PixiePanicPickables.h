// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PixiePanicPickables.generated.h"


UENUM()
enum class EPickableType
{
	Fish      UMETA(DisplayName = "Fish"),
	Sandwich  UMETA(DisplayName = "Sandwich"),
	Cheese	  UMETA(DisplayName = "Cheese"),
	MAX       UMETA(Hidden)
	
};

class USphereComponent;
class APixiePanicPlayerCharacter;
UCLASS()
class GDTV25_API APixiePanicPickables : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	APixiePanicPickables();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	UPROPERTY(Transient)
	APixiePanicPlayerCharacter* Player;
	
	UFUNCTION()
	void Collect(UPrimitiveComponent* OverlappedComponent,
	             AActor* OtherActor,
	             UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

	FTimerHandle ThrownTimer;
	
public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION()
	void Throw();
	UFUNCTION()
	void Reset();

	bool bIsPicked = false;
	bool bIsThrowing = false;
	
	UPROPERTY(EditAnywhere)
	UMeshComponent* MeshComp;
	UPROPERTY(EditAnywhere)
	USphereComponent* SphereComp;
	
	UPROPERTY(EditAnywhere)
	EPickableType PickableType = EPickableType::Fish;
};
