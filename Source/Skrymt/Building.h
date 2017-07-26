// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Building.generated.h"

//Used to define which resource the building will produce
UENUM()
enum class ResourceTypes : uint8
{
	Gold,
	Wood,
	Stone,
	Ore,
	Food,
	Science,
	Happiness,
	Weapons,
	none
};

//BluePrintTable For information for buildings 
USTRUCT(Blueprintable)
struct FBuildingData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Housing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Garrison;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 ProductionNeeded;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		ResourceTypes ResourceType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 ResourcePerWorker;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		FString Mesh;
};

UCLASS()
class SKRYMT_API ABuilding : public AActor
{
	GENERATED_BODY()

public:
	// Mesh component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")

		UStaticMeshComponent * Tempmesh;
	//constructor and initializer
	ABuilding(const FObjectInitializer& ObjectInitializer)
		: Super(ObjectInitializer)
	{
		Tempmesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));

	}



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//UStaticMesh CurrentMesh;

	//Health Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Health;
	//Armor Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Armor;
	//Housing Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Housing;
	//Garrison Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Garrison;
	//Production Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 ProductionNeeded;
	//Production Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		ResourceTypes ResourceType;
	//Production Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 ResourcePerWorker;

public:

	//Function to handle construction of the Building
	UFUNCTION(BlueprintCallable)
		virtual void Construction(uint8 modifier);
	//Function to handle Production of the Building
	UFUNCTION(BlueprintCallable)
		virtual void Produce(uint8 modifier);
	//Function to handle Repairs of the Building
	UFUNCTION(BlueprintCallable)
		virtual void Repair(uint8 modifier);
	//Function to change mesh of the Building
	UFUNCTION(BlueprintCallable)
		void MeshChange(FString filepath);

	UFUNCTION(BlueprintCallable, Category = "Building")
	void SetVariables(uint8 NewHealth, uint8 NewArmor, uint8 NewHousing, uint8 NewGarrison, uint8 NewProductionNeeded, ResourceTypes NewResourceType, uint8 NewResourcePerWorker);
	



};

