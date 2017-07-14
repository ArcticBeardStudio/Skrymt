// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "BreakfastReportBPLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API UBreakfastReportBPLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()


		//** Functions to get the current production *//
		UFUNCTION(BlueprintPure, Category = "BreakfastReport")
		static FText GetFoodProduction();
		
		UFUNCTION(BlueprintPure, Category = "BreakfastReport")
		static FText GetWoodProduction();

		UFUNCTION(BlueprintPure, Category = "BreakfastReport")
		static FText GetStoneProduction();
		
		UFUNCTION(BlueprintPure, Category = "BreakfastReport")
		static FText GetOreProduction();

		UFUNCTION(BlueprintPure, Category = "BreakfastReport")
		static FText GetGoldProduction();

		UFUNCTION(BlueprintPure, Category = "BreakfastReport")
		static FText GetWeather();
};
