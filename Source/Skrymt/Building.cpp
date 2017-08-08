// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"
#include "SkrymtGameState.h"
#include "BuildingManager.h"
#include "SkrymtPlayerState.h"

ABuilding::ABuilding(const FObjectInitializer& ObjectInitializer)
{
	Root = ObjectInitializer.CreateDefaultSubobject<USceneComponent>(this, TEXT("Root"));
	RootComponent = Root;
}

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
}

void ABuilding::StartedDay()
{

}