#include "MovingActor.h"

#include "VectorTypes.h"

AMovingActor::AMovingActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RootScene);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootScene);

	MoveSpeed = 100.0f;
	MaxRange = 500.0f;
	StartLocation = FVector::ZeroVector;
	TargetLocation = FVector::ZeroVector;
	Direction = FVector::ZeroVector;
	bMoveX = false;
	bMoveY = false;
	bMoveZ = false;
	bMoveTimer = false;
	MovingDistance = 0.0f;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	Direction = FVector(bMoveX ? 1.0f : 0.0f,
	                    bMoveY ? 1.0f : 0.0f,
	                    bMoveZ ? 1.0f : 0.0f).GetSafeNormal();
	TargetLocation = StartLocation + Direction * MaxRange;
	MovingDistance = (TargetLocation - StartLocation).Size();
	
	if (bMoveTimer)
	{
		GetWorld()->GetTimerManager().SetTimer(ChangeSpeedTimerHandle, this,
		                                       &AMovingActor::ChangeRandomSpeed, 5.0f, true);
	}
}

void AMovingActor::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation += Direction * MoveSpeed * DeltaTime;
	SetActorLocation(CurrentLocation);

	float Distance = (CurrentLocation - StartLocation).Size();
	if (Distance > MovingDistance)
	{
		Direction *= -1.0f;

		FVector temp = StartLocation;
		StartLocation = TargetLocation;
		TargetLocation = temp;
	}
}

void AMovingActor::ChangeRandomSpeed()
{
	MoveSpeed = FMath::FRandRange(50.0f, 200.0f);
}