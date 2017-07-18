// Fill out your copyright notice in the Description page of Project Settings.

#include "RNGLibrary.h"

// Random Integer
int32 URNGLibrary::RandomInt(int32 Min, int32 Max)
{
	return FMath::RandRange(Min, Max);
}
int32 URNGLibrary::RandomInt(int32 Max)
{
	return FMath::RandRange(0, Max);
}
int32 URNGLibrary::RandomInt()
{
	return FMath::RandRange(0, 1);
}

// Random Float
float URNGLibrary::RandomFloat(float Min, float Max)
{
	return FMath::FRandRange(Min, Max);
}
float URNGLibrary::RandomFloat(float Max)
{
	return FMath::FRandRange(0, Max);
}
float URNGLibrary::RandomFloat()
{
	return FMath::FRand();
}

// Noise
float URNGLibrary::SimplexNoise(float x, float y, float z, float w)
{
	return 0.0f;
}
