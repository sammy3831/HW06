
#include "RotationActor.h"

ARotationActor::ARotationActor()
{
	PrimaryActorTick.bCanEverTick = true;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RootScene);

	StaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("StaticMesh"));
	StaticMesh->SetupAttachment(RootScene);

	RotationSpeed = 90.0f;
	bRotateX = false;
	bRotateY = false;
	bRotateZ = false;
}

void ARotationActor::BeginPlay()
{
	Super::BeginPlay();
	
	Rotation = FRotator(bRotateX ? RotationSpeed : 0.0f,
						bRotateY ? RotationSpeed : 0.0f,
						bRotateZ ? RotationSpeed : 0.0f);
}

void ARotationActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	StaticMesh->AddLocalRotation(Rotation * DeltaTime);
}

