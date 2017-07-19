// Fill out your copyright notice in the Description page of Project Settings.

#include "ResourceManager.h"

void UResourceManager::EndOfDay()
{

}

void UResourceManager::CalculateTodaysResources(TArray<int32> TodaysProduction) // iFarmingPopulation, iGatheringPopulation, iHuntingPopulation, iWoodPopulation, iStonePopulation, iMiningPopulation, iMiningPopulation 
{
	iFoodResource = fFarmingBaseProduction * TodaysProduction[0] + fGatheringBaseProduction * TodaysProduction[1] + fHuntingBaseProduction * TodaysProduction[2];
	iWoodResource = fForestryBaseProduction * TodaysProduction[3];
	iStoneResource = fQuarryingBaseProduction * TodaysProduction[4];
	iOreResource = fMiningOreBaseProduction * TodaysProduction[5];
	iGoldResource = fMiningGoldBaseProduction * TodaysProduction[6];
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