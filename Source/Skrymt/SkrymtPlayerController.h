// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "SkrymtPlayerController.generated.h"

//My General Log
DECLARE_LOG_CATEGORY_EXTERN(MyLog, Log, All);

/**
 * 
 */
UCLASS()
class SKRYMT_API ASkrymtPlayerController : public APlayerController
{
	GENERATED_BODY()

public:

	ASkrymtPlayerController();

	/** Update Function, Called Every Frame */
	UFUNCTION()
	virtual void Tick(float deltaSeconds) override;

	//Called to add all selected actors to the actor array at the end of the selection
	UFUNCTION(BlueprintCallable, Category = "PlayerController")
	void AddActorsToArray(const TArray<AActor*> ActorArray);

	//Called to add all selected actors to the controlgroup chosen by the player
	UFUNCTION(BlueprintCallable, Category = "PlayerController")
	void SetControlGroup(const int Index);

	//Called when starting the selection to empty the actor array before the new selection
	UFUNCTION(BlueprintCallable, Category = "PlayerController")
	void RemoveActorsFromArray();

	//Returns the Array with all the selected actors
	UFUNCTION(BlueprintPure, Category = "PlayerController")
	TArray<AActor*> GetAllSelectedActors();

	//Returns the Array with all the selected actors in the controlgroup
	UFUNCTION(BlueprintPure, Category = "PlayerController")
	TArray<AActor*> GetControlgroup(const int Index);

protected:
	
	virtual void BeginPlay() override;

private:

	bool bIsSelecting;
	bool bCanMoveCamera;

	//All actors currently selected in the game
	TArray<AActor*> SelectedActors;
	
	//Arrays for controlgroups 1-9
	TArray<TArray<AActor*>> Controlgroups;

};