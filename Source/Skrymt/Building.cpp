// Fill out your copyright notice in the Description page of Project Settings.

#include "Building.h"
#include "SkrymtGameState.h"
#include "BuildingManager.h"
#include "SkrymtPlayerState.h"

// Called when the game starts or when spawned
void ABuilding::BeginPlay()
{
	Super::BeginPlay();
}

void ABuilding::StartedDay()
{
	if (GetDaysLeftToConstruct() <= 1) 
	{
		if (bIsComplete == false)
		{
			DaysWorkedOnBuilding++;
			Construction();
		}
		return;
	}
	DaysWorkedOnBuilding++;
	GEngine->AddOnScreenDebugMessage(30, 10.f, FColor::Blue, FString::Printf(TEXT("Days Worked = '%d'"), DaysWorkedOnBuilding));
}

void ABuilding::Construction()
{
	bIsComplete = true;
	BuildingManagerRef->OnConstructBuilding.Broadcast(this);
	UE_LOG(LogTemp, Warning, TEXT("In Construction Building"));
}

void ABuilding::Produce(uint8 Modifier)
{

}

void ABuilding::Repair(uint8 Modifier)
{
	Health += Modifier;
}

int ABuilding::GetHousing()
{
	return Housing;
}

int ABuilding::GetDaysLeftToConstruct()
{
	return DaysToComplete - DaysWorkedOnBuilding;
}

void ABuilding::SetVariables(uint8 NewHealth, uint8 NewArmor, uint8 NewHousing, uint8 NewGarrison, uint8 NewDaysToComplete, uint8 NewMaxWorkerInBuilding, ResourceTypes NewResourceType, uint8 NewResourcePerWorker, FBuildingCost NewBuildingCost)
{
	Health = NewHealth;
	Armor = NewArmor;
	Housing = NewHousing;
	Garrison = NewGarrison;
	DaysToComplete = NewDaysToComplete;
	MaxWorkerInBuilding = NewMaxWorkerInBuilding;
	ResourceType = NewResourceType;
	ResourcePerWorker = NewResourcePerWorker;
	BuildingCost = NewBuildingCost;
	UE_LOG(LogTemp, Warning, TEXT("Set Variables Building"));
	ASkrymtGameState* GameState = (ASkrymtGameState*)GetWorld()->GetGameState();
	GameState->OnStartDay.AddDynamic(this, &ABuilding::StartedDay);
	ASkrymtPlayerState* PlayerState = Cast<ASkrymtPlayerState>(GetWorld()->GetFirstPlayerController()->PlayerState);
	BuildingManagerRef = PlayerState->BuildingManager;
	PlayerState->UpdateResourcesConstruct(NewBuildingCost);
	if (DaysToComplete == 0)
	{
		Construction();
	}

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

ResourceTypes ABuilding::GetResourceType()
{
	return ResourceType;
}

bool ABuilding::CheckComplete()
{
	return bIsComplete;
}

int ABuilding::GetResourcePerWorker()
{
	return ResourcePerWorker;
}

/*
WoodBaseProd = 10 + NewBase

WoodMaxPop = 10 + 3 + 5

0 - 18 * WoodBaseProd
*/

// Called every frame
//void ABuilding::Tick(float DeltaTime)
//{
//	Super::Tick(DeltaTime);
//
//}

