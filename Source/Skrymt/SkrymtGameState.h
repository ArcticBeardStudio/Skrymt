// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/GameStateBase.h"
#include "SkrymtGameState.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnStartDay);

/**
 * 
 */
UCLASS()
class SKRYMT_API ASkrymtGameState : public AGameStateBase
{
	GENERATED_BODY()
	
public:
	ASkrymtGameState(const FObjectInitializer &ObjectInitializer);

	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintAssignable, Category = "Skrymt Game State")
	FOnStartDay OnStartDay;

	UFUNCTION(BlueprintCallable, Category = "Skrymt Game State")
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
