
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RotationActor.generated.h"

UCLASS()
class HW06_API ARotationActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ARotationActor();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Component")
	USceneComponent* RootScene;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Component")
	UStaticMeshComponent* StaticMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationValue")
	float RotationSpeed;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationValue")
	bool bRotateX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationValue")
	bool bRotateY;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationValue")
	bool bRotateZ;

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;

private:
	FRotator Rotation;

};
