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

/**
 * 
 */
UCLASS()
class SKRYMT_API UEventLibrary : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
