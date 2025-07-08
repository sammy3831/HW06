#include "SpawnVolume.h"
#include "Components/BoxComponent.h"

ASpawnVolume::ASpawnVolume()
{
	PrimaryActorTick.bCanEverTick = false;

	RootScene = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(RootScene);

	SpawningBox = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	SpawningBox->SetupAttachment(RootScene);

	MaxSpawnCount = 10;
}

void ASpawnVolume::BeginPlay()
{
	Super::BeginPlay();

	for (int32 i = 0; i < MaxSpawnCount; i++)
	{
		SpawnActor();
	}
}

FVector ASpawnVolume::GetRandomLocation() const
{
	FVector BoxExtent = SpawningBox->GetScaledBoxExtent();
	FVector BoxCenter = SpawningBox->GetComponentLocation();

	return BoxCenter + FVector(FMath::FRandRange(-BoxExtent.X, BoxExtent.X),
	                           FMath::FRandRange(-BoxExtent.Y, BoxExtent.Y),
	                           FMath::FRandRange(-BoxExtent.Z, BoxExtent.Z));
}

TSubclassOf<AActor> ASpawnVolume::GetRandomActor() const
{
	if (SpawnActors.IsEmpty())
	{
		return nullptr;
	}

	int32 RandomIndex = FMath::RandRange(0, SpawnActors.Num() - 1);
	return SpawnActors[RandomIndex];
}

void ASpawnVolume::SpawnActor()
{
	TSubclassOf<AActor> ActorClass = GetRandomActor();

	if (ActorClass)
	{
		GetWorld()->SpawnActor<AActor>(ActorClass, GetRandomLocation(), FRotator::ZeroRotator);
	}
}
