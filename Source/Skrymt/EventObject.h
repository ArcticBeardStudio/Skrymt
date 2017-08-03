// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EventLibrary.h"
#include "UObject/NoExportTypes.h"
#include "EventObject.generated.h"




/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class SKRYMT_API UEventObject : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadWrite, Category = "Event Object")
	FName ID;

	UPROPERTY(BlueprintReadWrite, Category = "Event Object")
	int32 Duration;

	UPROPERTY(BlueprintReadWrite, Category = "Event Object")
	int32 NumberOfChildren;

	UPROPERTY(BlueprintReadWrite, Category = "Event Object")
	TSet<FName> EffectTags;

	UPROPERTY(BlueprintReadWrite, Category = "Event Object")
	TSet<FName> TagsRecevied;

	UPROPERTY(BlueprintReadWrite, Category = "Event Object")
	TSet<FName> TagsLost;
	
	UPROPERTY(BlueprintReadWrite, Category = "Event Object")
	TArray<FName> Children;

	//TArray<EventOption> Options;

	UPROPERTY(BlueprintReadWrite, Category = "Event Object")
	bool bTriggered;

	UPROPERTY(BlueprintReadWrite, Category = "Event Object")
	bool bTerminated;

	UPROPERTY(BlueprintReadWrite, Category = "Event Object")
	bool bRandomChild;

	UEventObject();
	UEventObject(FName id, float duration, float numberofchildren, TSet<FName> effectTags, TSet<FName> tagsRecevied, TSet<FName> tagsLost, TArray<FName> children);

	/** Function called when the Event hasnt been triggered yet */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Event Object")
	void OnEffect();

	/** Function called when the Event is created*/
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Event Object")
	void OnStart();

	/** Function called when the Event is expired */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Event Object")
	void OnExpired();

	/** Function called to see if the event is triggered or is going to be triggered */
	UFUNCTION(BlueprintCallable, Category = "Event Object")
	virtual bool CheckIfTriggered();

	/** Function called to see if the event is triggered or is going to be triggered */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Event Object")
	bool CheckConditions();

	/** Function called when the event is triggered */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Event Object")
	void Trigger();

	/** Function called when the event is triggered */
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = "Event Object")
	void CreateEventUI();

	/** Function called when the event is terminated */
	UFUNCTION(BlueprintCallable, Category = "Event Object")
	virtual void Terminate();

	/** Function called when the event is Ticked, called each turn */
	UFUNCTION(BlueprintCallable, Category = "Event Object")
	virtual void TickEvent();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Event Object")
	virtual class ASkrymtPlayerState* GetPlayerState();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Event Object")
	virtual class APlayerController* GetFirstLocalPlayer();

	
};
