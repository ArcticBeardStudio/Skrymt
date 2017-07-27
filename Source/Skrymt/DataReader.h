// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "DataLibrary.h"
#include "EventLibrary.h"
#include "UObject/NoExportTypes.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "DataReader.generated.h"


#define ABILITY_PATH TEXT("/Game/Data/AbilityDataTable.AbilityDataTable")
#define EFFECT_PATH TEXT("/Game/Data/EffectDataTable.EffectDataTable")


/**
 * 
 */
UCLASS()
class SKRYMT_API UDataReader : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


public:

	// Base data getter function
	static FTableRowBase* GetData(FName Name, const TCHAR* Path);

	// Gets the data associated to the Ability with the given name
	UFUNCTION(BlueprintCallable, Category = "Data Reader")
	static FAbilityData GetAbilityData(FName AbilityName)
	{
		return *static_cast<FAbilityData*>(GetData(AbilityName, ABILITY_PATH));
	};

	// Gets the data associated to the Effect with the given name
	UFUNCTION(BlueprintCallable, Category = "Data Reader")
	static FEffectData GetEffectData(FName EffectName)
	{
		return *static_cast<FEffectData*>(GetData(EffectName, EFFECT_PATH));
	};
	// Gets the data associated to the Action with the given name
	UFUNCTION(BlueprintCallable, Category = "DataReader")
	static FActionData GetActionData(FName RowName);
	
	// Gets the data associated to the ApllyEffect with the given name
	UFUNCTION(BlueprintCallable, Category = "DataReader")
	static FApplyEffectData GetApplyEffectData(FName RowName);

	/** Function called when the event is created, reads the data for the event */
	UFUNCTION(BlueprintCallable, Category = "DataReader")
	static FEventInitiationData GetEventData(FName RowName);
};
