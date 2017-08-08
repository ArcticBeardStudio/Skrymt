// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "UObject/NoExportTypes.h"
#include "DataLibrary.generated.h"

/*********
* GLOBAL *
*********/

UENUM(BlueprintType)
enum class EResourceTypes : uint8
{
	Food,
	Wood,
	Stone,
	Ore,
	Gold
};

/*****************
* ABILITY SYSTEM *
*****************/

UENUM(BlueprintType)
enum class ETargetTypes : uint8
{
	TargetActor,
	TargetLocation,
	SourceActor,
	SourceLocation
};

USTRUCT(BlueprintType)
struct FAbilityData : public FTableRowBase
{
	GENERATED_BODY()

	// Name of the effect to use as cooldown
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability")
	FName Cooldown;

	// Name of the action to use as cost
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability")
	FName Cost;

	// Name of the action to use when ability is activated
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability")
	FName Action;
};

UENUM(BlueprintType)
enum class EActionTypes : uint8
{
	ApplyEffect,
	ActionSet,
	RemoveEffect,
	ModifyPlayer
};

USTRUCT(Blueprintable)
struct FActionData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionData")
	EActionTypes ActionType;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionData")
	FName ActionTypeName;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionData")
	float HitChance;
};

USTRUCT(Blueprintable)
struct FApplyEffectData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionData")
	int32 Stacks;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "ActionData")
	FName Effect;
};

USTRUCT(BlueprintType)
struct FEffectData : public FTableRowBase
{
	GENERATED_BODY()

	// Time before effect expires
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effect")
	float Duration;

	// Tags given by a Effect
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Effect")
	TSet<FName> ReceivedTags;
};

/******************
* BUILDING SYSTEM *
******************/

USTRUCT(BlueprintType)
struct FBuildingData : public FTableRowBase
{
	GENERATED_BODY()
	
	//Health Variable
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building")
	int32 Health;
	//Armor Variable
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building")
	int32 Armor;
	//Housing Variable
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building")
	int32 Housing;
	//Garrison Variable
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building")
	int32 Garrison;
	//Number of days for complete the building
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building")
	int32 ConstructionTime;
	//How many workers that can work in the building
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building")
	int32 MaxWorkers;
	//How many resources this building will add per worker
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building")
	TMap<EResourceTypes, int32>  ResourcePerWorker;
	//How much the building costs to build
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Building")
	TMap<EResourceTypes, int32> Cost;
};

/**
 * 
 */
UCLASS()
class SKRYMT_API UDataLibrary : public UObject
{
	GENERATED_BODY()
	
	
	
	
};
