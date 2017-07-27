

#include "ControlableCharacter.h"


// Sets default values
AControlableCharacter::AControlableCharacter()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AControlableCharacter::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AControlableCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AControlableCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AControlableCharacter::DamageRecieved(uint8 damage)
{
	Health = Health - damage;
}

bool AControlableCharacter::CheckIfAlive()
{
	return Health <= 0;
}
void AControlableCharacter::SetVariables(uint8 NewHealth, uint8 NewArmor, uint8 NewProductionNeeded, uint8 NewGarrison, uint8 NewDamage, uint8 NewHitChance, uint8 NewAttackSpeed, uint8 NewRange)
{

}
