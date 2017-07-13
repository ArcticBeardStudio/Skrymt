// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "DataLibrary.h"
#include "UObject/NoExportTypes.h"
#include "Ability.generated.h"

/**
 * 
 */


UCLASS()
class SKRYMT_API UAbility : public UObject
{
	GENERATED_BODY()


public:
	UPROPERTY(BlueprintReadOnly, Category = "AbilityData")
	FAbilityData Data;
	
	UFUNCTION(BlueprintCallable, Category = "Ability")
	void Initialize(FName AbilityName);

	UFUNCTION(BlueprintCallable, Category = "Ability")
	void Execute(AActor* Target, AActor* Source);
};
