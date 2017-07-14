// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameStateBase.h"
#include "DayNightCycleGameState.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API ADayNightCycleGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:

	UFUNCTION(BlueprintCallable, Category = "DayNightCycleStartDay")
	void StartDay();

	UFUNCTION(BlueprintCallable, Category="DayNightCycleEndDay")
	bool EndDay();

	UFUNCTION(BlueprintCallable, Category = "DayNightCycleStartWave")
	void StartWave();

	UFUNCTION(BlueprintCallable, Category = "DayNightCycleEndWave")
	void EndWave();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category="DayNightCycleGetCurrentDay")
	int GetCurrentDay();
	UFUNCTION(BlueprintCallable, BlueprintPure, Category ="DayNightCycleGetCurrentWave")
	int GetCurrentWave();

	UFUNCTION(BlueprintCallable, Category = "DayNightCycleInstantiateVariables")
	void InstantiateVariables(int StartDay, int StartWave);

protected:

	int Day;
	int Wave;

private:
	
	
};
