// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#pragma once

//#include "Engine.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemComponentInterface.h"
#include "BaseUnit.generated.h"

UCLASS()
class SKRYMT_API ABaseUnit : public ACharacter, public IAbilitySystemComponentInterface
{
	GENERATED_BODY()

public:
	
	// Sets default values for this character's properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ability")
		UAbilitySystemComponent* AbilityComponent;
	ABaseUnit();

	ABaseUnit(const FObjectInitializer& ObjectInitializer)
	{
		AbilityComponent = ObjectInitializer.CreateDefaultSubobject<UAbilitySystemComponent>(this, TEXT("Ability"));
		
	}

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//General variables
	

	//Health Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicUnit")
		uint8 Health;
	//Armor Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicUnit")
		uint8 Armor;

	//Production Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicUnit")
		uint8 ProductionNeeded;

	//Movement variables

	//MovementSpeed Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicUnit")
		uint8 MovementSpeed;
	//TurnSpeed Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicUnit")
		uint8 TurnSpeed;


	//Combat Variables



	// Damage Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicUnit")
		uint8 Damage;
	// DamageType Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicUnit")
		FName DamageType;
	//Hit Chance Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicUnit")
		uint8 HitChance;
	//AttackSpeed Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicUnit")
		uint8 AttackSpeed;
	//Range Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "BasicUnit")
		uint8 Range;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "BasicUnitFunction")
		void DamageRecieved(uint8 IncomingDamage);

	UFUNCTION(BlueprintCallable, Category = "BasicUnitFunction")
		bool CheckIfAlive();

	UFUNCTION(BlueprintCallable, Category = "BasicUnitFunction")
		void SetVariables(uint8 NewHealth, uint8 NewArmor, uint8 NewProductionNeeded, uint8 NewGarrison, uint8 NewDamage, uint8 NewHitChance, uint8 NewAttackSpeed, uint8 NewRange);
	
	
};
