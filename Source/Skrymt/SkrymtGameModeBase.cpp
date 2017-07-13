// Fill out your copyright notice in the Description page of Project Settings.

#include "SkrymtGameModeBase.h"
#include "Blueprint/UserWidget.h"
#include "ProductionManager.h"
#include "ResourceManager.h"
#include "EventManager.h"




void ASkrymtGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	ProductionManager = NewObject<UProductionManager>(this);
	ResourceManager = NewObject<UResourceManager>(this);
	EventManager = NewObject<UEventManager>(this);

	WeatherTags = {};

	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void ASkrymtGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}
//Argument is a array where the indices are : { food, wood, stone, ore, gold }
void ASkrymtGameModeBase::UpdateResources(TArray<int32> Resources)
{
		
		iFoodResource = iFoodResource + Resources[0];
		iWoodResource = iWoodResource + Resources[1];
		iStoneResource = iStoneResource + Resources[2];
		iOreResource = iOreResource + Resources[3];
		iGoldResource = iGoldResource + Resources[4];
}

void ASkrymtGameModeBase::UpdateWeather(TSet<FName> NewWeatherTags)
{
	WeatherTags.Empty();
	WeatherTags = NewWeatherTags;
}


void ASkrymtGameModeBase::EndOfTheDay()
{
	ProductionManager->SetTodaysProduction();
	ResourceManager->CalculateTodaysResources(ProductionManager->GetTodaysProduction());
	ResourceManager->SetTodaysResources();
	this->UpdateResources(ResourceManager->GetTodaysResources());
	this->UpdateWeather(EventManager->GetNextWeatherFromDecider());
}