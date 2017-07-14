// Fill out your copyright notice in the Description page of Project Settings.

#include "DayNightCycleGameState.h"

void ADayNightCycleGameState::StartDay()
{
	Day++;
}

//** Call this when "End day" button is pressed in the HUD. Determines whether we go to the next day or wave *//
bool ADayNightCycleGameState::EndDay()
{
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
void ADayNightCycleGameState::StartWave()
{
	Wave++;
}

void ADayNightCycleGameState::EndWave()
{
	
}

//** Functions to return the current day and wave, used for HUD *//
int ADayNightCycleGameState::GetCurrentDay()
{
	return Day;
}

int ADayNightCycleGameState::GetCurrentWave()
{
	return Wave;
}


//**Instantiate which day and wave we want to play at *//
void ADayNightCycleGameState::InstantiateVariables(int StartDay, int StartWave)
{
	Day = StartDay;
	Wave = StartWave;
}