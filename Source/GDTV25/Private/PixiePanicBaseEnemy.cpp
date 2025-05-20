// Fill out your copyright notice in the Description page of Project Settings.


#include "PixiePanicBaseEnemy.h"
#include "Components/CapsuleComponent.h"
#include "AIController.h"
#include "Blueprint/AIBlueprintHelperLibrary.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/PawnMovementComponent.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APixiePanicBaseEnemy::APixiePanicBaseEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessAI = EAutoPossessAI::PlacedInWorldOrSpawned;
	
	bUseControllerRotationYaw = false;
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
}

// Called when the game starts or when spawned
void APixiePanicBaseEnemy::BeginPlay()
{
	Super::BeginPlay();

	if (!Target)
	{
		Target = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
	}
	
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 160.f, 0.f);

	CurrentController = Cast<AAIController>(GetController());
}

void APixiePanicBaseEnemy::SetTarget(AActor* NewTarget)
{
	Target = NewTarget;
}

void APixiePanicBaseEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (!Target) {return;}
	
	CurrentController->MoveToActor(Target, 100,true,true,false);
}
