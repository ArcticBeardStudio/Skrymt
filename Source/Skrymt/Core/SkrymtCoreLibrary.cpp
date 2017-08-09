// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#include "SkrymtCoreLibrary.h"
#include "SkrymtCore.h"

ASkrymtGameModeBase* USkrymtCoreLibrary::GetSkrymtGameMode()
{
	return SkrymtCore::GetSkrymtGameMode();
}

ASkrymtPlayerState* USkrymtCoreLibrary::GetSkrymtPlayerState()
{
	return SkrymtCore::GetSkrymtPlayerState();
}

ASkrymtGameState* USkrymtCoreLibrary::GetSkrymtGameState()
{
	return SkrymtCore::GetSkrymtGameState();
}
