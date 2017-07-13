// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "EventLibrary.h"
#include "UObject/NoExportTypes.h"
#include "EventManager.generated.h"


/**
 * 
 */
UCLASS()
class SKRYMT_API UEventManager : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
	class UEventDecider* EventDecider;

	UFUNCTION(BlueprintCallable, Category = "EventManager")
	TSet<FName> GetNextWeatherFromDecider();
};
