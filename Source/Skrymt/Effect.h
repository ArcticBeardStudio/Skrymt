// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "DataLibrary.h"
#include "UObject/NoExportTypes.h"
#include "Effect.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API UEffect : public UObject
{
	GENERATED_BODY()
	
public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effect")
	FName Name;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effect")
	FEffectData Data;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effect")
	float ElapsedTime = 0.0;

	UFUNCTION(BlueprintCallable, Category = "Effect")
	void Initialize(FName EffectName);

	UFUNCTION(BlueprintCallable, Category = "Effect")
	void TickEffect(float DeltaTime);

	UFUNCTION(BlueprintCallable, Category = "Effect")
	void Expire();
	
	
};
