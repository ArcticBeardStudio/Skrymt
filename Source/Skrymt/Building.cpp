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

