// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ProductionManager.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API UProductionManager : public UObject
{
	GENERATED_BODY()
	
protected:
	//VARIABLES
//Variables to say how many citizens that is working on a specific area
	int SocialPopulation;
	int FarmingPopulation;		//Kommer att behövas splittas upp beroende på hur många olika sätt vi har att samla mat
	int GatheringPopulation;
	int HuntingPopulation;
	int FishingPopulation;
	int MiningOrePopulation;
	int MiningGoldPopulation;
	int QuarryingPopulation;
	int ForestryPopulation;
	int SciencePopulation;

	TArray<int32> TodaysProduction;
	
	UPROPERTY(BlueprintReadWrite)
	int PossibleCitizensForWork = 50;

public:
	/** Gets the amount of people working from the SOCIAL slider in production menu*/
	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void GetSocialPopulationFromGUI(int SliderValue) { SocialPopulation = SliderValue; };
	/** Gets the amount of people working from the FOOD slider in production menu*/
	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void GetFarmingPopulationFromGUI(int SliderValue) { FarmingPopulation = SliderValue; };
	/** Gets the amount of people working from the FOOD slider in production menu*/
	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void GetGatheringPopulationFromGUI(int SliderValue) { GatheringPopulation = SliderValue; };
	/** Gets the amount of people working from the FOOD slider in production menu*/
	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void GetHuntingPopulationFromGUI(int SliderValue) { HuntingPopulation = SliderValue; };
	/** Gets the amount of people working from the FOOD slider in production menu*/
	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void GetFishingPopulationFromGUI(int SliderValue) { FishingPopulation = SliderValue; };
	/** Gets the amount of people working from the MINING slider in production menu*/
	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void GetMiningOrePopulationFromGUI(int SliderValue) { MiningOrePopulation = SliderValue; };
	/** Gets the amount of people working from the MINING slider in production menu*/
	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void GetMiningGoldPopulationFromGUI(int SliderValue) { MiningGoldPopulation = SliderValue; };
	/** Gets the amount of people working from the WOOD slider in production menu*/
	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void GetQuarryingPopulationFromGUI(int SliderValue) { QuarryingPopulation = SliderValue; };
	/** Gets the amount of people working from the WOOD slider in production menu*/
	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void GetWoodPopulationFromGUI(int SliderValue) { ForestryPopulation = SliderValue; };
	/** Gets the amount of people working from the STONE slider in production menu*/
	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void GetStonePopulationFromGUI(int SliderValue) { SciencePopulation = SliderValue; };

	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void UpdatePossibleCitizensForWork(int SliderValue) { PossibleCitizensForWork = SliderValue; };

	/** Function called at the end of the day */
	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void EndOfDay();

	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		TArray<int32> GetTodaysProduction();

	UFUNCTION(BlueprintCallable, Category = "ProductionManager")
		void SetTodaysProduction();
};
