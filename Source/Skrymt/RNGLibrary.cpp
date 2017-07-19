// Fill out your copyright notice in the Description page of Project Settings.

#include "RNGLibrary.h"

// Random Integer
int32 URNGLibrary::RandomInt(int32 Min, int32 Max)
{
	return FMath::RandRange(Min, Max);
}
int32 URNGLibrary::RandomInt(int32 Max)
{
	return RandomInt(0, Max);
}
int32 URNGLibrary::RandomInt()
{
	return RandomInt(0, 1);
}
int32 URNGLibrary::RandomInt(int32 Seed, int32 Min, int32 Max)
{
	return FRandomStream(Seed).RandRange(Min, Max);
}
int32 URNGLibrary::RandomInt(int32 Seed, int32 Max)
{
	return RandomInt(Seed, 0, Max);
}
int32 URNGLibrary::RandomInt(int32 Seed)
{
	return RandomInt(Seed, 0, 1);
}

// Random Float
float URNGLibrary::RandomFloat(float Min, float Max)
{
	return FMath::FRandRange(Min, Max);
}
float URNGLibrary::RandomFloat(float Max)
{
	return RandomFloat(0, Max);
}
float URNGLibrary::RandomFloat()
{
	return RandomFloat(0, 1);
}
float URNGLibrary::RandomFloat(int32 Seed, float Min, float Max)
{
	return FRandomStream(Seed).FRandRange(Min, Max);
}
float URNGLibrary::RandomFloat(int32 Seed, float Max)
{
	return RandomFloat(Seed, 0, Max);
}
float URNGLibrary::RandomFloat(int32 Seed)
{
	return RandomFloat(Seed, 0, 1);
}

// Noise
float URNGLibrary::SimplexNoise(float x, float y, float z, float w)
{
	return 0.0f;
}
