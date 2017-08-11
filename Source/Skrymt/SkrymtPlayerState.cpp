// Fill out your copyright notice in the Description page of Project Settings.

#include "SkrymtPlayerState.h"
#include "Core/SkrymtCore.h"
#include "EventManager.h"
#include "Building.h"
#include "BuildingManager.h"
#include "SkrymtGameInstance.h"
#include "DataLibrary.h"

ASkrymtPlayerState::ASkrymtPlayerState(const FObjectInitializer &ObjectInitializer)
	:Super(ObjectInitializer)
{
	SkrymtCore::SetSkrymtPlayerState(this);
}

void ASkrymtPlayerState::BeginPlay()
{
	Super::BeginPlay();
	EventManager = NewObject<UEventManager>(this);
	BuildingManager = NewObject<UBuildingManager>(this);

	BuildingManager->OnConstructBuilding.AddDynamic(this, &ASkrymtPlayerState::BuildingConstructed);
	EventManager->OnEventTriggered.AddDynamic(this, &ASkrymtPlayerState::EventTriggered);

	USkrymtGameInstance* SGI = SkrymtCore::GetSkrymtGameInstance();
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

void ASkrymtPlayerState::UpdateWeather(TSet<FName> NewWeatherTags)
{
	WeatherTags.Empty();
	WeatherTags = NewWeatherTags;
}

void ASkrymtPlayerState::EndOfTheDay()
{
	UpdateWeather(EventManager->GetNextWeatherFromDecider());
	EventManager->UpdateEvents();
}

void ASkrymtPlayerState::BuildingConstructed(ABuilding * ConstructedBuilding)
{
	FBuildingData BuildingData = ConstructedBuilding->Data;
	for (auto& Elem : BuildingData.ResourcePerWorker)
	{
		TMap<EGatherTypes, int32>& GatherTypes = Productions.FindOrAdd(Elem.Key);
		int32& Value = GatherTypes.FindOrAdd(BuildingData.GatherType);
		Value += Elem.Value;
		UE_LOG(LogTemp, Warning, TEXT("Added base current value: %d, %d, %d"), (int32)Elem.Key, (int32)BuildingData.GatherType, Value);
	}
}

void ASkrymtPlayerState::AddResources(TArray<int32> Values)
{
	for (uint8 i = 0; i < Values.Num(); i++)
	{
		int32& Resource = Resources.FindOrAdd((EResourceTypes)i);
		Resource += Values[(int32)i];
	}
}

void ASkrymtPlayerState::UpdateResourcesConstruct(TArray<int32> BuildingCost)
{
	// TODO: Implement with current resource storage
}

bool ASkrymtPlayerState::CheckEnoughResources(TArray<int32> BuildingCost)
{
	// TODO: Implement with current resource storage


	if (true)
	{
		return true;
	}
	return false;	
}

void ASkrymtPlayerState::EventTriggered_Implementation(UEventObject* EventObject)
{
	GEngine->AddOnScreenDebugMessage(20, 10.f, FColor::Red, FString::Printf(TEXT("Event '%s' added"), *EventObject->ID.ToString()));
}