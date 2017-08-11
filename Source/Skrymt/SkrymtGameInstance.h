// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "SkrymtGameInstance.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API USkrymtGameInstance : public UGameInstance
{
	GENERATED_BODY()
	
public:
	USkrymtGameInstance(const FObjectInitializer & ObjectInitializer);

	UFUNCTION(BlueprintPure, Category = "Skrymt Game Instance")
	FText GetPlayerName(){ return PlayerName; }

	UFUNCTION(BlueprintPure, Category = "Skrymt Game Instance")
	FText GetTownName() { return TownName; }

	UFUNCTION(BlueprintCallable, Category = "Skrymt Game Instance")
	void SetPlayerName(FText NewPlayerName) { PlayerName = NewPlayerName; }

	UFUNCTION(BlueprintCallable, Category = "Skrymt Game Instance")
	void SetTownName(FText NewTownName) { TownName = NewTownName; }
	
	UFUNCTION(BlueprintCallable, Category = "Skrymt Game Instance")
	void SetFromMenu(bool bValue) { bFromMainMenu = bValue; }

	UFUNCTION(BlueprintPure, Category = "Skrymt Game Instance")
	bool GetFromMenu() { return bFromMainMenu; }

private:

	FText PlayerName;
	FText TownName;
	bool bFromMainMenu = false;
};
