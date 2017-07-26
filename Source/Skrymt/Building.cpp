// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"




// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();

}

void ABuilding::Construction(uint8 Modifier)
{

}

void ABuilding::Produce(uint8 Modifier)
{

}

void ABuilding::Repair(uint8 Modifier)
{
	Health += Modifier;
}

void ABuilding::SetVariables(uint8 NewHealth, uint8 NewArmor, uint8 NewHousing, uint8 NewGarrison, uint8 NewProductionNeeded, ResourceTypes NewResourceType, uint8 NewResourcePerWorker)
{
	Health = NewHealth;
	Armor = NewArmor;
	Housing = NewHousing;
	Garrison = NewGarrison;
	ProductionNeeded = NewProductionNeeded;
	ResourceType = NewResourceType;
	ResourcePerWorker = NewResourcePerWorker;
	UE_LOG(LogTemp, Warning, TEXT("Set Variables Building"));
}

void ABuilding::MeshChange(FString Filepath)
{
	const TCHAR* Temp = *Filepath;
	UStaticMesh* MeshToUse = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, Temp));

	if (MeshToUse && Tempmesh)
	{
		Tempmesh->SetStaticMesh(MeshToUse);
	}

}

// Called every frame
//void ABuilding::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

