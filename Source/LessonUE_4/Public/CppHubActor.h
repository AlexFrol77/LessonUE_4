// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CppBaseActor.h"
#include "CppHubActor.generated.h"


UCLASS()
class LESSONUE_4_API ACppHubActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACppHubActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;



	FTimerHandle SpawnTimerHandle;
	FTimerHandle DestroyTimerHandle;

	void OnTimeToSpawn();
	void OnTimeToDestroy();

	const int32 TotalCount = 10;
	int32 CurrentTimerCount = 0;

	UPROPERTY()
	TArray<ACppBaseActor*> SpawnedObjects;

	UPROPERTY(EditAnywhere)
	TSubclassOf<ACppBaseActor> CppClass;

	UPROPERTY(EditAnywhere)
	float SpawnTimerRate = 2.0f;

	UPROPERTY(EditAnywhere)
	float DestroyTimerRate = 1.0f;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
