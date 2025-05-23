// Fill out your copyright notice in the Description page of Project Settings.


#include "PixiePanicPickables.h"

#include "PixiePanicPlayerCharacter.h"
#include "Components/SphereComponent.h"


// Sets default values
APixiePanicPickables::APixiePanicPickables()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	RootComponent = MeshComp;
	SphereComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	SphereComp->SetupAttachment(MeshComp);

	MeshComp->SetMobility(EComponentMobility::Movable);
	
	MeshComp->SetCollisionEnabled(ECollisionEnabled::QueryAndPhysics);
	MeshComp->SetCollisionObjectType(ECC_PhysicsBody);
	MeshComp->SetCollisionResponseToAllChannels(ECR_Block);
	MeshComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Ignore);
	
	SphereComp->SetCollisionEnabled(ECollisionEnabled::QueryOnly);
	SphereComp->SetCollisionResponseToAllChannels(ECR_Overlap);
	
	MeshComp->SetSimulatePhysics(true);
	SphereComp->SetGenerateOverlapEvents(true);
}


void APixiePanicPickables::BeginPlay()
{
	Super::BeginPlay();
	SphereComp->OnComponentBeginOverlap.AddDynamic(this,&APixiePanicPickables::Collect);
}

void APixiePanicPickables::Collect(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	if (!OtherActor->IsA(APixiePanicPlayerCharacter::StaticClass())) return;

	Player = Cast<APixiePanicPlayerCharacter>(OtherActor);
	
	if (Player->bIsPickingUp) {return;}
	if (bIsThrowing) {return;}
	
	Player->PickUP(this);

	
	bIsPicked = true;
	bIsThrowing = false;
	MeshComp->SetSimulatePhysics(false);
}

void APixiePanicPickables::Throw()
{
	if (bIsThrowing) {return;}
	
	bIsPicked = false;
	MeshComp->SetSimulatePhysics(true);
	
	if (Player)
	{
		MeshComp->SetPhysicsLinearVelocity(FVector::ZeroVector);
		MeshComp->SetPhysicsAngularVelocityInDegrees(FVector::ZeroVector);
		
		const FVector ThrowDirection = Player->GetMesh()->GetRightVector().GetSafeNormal();
		const float ThrowStrength = Player->GetVelocity().Size() + 1000.f;
		
		if (!ThrowDirection.IsNearlyZero())
		{
			MeshComp->AddImpulse(ThrowDirection * ThrowStrength, NAME_None, true);
		}
		else
		{
			UE_LOG(LogTemp, Warning, TEXT("ThrowDirection is zero! No impulse applied."));
		}
	}
	
	bIsThrowing = true;
	GetWorldTimerManager().SetTimer(ThrownTimer, this, &APixiePanicPickables::Reset, .5f, false);
}

void APixiePanicPickables::Reset()
{
	bIsThrowing = false;
}

void APixiePanicPickables::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
	if (bIsPicked)
	{
		if (Player)
		{
			FVector TargetLocation = Player->GetActorLocation() + FVector(0, 0, 200);
			FVector LerpLocation = FMath::VInterpTo(MeshComp->GetComponentLocation(), TargetLocation, DeltaTime, 10.0f);
			MeshComp->SetWorldLocation(LerpLocation);
		}
	}
}

