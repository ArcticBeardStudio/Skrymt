// Fill out your copyright notice in the Description page of Project Settings.

#include "EventManager.h"
#include "EventDecider.h"
#include "DataReader.h"

TSet<FName> UEventManager::GetNextWeatherFromDecider()
{
	EventDecider = NewObject<UEventDecider>(GetOuter());
	FName NewWeather = EventDecider->GetNextWeather();

	//if (NewWeather == FName("Raining"))
	//{
		//AddEvent(FName("BuildingAccident"));
	//}

	GEngine->AddOnScreenDebugMessage(10, 10.f, FColor::Emerald, FString::Printf(TEXT("Next weather is: '%s'"), *NewWeather.ToString()));

	UDataTable* DataTable = LoadObject<UDataTable>(NULL, TEXT("/Game/Data/Events/WeatherEventData.WeatherEventData"), NULL, LOAD_None, NULL);

	FString ContextString;
	FWeatherEventData* NewWeatherData = DataTable->FindRow<FWeatherEventData>(NewWeather, ContextString);

	return NewWeatherData->ReceivedTags;
}

void UEventManager::AddEvent(FName EventName)
{
	
	FString EventPath = "/Game/Blueprints/Events/" + EventName.ToString() + "." + EventName.ToString() + "_C";
	//UEventObject* Result = LoadObject<UEventObject>(NULL, TEXT("/Game/Blueprints/Events/BuildingAccident.BuildingAccident"));//, NULL, LOAD_None, NULL);
	//UClass* Result = FindObject<UClass>(ClassPackage, TEXT("/Game/Blueprints/Events/BuildingAccident.BuildingAccident_C"));
	UClass* Result = StaticLoadClass(UEventObject::StaticClass(), NULL, *EventPath, NULL, LOAD_None, NULL);

	UEventObject* EventToAdd = NewObject<UEventObject>(this, Result);

	FEventInitiationData EventData = UDataReader::GetEventData(EventName);
	EventToAdd->ID = EventData.ID;
	EventToAdd->Duration = EventData.Duration;
	EventToAdd->NumberOfChildren = EventData.NumberOfChildren;
	EventToAdd->EffectTags = EventData.EffectTags;
	EventToAdd->TagsRecevied = EventData.TagsRecevied;
	EventToAdd->TagsLost = EventData.TagsLost;
	EventToAdd->Children = EventData.Children;
	this->EventQueue.Add(EventToAdd);
	EventToAdd->OnStart();
}

void UEventManager::UpdateEvents()
{
	//uint8 Len = EventQueue.Num();
	for (uint8 i = 0; i < this->EventQueue.Num(); ++i)
	{
		this->EventQueue[i]->TickEvent();
	}
}
