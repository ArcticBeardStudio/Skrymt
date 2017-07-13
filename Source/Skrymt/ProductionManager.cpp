// Fill out your copyright notice in the Description page of Project Settings.

#include "ProductionManager.h"
#include <EngineGlobals.h>
#include <Runtime/Engine/Classes/Engine/Engine.h>


void UProductionManager::EndOfDay()
{

}

TArray<int32> UProductionManager::GetTodaysProduction()
{
	return TodaysProduction;
}

void UProductionManager::SetTodaysProduction()
{
	TodaysProduction = { iFarmingPopulation, iGatheringPopulation, iHuntingPopulation, iWoodPopulation, iStonePopulation, iMiningPopulation, iMiningPopulation };
}