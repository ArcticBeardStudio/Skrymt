// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "SkrymtCoreLibrary.generated.h"

class ASkrymtGameModeBase;
class ASkrymtPlayerState;
class ASkrymtGameState;
class USkrymtGameInstance;

/**
 * 
 */
UCLASS()
class SKRYMT_API USkrymtCoreLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Skrymt")
	static ASkrymtGameModeBase* GetSkrymtGameMode();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Skrymt")
	static ASkrymtPlayerState* GetSkrymtPlayerState();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Skrymt")
	static ASkrymtGameState* GetSkrymtGameState();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Skrymt")
	static USkrymtGameInstance* GetSkrymtGameInstance();
};
