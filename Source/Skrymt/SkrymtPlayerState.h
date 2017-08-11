// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerState.h"
#include "SkrymtPlayerState.generated.h"

class ABuilding;
struct FBuildingData;
enum class EResourceTypes : uint8;
enum class EGatherTypes : uint8;

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
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skrymt Player State")
	int32 Population;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skrymt Player State")
	int32 MaxPopulation;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skrymt Player State")
	TMap<EGatherTypes, int32> Workers;
	TMap<EResourceTypes, TMap<EGatherTypes, int32>> Productions;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skrymt Player State")
	TMap<EResourceTypes, int32> Incomes;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Skrymt Player State")
	TMap<EResourceTypes, int32> Resources;

	UPROPERTY(BlueprintReadWrite)
	TSet<FName> WeatherTags;
	
	//FUNCTIONS
	//-----------------------------------------------------

	virtual void BeginPlay() override;

	//UFUNCTION(BlueprintCallable, Category = "GameManager")
	TSet<FName> GetWeatherTags() { return WeatherTags; };

	/** Function to change all resources*/
	UFUNCTION(BlueprintCallable, Category = "Player State")
	void AddResources(TArray<int32> Values);

	/** Function to change all resources when constructing building*/
	UFUNCTION(BlueprintCallable, Category = "Player State")
	void UpdateResourcesConstruct(TArray<int32> BuildingCost);

	/** Function to check if we have enough money to construct the building*/
	UFUNCTION(BlueprintCallable, Category = "Player State")
	bool CheckEnoughResources(TArray<int32> BuildingCost);

	/** Function to change all resources */
	//UFUNCTION(BlueprintCallable, Category = "GameManager")
	void UpdateWeather(TSet<FName> NewWeatherTags);

	UFUNCTION(BlueprintCallable, Category = "Player State")
	void EndOfTheDay();

	//MEMBERS
	//-----------------------------------------------------
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

	UFUNCTION()
	void BuildingConstructed(ABuilding* ConstructedBuilding);
};
