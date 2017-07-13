// Fill out your copyright notice in the Description page of Project Settings.

#include "AbilitySystemComponent.h"
#include "Effect.h"


// Sets default values for this component's properties
UAbilitySystemComponent::UAbilitySystemComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UAbilitySystemComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UAbilitySystemComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	for (auto& Elem : Effects)
	{
		Elem.Value->TickEffect(DeltaTime);
	}
}

void UAbilitySystemComponent::GiveAbility(FName AbilityName)
{
}

UEffect* UAbilitySystemComponent::ApplyEffect(FName EffectName)
{
	UEffect* Effect = NewObject<UEffect>(this);
	Effect->Initialize(EffectName);
	Effects.Add(EffectName, Effect);
	return Effect;
}

void UAbilitySystemComponent::EffectExpired(FName EffectName)
{
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT("EFFECT EXPIRED"));
	Effects.Remove(EffectName);
}

