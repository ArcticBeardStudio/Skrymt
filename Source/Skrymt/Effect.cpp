// Fill out your copyright notice in the Description page of Project Settings.

#include "Effect.h"
#include "DataReader.h"
#include "AbilitySystemComponent.h"

void UEffect::Initialize(FName EffectName)
{
	Name = EffectName;
	Data = UDataReader::GetEffectData(EffectName);
}

void UEffect::TickEffect(float DeltaTime)
{
	ElapsedTime += DeltaTime;

	if (ElapsedTime >= Data.Duration)
	{
		Expire();
	}
}

void UEffect::Expire()
{
	UAbilitySystemComponent* AbilitySystemComponent = GetTypedOuter<UAbilitySystemComponent>();
	if (AbilitySystemComponent->IsValidLowLevel())
	{
		AbilitySystemComponent->EffectExpired(Name);
	}
}
