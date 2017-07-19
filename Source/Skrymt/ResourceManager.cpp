// Fill out your copyright notice in the Description page of Project Settings.

#include "ResourceManager.h"

void UResourceManager::EndOfDay()
{

}

void UResourceManager::CalculateTodaysResources(TArray<int32> TodaysProduction) // iFarmingPopulation, iGatheringPopulation, iHuntingPopulation, iWoodPopulation, iStonePopulation, iMiningPopulation, iMiningPopulation 
{
	FoodResource = FarmingBaseProduction * TodaysProduction[0] + GatheringBaseProduction * TodaysProduction[1] + HuntingBaseProduction * TodaysProduction[2];
	WoodResource = ForestryBaseProduction * TodaysProduction[3];
	StoneResource = QuarryingBaseProduction * TodaysProduction[4];
	OreResource = MiningOreBaseProduction * TodaysProduction[5];
	GoldResource = MiningGoldBaseProduction * TodaysProduction[6];
}

TArray<int32> UResourceManager::GetTodaysResources()
{
	return TodaysResources;
}

void UResourceManager::SetTodaysResources()
{
	TodaysResources = { iFoodResource, iWoodResource, iStoneResource, iOreResource, iGoldResource };
}

int UResourceManager::GetFoodResource()
{
	return iFoodResource;
}

int UResourceManager::GetWoodResource()
{
	return iWoodResource;
}

int UResourceManager::GetStoneResource()
{
	return iStoneResource;
}

int UResourceManager::GetOreResource()
{
	return iOreResource;
}

int UResourceManager::GetGoldResource()
{
	return iGoldResource;
}