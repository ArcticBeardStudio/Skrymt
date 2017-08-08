// Fill out your copyright notice in the Description page of Project Settings.

#include "SkrymtGameState.h"
#include "SkrymtPlayerState.h"
#include "ResourceManager.h"

void ASkrymtGameState::SkrymtGameState()
{
	UE_LOG(LogTemp, Warning, TEXT("Constructor game state"));
}

void ASkrymtGameState::BeginPlay()
{
	UE_LOG(LogTemp, Warning, TEXT("Begin play game state"));
	Super::BeginPlay();
}

//** Function called at the start of the day, updates the players resources
void ASkrymtGameState::StartDay()
{
	ASkrymtPlayerState* PlayerState = Cast<ASkrymtPlayerState>(GetWorld()->GetFirstPlayerController()->PlayerState);
	PlayerState->UpdateResources(PlayerState->ResourceManager->GetTodaysResources());
	Day++;

	OnStartDay.Broadcast();
}

//** Call this when "End day" button is pressed in the HUD. Determines whether we go to the next day or wave *//
bool ASkrymtGameState::EndDay()
{
	ASkrymtPlayerState* PlayerState = Cast<ASkrymtPlayerState>(GetWorld()->GetFirstPlayerController()->PlayerState);
	PlayerState->EndOfTheDay();

	return true;
	/*if(bGoToNextDay)
	{
		return true;
	}
	else
	{
		return false;
	}*/


	//return true;
	
}

//** Functions to start and end a wave *//
void ASkrymtGameState::StartWave()
{
	Wave++;
}

void ASkrymtGameState::EndWave()
{
	
}

//** Functions to return the current day and wave, used for HUD *//
int ASkrymtGameState::GetCurrentDay()
{
	return Day;
}

int ASkrymtGameState::GetCurrentWave()
{
	return Wave;
}


//**Instantiate which day and wave we want to play at *//
void ASkrymtGameState::InstantiateVariables(int StartDay, int StartWave)
{
	Day = StartDay;
	Wave = StartWave;
}