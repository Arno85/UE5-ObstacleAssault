// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MovingPlatform.generated.h"

UCLASS()
class OBSTACLEASSAULT_API AMovingPlatform : public AActor
{
	GENERATED_BODY()

private:
	FVector StartLocation{};

	UPROPERTY(EditAnywhere, Category = "Moving Platform|Moving")
	FVector PlatformVelocity{0.0, 100.0, 0.0};

	UPROPERTY(EditAnywhere, Category = "Moving Platform|Moving")
	float MoveDistance{100.0};

	UPROPERTY(EditAnywhere, Category = "Moving Platform|Rotation")
	FRotator RotationVelocity{0.0, 0.0, 0.0};

public:
	AMovingPlatform();
	virtual void Tick(float DeltaTime) override;

protected:
	virtual void BeginPlay() override;

private:
	void MovePlatform(float DeltaTime);
	void RotatePlatform(float DeltaTime);
	bool ShouldPlatformReturn() const;
	float GetDistanceMoved() const;
};
