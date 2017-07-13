// Fill out your copyright notice in the Description page of Project Settings.

#include "Ability.h"
#include "Action.h"
#include "DataReader.h"

void UAbility::Initialize(FName AbilityName)
{
	Data = UDataReader::GetAbilityData(AbilityName);
}

void UAbility::Execute(AActor* Target, AActor* Source)
{
	UE_LOG(LogTemp, Warning, TEXT("Executing Ability on '%s'"), *Target->GetName());
	UAction::Execute(Data.Action, Target, Source);
}
