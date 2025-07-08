#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SpawnVolume.generated.h"

class UBoxComponent;

UCLASS()
class HW06_API ASpawnVolume : public AActor
{
	GENERATED_BODY()

public:
	ASpawnVolume();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USceneComponent* RootScene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	UBoxComponent* SpawningBox;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnVolume")
	TArray<TSubclassOf<AActor>> SpawnActors;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnVolume")
	int32 MaxSpawnCount;

protected:
	virtual void BeginPlay() override;

private:
	FVector GetRandomLocation() const;
	TSubclassOf<AActor> GetRandomActor() const;
	void SpawnActor();
};
