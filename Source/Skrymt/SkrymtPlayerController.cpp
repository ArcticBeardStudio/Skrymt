// Fill out your copyright notice in the Description page of Project Settings.

#include "SkrymtPlayerController.h"

//General Log
DEFINE_LOG_CATEGORY(MyLog);

//Constructor, enables tick and mouse cursor
ASkrymtPlayerController::ASkrymtPlayerController()
{
	PrimaryActorTick.bCanEverTick = true;
	bShowMouseCursor = true;
}

//Update function for the playercontroller
void ASkrymtPlayerController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

//Start function for the playercontroller
void ASkrymtPlayerController::BeginPlay()
{
	Super::BeginPlay();
	for (int i = 0; i < 9; i++)
	{
		TArray<AActor*> EmptyList;
		
		Controlgroups.Push(EmptyList);
		UE_LOG(MyLog, Warning, TEXT("Index is: %d"), i);
	}
	UE_LOG(MyLog, Warning, TEXT("Number of elements in Controlgroups: %d"), Controlgroups.Num());
}

void ASkrymtPlayerController::AddActorsToArray(const TArray<AActor*> ActorArray)
{
	SelectedActors = ActorArray;
	UE_LOG(MyLog, Warning, TEXT("Number of elements in SelectedActors: %d"), SelectedActors.Num());
}

void ASkrymtPlayerController::RemoveActorsFromArray()
{
	SelectedActors.Empty();
}

TArray<AActor*> ASkrymtPlayerController::GetAllSelectedActors()
{
	return SelectedActors;
}

void ASkrymtPlayerController::SetControlGroup(const int Index)
{
	if (Index > 0)
	{
		if (SelectedActors.Num() > 0)
		{
			if (Controlgroups.Num() > Index - 1)
			{
				Controlgroups[Index - 1] = SelectedActors;
			}
		}
	}
}

TArray<AActor*> ASkrymtPlayerController::GetControlgroup(const int Index)
{
	if (Index > 0)
	{
		if (Controlgroups[Index - 1].Num() > 0)
		{
			SelectedActors.Empty();
			SelectedActors = Controlgroups[Index - 1];
			return SelectedActors;
		}
	}

	//If no controlgroups was found, return an empty list
	TArray<AActor*> EmptyList;
	return EmptyList;
}