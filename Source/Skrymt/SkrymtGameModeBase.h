// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SkrymtGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API ASkrymtGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

protected:

	/** The widget class to use for our HUD screen */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		TSubclassOf<class UUserWidget> HUDWidgetClass;

	/** The instance of the HUD */
	UPROPERTY()
		class UUserWidget* CurrentWidget;




public:

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
	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	//UFUNCTION(BlueprintCallable, Category = "GameManager")
	TSet<FName> GetWeatherTags() { return WeatherTags; };

	/** Function to update the number of citizens */
	UFUNCTION(BlueprintCallable, Category = "GameManager")
	void UpdateNumberOfCitizens(int CitizenDifference) { iNumberOfCitizens = iNumberOfCitizens + CitizenDifference; };

	/** Function to update the number of vacant citizens */
	UFUNCTION(BlueprintCallable, Category = "GameManager")
	void UpdateNumberOfVacantCitizens(int VacantCitizenDifference) { iNumberOfVacantCitizens = VacantCitizenDifference; };

	/** Function to change all resources */
	UFUNCTION(BlueprintCallable, Category = "GameManager")
		void UpdateResources(TArray<int32> Resources);

	/** Function to change all resources */
	//UFUNCTION(BlueprintCallable, Category = "GameManager")
	void UpdateWeather(TSet<FName> NewWeatherTags);

	/** Helper function for end of the day */
	UFUNCTION(BlueprintCallable, Category = "GameManager")
		void EndOfTheDay();

	//MEMBERS
	//-----------------------------------------------------
	UPROPERTY(BlueprintReadOnly)
	class UProductionManager* ProductionManager;

	UPROPERTY(BlueprintReadOnly)
	class UResourceManager* ResourceManager;
	
	UPROPERTY(BlueprintReadOnly)
	class UEventManager* EventManager;
};
