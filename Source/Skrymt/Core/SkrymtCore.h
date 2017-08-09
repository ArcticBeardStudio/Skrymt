// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

class ASkrymtGameModeBase;
class ASkrymtPlayerState;
class ASkrymtGameState;

/**
 * 
 */
class SKRYMT_API SkrymtCore
{
public:
	SkrymtCore();
	~SkrymtCore();

	static ASkrymtGameModeBase* GetSkrymtGameMode();
	static ASkrymtPlayerState* GetSkrymtPlayerState();
	static ASkrymtGameState* GetSkrymtGameState();

	static void SetSkrymtGameMode(ASkrymtGameModeBase* NewGameMode);
	static void SetSkrymtPlayerState(ASkrymtPlayerState* NewPlayerState);
	static void SetSkrymtGameState(ASkrymtGameState* NewGameState);

protected:
	static ASkrymtGameModeBase* SkrymtGameMode;
	static ASkrymtPlayerState* SkrymtPlayerState;
	static ASkrymtGameState* SkrymtGameState;
};
