// Fill out your copyright notice in the Description page of Project Settings.

#include "SkrymtPlayerState.h"
#include "ProductionManager.h"
#include "ResourceManager.h"
#include "EventManager.h"

void ASkrymtPlayerState::BeginPlay()
{
	Super::BeginPlay();
	ProductionManager = NewObject<UProductionManager>(this);
	ResourceManager = NewObject<UResourceManager>(this);
	EventManager = NewObject<UEventManager>(this);

	EventManager->OnEventTriggered.AddDynamic(this, &ASkrymtPlayerState::EventTriggered);
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

void ASkrymtPlayerState::EventTriggered_Implementation(UEventObject* EventObject)
{
	GEngine->AddOnScreenDebugMessage(20, 10.f, FColor::Red, FString::Printf(TEXT("Event '%s' added"), *EventObject->ID.ToString()));
}