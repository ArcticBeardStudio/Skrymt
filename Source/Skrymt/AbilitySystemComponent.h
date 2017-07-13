// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Components/ActorComponent.h"
#include "AbilitySystemComponent.generated.h"


UCLASS( ClassGroup=(AbilitySystem), meta=(BlueprintSpawnableComponent) )
class SKRYMT_API UAbilitySystemComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability System")
	// Abilities the actor possesses
	TMap<FName, class UAbility*> Abilities;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability System")
	// Effects that are active on the actor
	TMap<FName, class UEffect*> Effects;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Ability System")
	// Tags associated with the actor
	TSet<FName> Tags;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Sets default values for this component's properties
	UAbilitySystemComponent();

	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	void GiveAbility(FName AbilityName);

	UFUNCTION(BlueprintCallable, Category = "Arctic Power Component")
	UEffect* ApplyEffect(FName EffectName);

	void EffectExpired(FName Name);
	
};
