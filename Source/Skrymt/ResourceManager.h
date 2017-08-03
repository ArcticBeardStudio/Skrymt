// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResourceManager.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API UResourceManager : public UObject
{
	GENERATED_BODY()
	
protected:
	//VARIABLES
//Variables to that hold the count for a resource
	int FoodResource;
	int OreResource;
	int GoldResource;
	int StoneResource;
	int WoodResource;
	int Happiness;
	int Housing;
	int ScienceResource;

	//Food resource base productions
	float FarmingBaseProduction = 1.0f;
	float GatheringBaseProduction = 1.0f;
	float HuntingBaseProduction = 1.0f;
	float FishingBaseProduction = 1.0f;

	//Stone resource base productions
	float MiningOreBaseProduction = 1.0f;

	//Gold resource base productions
	float MiningGoldBaseProduction = 1.0f;
	
	//Ore resource base productions
	float QuarryingBaseProduction = 1.0f;
	
	//Wood resource base productions
	float ForestryBaseProduction = 1.0f;

	//Science resource base productions
	float ScienceBaseProduction = 1.0f;

	TArray<int32> TodaysResources;

public:
	
	//** Get functions for all resources **//
	UFUNCTION(BlueprintPure, Category = "ResourceManager")
		int GetFoodResource();
	UFUNCTION(BlueprintPure, Category = "ResourceManager")
		int GetWoodResource();
	UFUNCTION(BlueprintPure, Category = "ResourceManager")
		int GetStoneResource();
	UFUNCTION(BlueprintPure, Category = "ResourceManager")
		int GetOreResource();
	UFUNCTION(BlueprintPure, Category = "ResourceManager")
		int GetGoldResource();
	UFUNCTION(BlueprintPure, Category = "ResourceManager")
		int GetScienceResource();
	UFUNCTION(BlueprintPure, Category = "ResourceManager")
		int GetHousingResource();
	UFUNCTION(BlueprintPure, Category = "ResourceManager")
		int GetHappinessResource();
	/** Function called at the end of the day */
	UFUNCTION(BlueprintCallable, Category = "ResourceManager")
		void EndOfDay();

	UFUNCTION(BlueprintCallable, Category = "ResourceManager")
		void CalculateTodaysResources(TArray<int32> TodaysProduction);

	UFUNCTION(BlueprintCallable, Category = "ResourceManager")
		void SetTodaysResources();

	UFUNCTION(BlueprintCallable, Category = "ResourceManager")
		TArray<int32> GetTodaysResources();

	//Add the constructed building's resource to base production, ugly fix
	UFUNCTION(BlueprintCallable, Category = "ResourceManager")
	void OnConstructedBuilding(ABuilding* ConstructedBuilding);

	//Remove the constructed building's resource from base production, ugly fix
	UFUNCTION(BlueprintCallable, Category = "ResourceManager")
	void RemoveProductionFromBuilding(ABuilding* ConstructedBuilding);
};