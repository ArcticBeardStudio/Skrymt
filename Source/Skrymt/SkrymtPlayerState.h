// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SkrymtPlayerState.generated.h"

#define LOCTEXT_NAMESPACE "Namespace"

/**
 * 
 */
UCLASS()
class SKRYMT_API ASkrymtPlayerState : public APlayerState
{
	GENERATED_BODY()
	
private:

	FText PlayerName;// = LOCTEXT("PlayerName", "[Name]");
	FText TownName;// = LOCTEXT("TownName", "[TownName]");

public:
	ASkrymtPlayerState(const FObjectInitializer &ObjectInitializer);

	//VARIABLES
	//-----------------------------------------------------
	UPROPERTY(BlueprintReadWrite)
	int iNumberOfCitizens = 100;

	UPROPERTY(BlueprintReadWrite)
	int iNumberOfVacantCitizens = 50;

	UPROPERTY(BlueprintReadWrite)
	int iFoodResource = 50;

	UPROPERTY(BlueprintReadWrite)
	int iWoodResource = 50;

	UPROPERTY(BlueprintReadWrite)
	int iStoneResource = 50;

	UPROPERTY(BlueprintReadWrite)
	int iOreResource = 50;

	UPROPERTY(BlueprintReadWrite)
	int iGoldResource = 50;

	UPROPERTY(BlueprintReadWrite)
	TSet<FName> WeatherTags;
	
	//FUNCTIONS
	//-----------------------------------------------------

	virtual void BeginPlay() override;

	//UFUNCTION(BlueprintCallable, Category = "GameManager")
	TSet<FName> GetWeatherTags() { return WeatherTags; };

	/** Function to update the number of citizens */
	UFUNCTION(BlueprintCallable, Category = "Player State")
	void UpdateNumberOfCitizens(int CitizenDifference) { iNumberOfCitizens = iNumberOfCitizens + CitizenDifference; };

	/** Function to update the number of vacant citizens */
	UFUNCTION(BlueprintCallable, Category = "Player State")
	void UpdateNumberOfVacantCitizens(int VacantCitizenDifference) { iNumberOfVacantCitizens = iNumberOfVacantCitizens + VacantCitizenDifference; };

	/** Function to change all resources */
	UFUNCTION(BlueprintCallable, Category = "Player State")
	void UpdateResources(TArray<int32> Resources);

	/** Function to change all resources when constructing building*/
	UFUNCTION(BlueprintCallable, Category = "Player State")
	void UpdateResourcesConstruct(FBuildingCost BuildingCost);

	/** Function to check if we have enough money to construct the building*/
	UFUNCTION(BlueprintCallable, Category = "Player State")
	bool CheckEnoughResources(FBuildingCost BuildingCost);

	/** Function to change all resources */
	//UFUNCTION(BlueprintCallable, Category = "GameManager")
	void UpdateWeather(TSet<FName> NewWeatherTags);

	UFUNCTION(BlueprintCallable, Category = "Player State")
	void EndOfTheDay();

	//MEMBERS
	//-----------------------------------------------------
	UPROPERTY(BlueprintReadOnly)
	class UProductionManager* ProductionManager;

	UPROPERTY(BlueprintReadOnly)
	class UResourceManager* ResourceManager;

	UPROPERTY(BlueprintReadOnly)
	class UEventManager* EventManager;

	UPROPERTY(BlueprintReadOnly)
	class UBuildingManager* BuildingManager;

	UFUNCTION(BlueprintCallable, BlueprintNativeEvent, Category = "Player State")
	void EventTriggered(UEventObject* EventObject);

	UFUNCTION(BlueprintCallable, Category = "Player State")
	FString GetPlayerName() { return PlayerName.ToString(); };

	UFUNCTION(BlueprintCallable, Category = "Player State")
	FString GetTownName() { return TownName.ToString(); };


#undef LOCTEXT_NAMESPACE 
};
