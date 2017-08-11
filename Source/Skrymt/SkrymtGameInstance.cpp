// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#include "SkrymtGameInstance.h"
#include "Core/SkrymtCore.h"

USkrymtGameInstance::USkrymtGameInstance(const FObjectInitializer & ObjectInitializer)
	:Super(ObjectInitializer)
{
	SkrymtCore::SetSkrymtGameInstance(this);
	UE_LOG(LogTemp, Warning, TEXT("%s >> Constructor"), *GetName());
}
