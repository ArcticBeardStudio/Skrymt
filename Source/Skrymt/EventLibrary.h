// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "UObject/NoExportTypes.h"
#include "EventLibrary.generated.h"


USTRUCT(BlueprintType)
struct FEventDeciderData : public FTableRowBase
{
	GENERATED_BODY()

	// Base Value For Weather
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weather Event")
	int32 BaseValue;
	
	// Tags Required for the event to trigger
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weather Event")
	TSet<FName> RequiredTags;

	// Tags that give weight to the event
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weather Event")
	TMap<FName, int32> ChanceTags;

	// Tags that exclude the event if triggered
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weather Event")
	TMap<FName, int32> ExcludedTags;

	// Number of times an event can be called
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weather Event")
	float NumberOfCalls;
};

USTRUCT(BlueprintType)
struct FWeatherEventData : public FTableRowBase
{
	GENERATED_BODY()

	// Tags that exclude the event if triggered
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Weather Event")
	TSet<FName> ReceivedTags;
};

//Data that contains all information showed on the buttons inside a Event pop-up
USTRUCT(BlueprintType)
struct FEventOptionData : public FTableRowBase
{
	GENERATED_BODY()

	// UI text for the Title
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Option Data")
	FText Title;

	// UI text for the Description
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Option Data")
	FText Description;

	// UI text for the Cost
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Option Data")
	FText Cost;
	
	// Events that get triggered by this option
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Option Data")
	TArray<FName> TriggeredEvents;
};

//Data that contains all information showed on the Event pop-up
USTRUCT(BlueprintType)
struct FEventDescriptionData : public FTableRowBase
{
	GENERATED_BODY()

	// UI text for the Title
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Description Data")
	FText Title;

	// UI text for the Description
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Description Data")
	FText Description;

	// UI text for the Cost
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Description Data")
	FText Cost;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Description Data")
	FName ImagePath;

	// Events that get triggered by this option
	//UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Option Data")
	//TArray<FName> Children;
};

//Data that contains all the variables for the event
USTRUCT(BlueprintType)
struct FEventInitiationData : public FTableRowBase
{
	GENERATED_BODY()

	//Name of the event
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Initiation Data")
	FName ID;

	//Duration for how long the event shoul be active
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Initiation Data")
	int32 Duration;

	//Number of Children an event has
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Initiation Data")
	int32 NumberOfChildren;

	//Tags given to the world when the event is active
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Initiation Data")
	TSet<FName> EffectTags;

	//Tags given to the world when the event is created
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Initiation Data")
	TSet<FName> TagsRecevied;

	//Tags given to the world when the event is terminated
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Initiation Data")
	TSet<FName> TagsLost;

	//Name of all the children the event have
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Event Initiation Data")
	TArray<FName> Children;
};

/**
 * 
 */
UCLASS()
class SKRYMT_API UEventLibrary : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
