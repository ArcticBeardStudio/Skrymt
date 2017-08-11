// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Building.generated.h"

struct FBuildingData;

UENUM(BlueprintType)
enum class EBuildingState : uint8
{
	Constructing,
	Complete,
	Broken
};

UCLASS()
class SKRYMT_API ABuilding : public AActor
{
	GENERATED_BODY()

public:
	// Root Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	USceneComponent* Root;
	// Mesh Component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
	UStaticMeshComponent* Mesh;

	// NAME
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly, Category = "Building")
	FName BuildingName;

	// Holds the current state of the building
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building")
	EBuildingState State;

	// Holds the data associated with the building
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building")
	FBuildingData Data;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	class UBuildingManager* BuildingManager;

public:
	//constructor and initializer
	ABuilding(const FObjectInitializer& ObjectInitializer);

	void StartedDay();

	// Called at the start of every day
	UFUNCTION(BlueprintImplementableEvent, Category = "Building")
	void NewDay();
};

