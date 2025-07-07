#include "MovingActor.h"

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
	Direction = FVector::ZeroVector;
	bMoveX = false;
	bMoveY = false;
	bMoveZ = false;
}

void AMovingActor::BeginPlay()
{
	Super::BeginPlay();

	StartLocation = GetActorLocation();
	Direction = FVector(bMoveX ? 1.0f : 0.0f,
						bMoveY ? 1.0f : 0.0f,
						bMoveZ ? 1.0f : 0.0f);
}

void AMovingActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector CurrentLocation = GetActorLocation();
	CurrentLocation = CurrentLocation + (Direction * MoveSpeed * DeltaTime);
	
	if (FVector::Dist(StartLocation, CurrentLocation) >= MaxRange)
	{
		Direction *= -1;
	}
	
	SetActorLocation(CurrentLocation);
}
