// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BasicEnemyCharacter.generated.h"

UCLASS()
class SKRYMT_API ABasicEnemyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ABasicEnemyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	//General variables

	//Health Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyUnit")
		uint8 Health;
	//Armor Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyUnit")
		uint8 Armor;

	//Production Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyUnit")
		uint8 ProductionNeeded;

	//Movement variables

	//MovementSpeed Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyUnit")
		uint8 MovementSpeed;
	//TurnSpeed Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyUnit")
		uint8 TurnSpeed;


	//Combat Variables


	
	// Damage Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyUnit")
		uint8 Damage;
	// DamageType Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyUnit")
		FName DamageType;
	//Hit Chance Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyUnit")
		uint8 HitChance;
	//AttackSpeed Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyUnit")
		uint8 AttackSpeed;
	//Range Variable
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyUnit")
		uint8 Range;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable, Category = "EnemyUnitFunction")
		void DamageRecieved(uint8 IncomingDamage);

	UFUNCTION(BlueprintCallable, Category = "EnemyUnitFunction")
		bool CheckIfAlive();

	UFUNCTION(BlueprintCallable, Category = "EnemyUnitFunction")
		void SetVariables(uint8 NewHealth, uint8 NewArmor, uint8 NewProductionNeeded, uint8 NewGarrison, uint8 NewDamage, uint8 NewHitChance, uint8 NewAttackSpeed, uint8 NewRange);
	
};
