// Fill out your copyright notice in the Description page of Project Settings.

#include "SkrymtPlayerState.h"
#include "Core/SkrymtCore.h"
#include "ProductionManager.h"
#include "ResourceManager.h"
#include "EventManager.h"
#include "BuildingManager.h"
#include "SkrymtGameInstance.h"
#include "BuildingStructs.h"

ASkrymtPlayerState::ASkrymtPlayerState(const FObjectInitializer &ObjectInitializer)
	:Super(ObjectInitializer)
{
	SkrymtCore::SetSkrymtPlayerState(this);
}

void ASkrymtPlayerState::BeginPlay()
{
	Super::BeginPlay();
	ProductionManager = NewObject<UProductionManager>(this);
	ResourceManager = NewObject<UResourceManager>(this);
	EventManager = NewObject<UEventManager>(this);
	BuildingManager = NewObject<UBuildingManager>(this);

	BuildingManager->OnConstructBuilding.AddDynamic(ResourceManager, &UResourceManager::OnConstructedBuilding);
	EventManager->OnEventTriggered.AddDynamic(this, &ASkrymtPlayerState::EventTriggered);

	USkrymtGameInstance* SGI = Cast<USkrymtGameInstance>(GetGameInstance());
	if (SGI)
	{
		PlayerName = SGI->GetPlayerName();
		TownName = SGI->GetTownName();
		FString PN = PlayerName.ToString();
		UE_LOG(LogTemp, Log, TEXT("PlayerName: %s"), *PN);
		FString TN = TownName.ToString();
		UE_LOG(LogTemp, Log, TEXT("TownName: %s"), *TN);
		if (SGI->GetFromMenu())
		{
			//Spawn buildings
		}
	}
	
}

//Argument is a array where the indices are : { food, wood, stone, ore, gold }
void ASkrymtPlayerState::UpdateResources(TArray<int32> Resources)
{

	iFoodResource = iFoodResource + Resources[0];
	iWoodResource = iWoodResource + Resources[1];
	iStoneResource = iStoneResource + Resources[2];
	iOreResource = iOreResource + Resources[3];
	iGoldResource = iGoldResource + Resources[4];
}

void ASkrymtPlayerState::UpdateWeather(TSet<FName> NewWeatherTags)
{
	WeatherTags.Empty();
	WeatherTags = NewWeatherTags;
}

void ASkrymtPlayerState::EndOfTheDay()
{
	ProductionManager->SetTodaysProduction();
	ResourceManager->CalculateTodaysResources(ProductionManager->GetTodaysProduction());
	ResourceManager->SetTodaysResources();
	UpdateResources(ResourceManager->GetTodaysResources());
	UpdateWeather(EventManager->GetNextWeatherFromDecider());
	EventManager->UpdateEvents();
}

void ASkrymtPlayerState::UpdateResourcesConstruct(FBuildingCost BuildingCost)
{
	iFoodResource -= BuildingCost.FoodCost;
	iWoodResource -= BuildingCost.WoodCost;
	iStoneResource -= BuildingCost.StoneCost;
	iOreResource -= BuildingCost.OreCost;
	iGoldResource -= BuildingCost.GoldCost;
}

bool ASkrymtPlayerState::CheckEnoughResources(FBuildingCost BuildingCost)
{
	if (iFoodResource >= BuildingCost.FoodCost && iWoodResource >= BuildingCost.WoodCost && iStoneResource >= BuildingCost.StoneCost && iOreResource >= BuildingCost.OreCost && iGoldResource >= BuildingCost.GoldCost)
	{
		return true;
	}
	return false;	
}

void ASkrymtPlayerState::EventTriggered_Implementation(UEventObject* EventObject)
{
	GEngine->AddOnScreenDebugMessage(20, 10.f, FColor::Red, FString::Printf(TEXT("Event '%s' added"), *EventObject->ID.ToString()));
}