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
	int WoodResource;
	int StoneResource;
	int OreResource;
	int GoldResource;

//The base production for each area of resource gathering
	float FarmingBaseProduction = 1.0f;
	float GatheringBaseProduction = 1.0f;
	float HuntingBaseProduction = 1.0f;
	float FishingBaseProduction = 1.0f;
	
	float MiningOreBaseProduction = 1.0f;
	float MiningGoldBaseProduction = 1.0f;
	
	float QuarryingBaseProduction = 1.0f;
	
	float ForestryBaseProduction = 1.0f;

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

	/** Function called at the end of the day */
	UFUNCTION(BlueprintCallable, Category = "ResourceManager")
		void EndOfDay();

	UFUNCTION(BlueprintCallable, Category = "ResourceManager")
		void CalculateTodaysResources(TArray<int32> TodaysProduction);

	UFUNCTION(BlueprintCallable, Category = "ResourceManager")
		void SetTodaysResources();

	UFUNCTION(BlueprintCallable, Category = "ResourceManager")
		TArray<int32> GetTodaysResources();
};