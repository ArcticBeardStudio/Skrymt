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
	int iFoodResource;
	int iWoodResource;
	int iStoneResource;
	int iOreResource;
	int iGoldResource;

//The base production for each area of resource gathering
	float fFarmingBaseProduction = 1.0f;
	float fGatheringBaseProduction = 1.0f;
	float fHuntingBaseProduction = 1.0f;
	float fFishingBaseProduction = 1.0f;
	
	float fMiningOreBaseProduction = 1.0f;
	float fMiningGoldBaseProduction = 1.0f;
	
	float fQuarryingBaseProduction = 1.0f;
	
	float fForestryBaseProduction = 1.0f;

	TArray<int32> TodaysResources;

public:
	

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