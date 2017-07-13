// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "EventLibrary.h"
#include "UObject/NoExportTypes.h"
#include "EventDecider.generated.h"


#define WEATHER_PATH TEXT("/Game/Data/Events/EventDeciderDatatable.EventDeciderDataTable")

/**
 * 
 */
UCLASS()
class SKRYMT_API UEventDecider : public UObject
{
	GENERATED_BODY()
	
public:
	//UDataTable* EventDeciderTable;
	UPROPERTY()
	TMap<FName, int32> Events;

	// Get New weather
	FName GetNextWeather();

	// Base decider getter function
	static UDataTable* GetEventDeciders(const TCHAR* Path);

	// Calculate weights for the events
	void CalculateEventDecidersWeigths(UDataTable* EventDeciderTable);
	// Get the next event
	FName GetNextEvent();

	// Base data getter function
	static FTableRowBase* GetEventDeciderData(FName Name, const TCHAR* Path);

	// Gets the data associated to the Weather Event with the given name
	UFUNCTION(BlueprintCallable, Category = "Event Decider")
	static FEventDeciderData GetWeatherEventDeciderData(FName WeatherName)
	{
		return *static_cast<FEventDeciderData*>(GetEventDeciderData(WeatherName, WEATHER_PATH));
	};
	
	
};
