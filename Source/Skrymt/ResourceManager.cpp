// Fill out your copyright notice in the Description page of Project Settings.

#include "ResourceManager.h"
#include "Building.h"
#include "SkrymtPlayerState.h"
#include "BuildingStructs.h"

void UResourceManager::EndOfDay()
{

}

void UResourceManager::CalculateTodaysResources(TArray<int32> TodaysProduction) // iFarmingPopulation, iGatheringPopulation, iHuntingPopulation, iWoodPopulation, iStonePopulation, iMiningPopulation, iMiningPopulation 
{
	FoodResource = FarmingBaseProduction * TodaysProduction[0] + GatheringBaseProduction * TodaysProduction[1] + HuntingBaseProduction * TodaysProduction[2] + FishingBaseProduction * TodaysProduction[3];
	OreResource = MiningOreBaseProduction * TodaysProduction[4];
	GoldResource = MiningGoldBaseProduction * TodaysProduction[5];
	StoneResource = QuarryingBaseProduction * TodaysProduction[6];
	WoodResource = ForestryBaseProduction * TodaysProduction[7];
	ScienceResource = ScienceBaseProduction * TodaysProduction[8];
}

TArray<int32> UResourceManager::GetTodaysResources()
{
	return TodaysResources;
}

void UResourceManager::SetTodaysResources()
{
	TodaysResources = { FoodResource, WoodResource, StoneResource, OreResource, GoldResource, ScienceResource };
}

int UResourceManager::GetFoodResource()
{
	return FoodResource;
}

int UResourceManager::GetWoodResource()
{
	return WoodResource;
}

int UResourceManager::GetStoneResource()
{
	return StoneResource;
}

int UResourceManager::GetOreResource()
{
	return OreResource;
}

int UResourceManager::GetGoldResource()
{
	return GoldResource;
}

int UResourceManager::GetScienceResource()
{
	return ScienceResource;
}

int UResourceManager::GetHousingResource()
{
	return Housing;
}

int UResourceManager::GetHappinessResource()
{
	return Happiness;
}

void UResourceManager::OnConstructedBuilding(ABuilding* ConstructedBuilding)
{
	uint8 BuildingResource = ConstructedBuilding->GetResourcePerWorker();
	if (ConstructedBuilding->GetResourceType() == ResourceTypes::FoodFarming)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add FarmingBaseProduction"));
		FarmingBaseProduction += BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::FoodGathering)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add GatheringBaseProduction"));
		GatheringBaseProduction += BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::FoodHunting)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add HuntingBaseProduction"));
		HuntingBaseProduction += BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::FoodFishing)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add FishingBaseProduction"));
		FishingBaseProduction += BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::OreMining)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add MiningOreBaseProduction"));
		MiningOreBaseProduction += BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::GoldMining)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add MiningGoldBaseProduction"));
		MiningGoldBaseProduction += BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::StoneMining)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add QuarryingBaseProduction"));
		QuarryingBaseProduction += BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::WoodForestry)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add ForestryBaseProduction"));
		ForestryBaseProduction += BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::Science)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add ScienceBaseProduction"));
		ScienceBaseProduction += BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::Happiness)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add Happiness"));
		Happiness += BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::Housing)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add Housing"));
		Housing += ConstructedBuilding->GetHousing();
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::Weapons)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add Farming Resource"));
		FarmingBaseProduction += BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::None)
	{
		UE_LOG(LogTemp, Warning, TEXT("In ConstructedBuilding, add Farming Resource"));
		FarmingBaseProduction += BuildingResource;
	}
}

void UResourceManager::RemoveProductionFromBuilding(ABuilding* ConstructedBuilding)
{
	uint8 BuildingResource = ConstructedBuilding->GetResourcePerWorker();
	if (ConstructedBuilding->GetResourceType() == ResourceTypes::FoodFarming)
	{
		FarmingBaseProduction -= BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::FoodGathering)
	{
		GatheringBaseProduction -= BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::FoodHunting)
	{
		HuntingBaseProduction -= BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::FoodFishing)
	{
		FishingBaseProduction -= BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::OreMining)
	{
		MiningOreBaseProduction -= BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::GoldMining)
	{
		MiningGoldBaseProduction -= BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::StoneMining)
	{
		QuarryingBaseProduction -= BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::WoodForestry)
	{
		ForestryBaseProduction -= BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::Science)
	{
		ScienceBaseProduction -= BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::Happiness)
	{
		Happiness -= BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::Housing)
	{
		Housing -= ConstructedBuilding->GetHousing();
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::Weapons)
	{
		FarmingBaseProduction -= BuildingResource;
	}
	else if (ConstructedBuilding->GetResourceType() == ResourceTypes::None)
	{
		FarmingBaseProduction -= BuildingResource;
	}
}