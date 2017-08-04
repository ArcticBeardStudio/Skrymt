// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Factories/Factory.h"
#include "SkrymtButtonStyleFactory.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API USkrymtButtonStyleFactory : public UFactory
{
	GENERATED_BODY()

public:
	USkrymtButtonStyleFactory(const FObjectInitializer& ObjectInitializer);
	virtual UObject* FactoryCreateNew(UClass* Class, UObject* InParent, FName Name, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};
