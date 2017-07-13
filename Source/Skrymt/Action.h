// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "DataLibrary.h"
#include "UObject/NoExportTypes.h"
#include "Action.generated.h"

/**
 * 
 */

UCLASS()
class SKRYMT_API UAction : public UObject
{
	GENERATED_BODY()

public:
	static void Execute(FName RowName, AActor* Target, AActor* Source);
	static void ApplyEffect(FActionData ActionData, AActor* Target, AActor* Source);
};
