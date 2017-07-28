// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "EnvironmentQuery/EnvQueryContext.h"
#include "FindPlayerUnitQueryContext.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API UFindPlayerUnitQueryContext : public UEnvQueryContext
{
	GENERATED_BODY()
		virtual void ProvideContext(FEnvQueryInstance& QueryInstance, FEnvQueryContextData& ContextData) const override;
	
	
	
};
