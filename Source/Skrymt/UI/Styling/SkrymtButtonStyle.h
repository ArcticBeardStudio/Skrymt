// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "SkrymtButtonStyle.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class SKRYMT_API USkrymtButtonStyle : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Button Style")
	struct FButtonStyle Style;
};
