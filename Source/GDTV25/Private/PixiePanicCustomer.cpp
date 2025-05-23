// Fill out your copyright notice in the Description page of Project Settings.


#include "PixiePanicCustomer.h"

#include "Components/SphereComponent.h"


// Sets default values
APixiePanicCustomer::APixiePanicCustomer()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	
	SkeletalMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("SkeletalMesh"));
	SkeletalMesh->SetupAttachment(RootComponent);
	
	Collision = CreateDefaultSubobject<USphereComponent>(TEXT("Collision"));
	Collision->SetupAttachment(SkeletalMesh);
	
}

// Called when the game starts or when spawned
void APixiePanicCustomer::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void APixiePanicCustomer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

