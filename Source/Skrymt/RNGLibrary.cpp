// Fill out your copyright notice in the Description page of Project Settings.

#include "RNGLibrary.h"

/*****************************
* Standard Random Generation *
*****************************/

// Generates a random integer between min (inclusive) and max (inclusive)
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

// Generates a random float between min (inclusive) and max (inclusive)
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

// Generates a random float
float URNGLibrary::SimplexNoise(float x, float y, float z, float w)
{
	return 0.0f;
}

/***************************
* Seeded Random Generation *
***************************/

// Generates a random seeded integer between min (inclusive) and max (inclusive)
int32 URNGLibrary::RandomSeededInt(int32 Seed, int32 Min, int32 Max)
{
	return FRandomStream(Seed).RandRange(Min, Max);
}
int32 URNGLibrary::RandomSeededInt(int32 Seed, int32 Max)
{
	return RandomSeededInt(Seed, 0, Max);
}
int32 URNGLibrary::RandomSeededInt(int32 Seed)
{
	return RandomSeededInt(Seed, 0, 1);
}

// Generates a random seeded float between min (inclusive) and max (inclusive)
float URNGLibrary::RandomSeededFloat(int32 Seed, float Min, float Max)
{
	return FRandomStream(Seed).FRandRange(Min, Max);
}
float URNGLibrary::RandomSeededFloat(int32 Seed, float Max)
{
	return RandomSeededFloat(Seed, 0, Max);
}
float URNGLibrary::RandomSeededFloat(int32 Seed)
{
	return RandomSeededFloat(Seed, 0, 1);
}
