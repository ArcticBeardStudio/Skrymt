// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "BuildingStructs.h"
#include "Building.generated.h"


UENUM()
enum EBuildingStates
{
	Constructing,
	Complete,
};

UCLASS()
class SKRYMT_API ABuilding : public AActor
{
	GENERATED_BODY()

public:
	// Root Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	USceneComponent* Root;

	EBuildingStates State;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UBuildingManager* BuildingManager;

public:
	//constructor and initializer
	ABuilding(const FObjectInitializer& ObjectInitializer);

	// Called at the start of every day
	UFUNCTION(BlueprintNativeEvent, Category = "Building")
	void StartedDay();
};

