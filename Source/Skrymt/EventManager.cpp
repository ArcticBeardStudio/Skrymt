// Fill out your copyright notice in the Description page of Project Settings.

#include "EventManager.h"
#include "EventDecider.h"

TSet<FName> UEventManager::GetNextWeatherFromDecider()
{
	EventDecider = NewObject<UEventDecider>(GetOuter());
	FName NewWeather = EventDecider->GetNextWeather();

	GEngine->AddOnScreenDebugMessage(10, 10.f, FColor::Emerald, FString::Printf(TEXT("Next weather is: '%s'"), *NewWeather.ToString()));

	UDataTable* DataTable = LoadObject<UDataTable>(NULL, TEXT("/Game/Data/Events/WeatherEventData.WeatherEventData"), NULL, LOAD_None, NULL);

	FString ContextString;
	FWeatherEventData* NewWeatherData = DataTable->FindRow<FWeatherEventData>(NewWeather, ContextString);

	return NewWeatherData->ReceivedTags;
}


