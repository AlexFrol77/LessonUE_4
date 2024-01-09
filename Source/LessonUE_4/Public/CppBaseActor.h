// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.generated.h"

UENUM(BlueprintType)
enum class EMovementState : uint8
{
	Mobility,
	Static
};

USTRUCT(BlueprintType)
struct FTransformStruct
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentLocation = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FRotator CurrentRotation = FRotator::ZeroRotator;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FVector CurrentScale = FVector(1.0f, 1.0f, 1.0f);
};

UCLASS()
class LESSONUE_4_API ACppBaseActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACppBaseActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	int EnemyNum = 20;

	UPROPERTY(VisibleDefaultsOnly)
	float CurrentHealth = 57.54687;

	UPROPERTY(VisibleAnywhere)
	bool IsLive = true;

	UPROPERTY(EditAnywhere)
	FString PlayerName = "Netologiy";

	UFUNCTION(BlueprintCallable)
	void ShowInformation();

	UFUNCTION(BlueprintCallable)
	float SinMovement();

	UPROPERTY(EditAnywhere)
	float Amplitude = 70.0f;

	UPROPERTY(EditAnywhere)
	float Frequency = 4.0f;


	UPROPERTY(VisibleAnywhere)
	FVector InitialLocation;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Mesh;

private:


};
