// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"
#include "Core/SkrymtCore.h"
#include "SkrymtGameState.h"
#include "BuildingManager.h"
#include "SkrymtPlayerState.h"
#include "DataLibrary.h"
#include "DataReader.h"

ABuilding::ABuilding(const FObjectInitializer& ObjectInitializer)
{
	Root = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));
	RootComponent = Root;

	Mesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));
}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();

	Data = UDataReader::GetBuildingData(BuildingName);

	BuildingManager = SkrymtCore::GetSkrymtPlayerState()->BuildingManager;

	// QUICK HACK CONSTRUCT
	BuildingManager->OnConstructBuilding.Broadcast(this);
}

void ABuilding::StartedDay()
{

}