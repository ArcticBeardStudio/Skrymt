// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#include "SkrymtCore.h"

ASkrymtGameModeBase* SkrymtCore::SkrymtGameMode;
ASkrymtPlayerState* SkrymtCore::SkrymtPlayerState;
ASkrymtGameState* SkrymtCore::SkrymtGameState;
USkrymtGameInstance* SkrymtCore::SkrymtGameInstance;

SkrymtCore::SkrymtCore()
{
}

SkrymtCore::~SkrymtCore()
{
}

ASkrymtGameModeBase* SkrymtCore::GetSkrymtGameMode()
{
	check(SkrymtGameMode != nullptr && "SkrymtGameMode is null")
	return SkrymtGameMode;
}

ASkrymtPlayerState* SkrymtCore::GetSkrymtPlayerState()
{
	check(SkrymtPlayerState != nullptr && "SkrymtPlayerState is null")
	return SkrymtPlayerState;
}

ASkrymtGameState* SkrymtCore::GetSkrymtGameState()
{
	check(SkrymtGameState != nullptr && "SkrymtGameState is null")
	return SkrymtGameState;
}

USkrymtGameInstance * SkrymtCore::GetSkrymtGameInstance()
{
	check(SkrymtGameInstance != nullptr && "SkrymtGameInstance is null")
	return SkrymtGameInstance;
}

void SkrymtCore::SetSkrymtGameMode(ASkrymtGameModeBase * NewGameMode)
{
	SkrymtGameMode = NewGameMode;
}

void SkrymtCore::SetSkrymtPlayerState(ASkrymtPlayerState * NewPlayerState)
{
	SkrymtPlayerState = NewPlayerState;
}

void SkrymtCore::SetSkrymtGameState(ASkrymtGameState * NewGameState)
{
	SkrymtGameState = NewGameState;
}

void SkrymtCore::SetSkrymtGameInstance(USkrymtGameInstance * NewGameInstance)
{
	SkrymtGameInstance = NewGameInstance;
}
