// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "DataLibrary.h"
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

	// Gets the data associated to the ability with the given name
	UFUNCTION(BlueprintCallable, Category = "Data Reader")
	static FAbilityData GetAbilityData(FName AbilityName)
	{
		return *static_cast<FAbilityData*>(GetData(AbilityName, ABILITY_PATH));
	};

	// Gets the data associated to the effect with the given name
	UFUNCTION(BlueprintCallable, Category = "Data Reader")
	static FEffectData GetEffectData(FName EffectName)
	{
		return *static_cast<FEffectData*>(GetData(EffectName, EFFECT_PATH));
	};

	UFUNCTION(BlueprintCallable, Category = "DataReader")
	static FActionData GetActionData(FName RowName);

	UFUNCTION(BlueprintCallable, Category = "DataReader")
	static FApplyEffectData GetApplyEffectData(FName RowName);

};
