// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "RNGLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API URNGLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Generates a random integer
	UFUNCTION(BlueprintCallable, Category = "RNG")
	static int32 RandomInt(int32 Min, int32 Max);
	static int32 RandomInt(int32 Max);
	static int32 RandomInt();

	// Generates a random float
	UFUNCTION(BlueprintCallable, Category = "RNG")
	static float RandomFloat(float Min, float Max);
	static float RandomFloat(float Max);
	static float RandomFloat();

	// Generates a random float
	UFUNCTION(BlueprintCallable, Category = "RNG")
	static float SimplexNoise(float x, float y, float z, float w);
};
