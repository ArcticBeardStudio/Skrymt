// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"




// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();

}

void ABuilding::Construction(uint8 modifier)
{

}

void ABuilding::Produce(uint8 modifier)
{
}

void ABuilding::repair(uint8 modifier)
{
	health += modifier;
}

void ABuilding::MeshChange(FString filepath)
{
	const TCHAR* temp = *filepath;
	UStaticMesh* meshToUse = Cast<UStaticMesh>(StaticLoadObject(UStaticMesh::StaticClass(), NULL, temp));

	if (meshToUse && tempmesh)
	{
		tempmesh->SetStaticMesh(meshToUse);
	}

}

// Called every frame
//void ABuilding::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

