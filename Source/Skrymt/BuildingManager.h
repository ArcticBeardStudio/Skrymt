// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "BuildingManager.generated.h"

class ABuilding;
enum class EResourceTypes : uint8;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnConstructBuilding,ABuilding*,ConstructedBuilding);
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDestroyBuilding);

/**
 * 
 */
UCLASS()
class SKRYMT_API UBuildingManager : public UObject
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, Category = "BuildingManager")
	bool StartConstruction(FName Name, FVector Location);
	
	//When a building is being constructed, add it to the list of buildings
	UFUNCTION(BlueprintCallable, Category = "BuildingManager")
	void AddBuilding(ABuilding* building);

	//When a building is destroyed, call this function to remove the building from the list
	UFUNCTION(BlueprintCallable, Category = "BuildingManager")
	void RemoveBuildingFromArray(ABuilding* building);

	//Returns a list of all buildings with the searched resourcetype
	UFUNCTION(BlueprintCallable, Category = "BuildingManager")
	TArray<ABuilding*> GetBuildingsOfType(EResourceTypes ResourceType);

	//Returns a list of all buildings that is currently constructing
	UFUNCTION(BlueprintCallable, Category = "BuildingManager")
	TArray<ABuilding*> GetBuildingsConstructing();

	

	//When a building is constructed, call the function to add it's resource to the resourcemanager
	void Constructed();

	FOnConstructBuilding OnConstructBuilding;

protected:


private:
	TArray<ABuilding*> Buildings;
	
};
