// Fill out your copyright notice in the Description page of Project Settings.


#include "PixiePanicCustomer.h"

#include "PixiePanicPlayerCharacter.h"
#include "Components/SphereComponent.h"
#include "Components/TextBlock.h"
#include "Components/WidgetComponent.h"
#include "Kismet/GameplayStatics.h"
#include "UI/PixiePanicCustomerWidget.h"


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
	Widget = CreateDefaultSubobject<UWidgetComponent>(TEXT("Widget"));
	Widget->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void APixiePanicCustomer::BeginPlay()
{
	Super::BeginPlay();

	Player = Cast<APixiePanicPlayerCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
	
	int32 Index = FMath::RandRange(0, static_cast<int32>(EPickableType::MAX) - 1);
	NeedType = static_cast<EPickableType>(Index);

	UPixiePanicCustomerWidget* CurrentWidget = Cast<UPixiePanicCustomerWidget>(Widget->GetWidget());
	if (IsValid(CurrentWidget))
	{
		const UEnum* EnumPtr = FindObject<UEnum>(ANY_PACKAGE, TEXT("EPickableType"), true);
		if (EnumPtr)
		{
			FString EnumName = EnumPtr->GetDisplayNameTextByValue(static_cast<int64>(NeedType)).ToString();
			CurrentWidget->ItemText->SetText(FText::FromString(EnumName));
		}
	}
}

// Called every frame
void APixiePanicCustomer::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Player)
	{
		FVector Direction = Player->GetActorLocation() - GetActorLocation();
		float RotationZ = FMath::Atan2(-Direction.X,Direction.Y);

		FRotator TarRotation = FMath::RadiansToDegrees(FRotator(0.0f,RotationZ,0.0f));
		FRotator NewRotation = FMath::RInterpTo(GetActorRotation(), TarRotation, DeltaTime, 5.0f);

		SetActorRotation(TarRotation);
		
	}
	
}

