// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "EventLibrary.h"
#include "EventObject.h"
#include "UObject/NoExportTypes.h"
#include "EventManager.generated.h"

class UEventObject;

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnEventTriggered, UEventObject*, EventObject);

/**
 * 
 */
UCLASS()
class SKRYMT_API UEventManager : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly)
	TArray<class UEventObject*> EventQueue;



	UPROPERTY(BlueprintReadOnly)
	class UEventDecider* EventDecider;

	UFUNCTION(BlueprintCallable, Category = "EventManager")
	TSet<FName> GetNextWeatherFromDecider();

	UFUNCTION(BlueprintCallable, Category = "EventManager")
	void UpdateEvents();

	UFUNCTION(BlueprintCallable, Category = "EventManager")
	void AddEvent(FName EventName);
	FOnEventTriggered OnEventTriggered;
};
