// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#include "BaseUnit.h"


//// Sets default values
ABaseUnit::ABaseUnit()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	//PrimaryActorTick.bCanEverTick = true;

	

}

// Called when the game starts or when spawned
void ABaseUnit::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABaseUnit::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ABaseUnit::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}
void ABaseUnit::DamageRecieved(uint8 damage)
{
	Health = Health - damage;
}

bool ABaseUnit::CheckIfAlive()
{
	return Health <= 0;
}
void ABaseUnit::SetVariables(uint8 NewHealth, uint8 NewArmor, uint8 NewProductionNeeded, uint8 NewGarrison, uint8 NewDamage, uint8 NewHitChance, uint8 NewAttackSpeed, uint8 NewRange)
{

}
