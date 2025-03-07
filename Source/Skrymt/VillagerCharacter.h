// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "BaseUnit.h"
#include "VillagerCharacter.generated.h"

UCLASS()
class SKRYMT_API AVillagerCharacter : public ABaseUnit
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AVillagerCharacter();





	AVillagerCharacter(const FObjectInitializer& ObjectInitializer)
	{
		AbilityComponent = ObjectInitializer.CreateDefaultSubobject<UAbilitySystemComponent>(this, TEXT("Ability"));

	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	
	
};
