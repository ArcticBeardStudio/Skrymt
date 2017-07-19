// Fill out your copyright notice in the Description page of Project Settings.

#include "EventDecider.h"
#include "SkrymtPlayerState.h"
#include "UnrealMathUtility.h"

FTableRowBase* UEventDecider::GetEventDeciderData(FName Name, const TCHAR* Path)
{
	UDataTable* DataTable = LoadObject<UDataTable>(NULL, Path, NULL, LOAD_None, NULL);
	FString ContextString;
	return DataTable->FindRow<FTableRowBase>(Name, ContextString);
}

UDataTable* UEventDecider::GetEventDeciders(const TCHAR* Path) 
{
	UDataTable* DataTable = LoadObject<UDataTable>(NULL, Path, NULL, LOAD_None, NULL);
	return DataTable;
}

void UEventDecider::CalculateEventDecidersWeigths(UDataTable* EventDeciderTable)
{
	FString ContextString;
	TArray<FName> RowNames;
	RowNames = EventDeciderTable->GetRowNames();

	for (auto& name : RowNames)
	{
		//UE_LOG(LogTemp, Warning, TEXT("Name of Weather: '%s'"), *name.ToString());
		FEventDeciderData* row = EventDeciderTable->FindRow<FEventDeciderData>(name, ContextString);
		if (row)
		{
			//UE_LOG(LogTemp, Warning, TEXT("Do We Get here!?"));
			int32 TotalEventWeight = 0;
			for (auto& ChanceTag : row->ChanceTags)
			{
				//UE_LOG(LogTemp, Warning, TEXT("Name of tags that give weight to weather: '%s'"), *ChanceTag.Key.ToString());
				ASkrymtPlayerState* PlayerState = GetTypedOuter<ASkrymtPlayerState>();
				//ASkrymtPlayerState* PlayerState = (ASkrymtPlayerState*)(GetWorld()->GetFirstPlayerController()->PlayerState);
				if (PlayerState->WeatherTags.Contains(FName(ChanceTag.Key)))
				{
					TotalEventWeight = TotalEventWeight + ChanceTag.Value;
				}
			}
			//UE_LOG(LogTemp, Warning, TEXT("Total weight: '%d'"), TotalEventWeight);
			Events.Add(name, TotalEventWeight);
		}
	}
}

FName UEventDecider::GetNextEvent() 
{
	int32 SumOfEventWeights = 0;
	FName ReturnName = FName("Raining");
	for (auto& Event : Events)
	{
		SumOfEventWeights = SumOfEventWeights + Event.Value;
	}

	int32 RandomIndex = FMath::RandRange(0, SumOfEventWeights);
	SumOfEventWeights = 0;
	for (auto& Event : Events)
	{
		SumOfEventWeights = SumOfEventWeights + Event.Value;
		if (SumOfEventWeights > RandomIndex)
		{
			ReturnName = Event.Key;
			break;
		}
	}
	return ReturnName;
}

FName UEventDecider::GetNextWeather()
{
	CalculateEventDecidersWeigths(GetEventDeciders(WEATHER_PATH));
	return GetNextEvent();
	//return FName("Raining");
}
