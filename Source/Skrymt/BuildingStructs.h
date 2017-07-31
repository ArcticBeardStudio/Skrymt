#pragma once
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "BuildingStructs.generated.h"

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
		uint8 DaysToComplete;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 MaxWorkerInBuilding;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		ResourceTypes ResourceType;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 ResourcePerWorker;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		FString Mesh;
};