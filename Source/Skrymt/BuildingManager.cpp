// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#include "BuildingManager.h"
#include "Building.h"

bool UBuildingManager::StartConstruction(FName Name, FVector Location)
{
	this->GetTypedOuter<ASkrymtPlayerState>()->SpawnActor()
}

void UBuildingManager::AddBuilding(ABuilding* building)
{
	Buildings.Add(building);
}

void UBuildingManager::RemoveBuildingFromArray(ABuilding* building)
{
	if (Buildings.Contains(building))
	{
		Buildings.Remove(building);
	}
}

TArray<ABuilding*> UBuildingManager::GetBuildingsOfType(ResourceTypes ResourceType)
{
	TArray<ABuilding*> NewList;
	for (int i = 0; i < Buildings.Num(); i++)
	{
		if (Buildings[i]->GetResourceType() == ResourceType)
		{
			NewList.Add(Buildings[i]);
		}
	}
	return NewList;
}

TArray<ABuilding*> UBuildingManager::GetBuildingsConstructing()
{
	TArray<ABuilding*> NewList;
	for (int i = 0; i < Buildings.Num(); i++)
	{
		if (Buildings[i]->CheckComplete() == false)
		{
			NewList.Add(Buildings[i]);
		}
	}
	return NewList;
}

void UBuildingManager::Constructed()
{
	//When the building is constructed, add it's resources to ResourceManager baseproduction
}