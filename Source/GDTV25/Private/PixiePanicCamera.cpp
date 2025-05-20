// Fill out your copyright notice in the Description page of Project Settings.


#include "PixiePanicCamera.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/Character.h"
#include "Kismet/GameplayStatics.h"

// Sets default values
APixiePanicCamera::APixiePanicCamera()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	CameraContainer = CreateDefaultSubobject<USceneComponent>("CameraContainer");
	RootComponent = CreateDefaultSubobject<USceneComponent>("Root");;
	
	CameraContainer->SetupAttachment(RootComponent);
	
	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComponent");
	CameraComp->SetupAttachment(CameraContainer);

	CameraComp->bUsePawnControlRotation = true;
}

// Called when the game starts or when spawned
void APixiePanicCamera::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void APixiePanicCamera::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!FollowTarget || !CameraComp){ return; }
	
	FVector LookDir = FollowTarget->GetActorLocation() - GetActorLocation();
	FRotator TargetRotation = LookDir.Rotation();
	FRotator CurrentRotation = CameraContainer->GetComponentRotation();
	
	FRotator NewRotation = FMath::RInterpTo(CurrentRotation, TargetRotation, DeltaTime, RotationSpeed);
	NewRotation.Yaw = 0;
	NewRotation.Roll = 0;
	
	CameraContainer->SetWorldRotation(NewRotation);
	
	float NewY;
	if (FollowTarget->GetActorLocation().Y > GetActorLocation().Y + HorizontalThreshold
		|| FollowTarget->GetActorLocation().Y < GetActorLocation().Y - HorizontalThreshold )
	{
		TargetY = FollowTarget->GetActorLocation().Y;
	}
	
	NewY = FMath::FInterpTo(GetActorLocation().Y,TargetY,DeltaTime,MovementSpeed);

	FVector NewLocation = GetActorLocation();
	NewLocation.Y = NewY;
	
	SetActorLocation(NewLocation);
}

void APixiePanicCamera::SetTarget(APawn* Target)
{
	FollowTarget = Target;
	
	FVector LookDir = FollowTarget->GetActorLocation() - GetActorLocation();
	FRotator TargetRotation = LookDir.Rotation();
	CameraContainer->SetWorldRotation(TargetRotation);
}