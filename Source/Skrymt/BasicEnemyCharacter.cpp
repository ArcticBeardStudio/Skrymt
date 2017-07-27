// Fill out your copyright notice in the Description page of Project Settings.

#include "BasicEnemyCharacter.h"


// Sets default values
ABasicEnemyCharacter::ABasicEnemyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ABasicEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABasicEnemyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABasicEnemyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ABasicEnemyCharacter::DamageRecieved(uint8 damage)
{
	Health = Health - damage;
}

bool ABasicEnemyCharacter::CheckIfAlive()
{
	return Health <= 0;
}
void ABasicEnemyCharacter::SetVariables(uint8 NewHealth, uint8 NewArmor, uint8 NewProductionNeeded, uint8 NewGarrison, uint8 NewDamage, uint8 NewHitChance, uint8 NewAttackSpeed, uint8 NewRange)
{

}