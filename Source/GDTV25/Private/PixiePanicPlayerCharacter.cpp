// Fill out your copyright notice in the Description page of Project Settings.


#include "GDTV25/Public/PixiePanicPlayerCharacter.h"

#include "PixiePanicPickables.h"
#include "GameFramework/CharacterMovementComponent.h"


// Sets default values
APixiePanicPlayerCharacter::APixiePanicPlayerCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = false;
	GetCharacterMovement()->bOrientRotationToMovement = false;
}

// Called when the game starts or when spawned
void APixiePanicPlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APixiePanicPlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	PlayerRotation(DeltaTime);
}

// Called to bind functionality to input
void APixiePanicPlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &APixiePanicPlayerCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APixiePanicPlayerCharacter::MoveRight);
	
	PlayerInputComponent->BindAction(TEXT("Jump"), EInputEvent::IE_Pressed, this, &APixiePanicPlayerCharacter::Throw);
}

void APixiePanicPlayerCharacter::PickUP(APixiePanicPickables* Pickable)
{
	CurrentPickable = Pickable;
	bIsPickingUp = true;
}

void APixiePanicPlayerCharacter::Throw()
{
	if (CurrentPickable)
	{
		bIsPickingUp = false;
		CurrentPickable->Throw();
	}
}

void APixiePanicPlayerCharacter::MoveForward(float axisValue)
{
	AddMovementInput(GetActorForwardVector() * axisValue);
	LastMovementInput.X = axisValue;
}

void APixiePanicPlayerCharacter::MoveRight(float axisValue)
{
	AddMovementInput(GetActorRightVector() * axisValue);
	LastMovementInput.Y = axisValue;
}

void APixiePanicPlayerCharacter::PlayerRotation(float DeltaTime)
{
	FVector Velocity = LastMovementInput;
	Velocity.Z = 0.f;

	if (!Velocity.IsNearlyZero())
	{
		float TargetYaw = FMath::RadiansToDegrees(FMath::Atan2(-Velocity.X, Velocity.Y));
		FRotator TargetRot= FRotator(0.f, TargetYaw, 0.f);
		FRotator SmoothRot = FMath::RInterpTo(GetMesh()->GetComponentRotation(), TargetRot, DeltaTime, 10.f);
		
		GetMesh()->SetWorldRotation(SmoothRot);
	}
}
