// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingActor.generated.h"

UCLASS()
class HW06_API AMovingActor : public AActor
{
	GENERATED_BODY()

public:
	AMovingActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USceneComponent* RootScene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveValue")
	float MoveSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveValue")
	float MaxRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveValue")
	bool bMoveX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveValue")
	bool bMoveY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveValue")
	bool bMoveZ;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "MoveTimer")
	bool bMoveTimer;

	UFUNCTION(BlueprintCallable, Category = "Move")
	void ChangeRandomSpeed();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	FVector Direction;
	FTimerHandle ChangeSpeedTimerHandle;
	FVector StartLocation;
	FVector TargetLocation;
	float MovingDistance;
};
