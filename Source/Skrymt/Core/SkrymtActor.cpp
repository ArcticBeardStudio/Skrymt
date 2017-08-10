// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#include "SkrymtActor.h"
#include "SkrymtCore.h"
#include "SkrymtGameState.h"


// Sets default values
ASkrymtActor::ASkrymtActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the actor is spawned
void ASkrymtActor::PostActorCreated()
{
	SkrymtCore::GetSkrymtGameState()->OnStartDay.AddDynamic(this, &ASkrymtActor::StartDay);
}

// Called when the game starts or when spawned
void ASkrymtActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called when a new day dawns
void ASkrymtActor::StartDay()
{
	UE_LOG(LogTemp, Warning, TEXT("%s >> Sees a new day dawning!"), *GetName());

	StartDay_Blueprint();
}

// Called every frame
void ASkrymtActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

