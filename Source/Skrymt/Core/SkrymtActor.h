// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SkrymtActor.generated.h"

UCLASS()
class SKRYMT_API ASkrymtActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASkrymtActor();

protected:
	// Called when the actor is spawned
	virtual void PostActorCreated() override;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called when a new day dawns
	UFUNCTION()
	virtual void StartDay();
	// Called when a new day dawns for blueprints
	UFUNCTION(BlueprintImplementableEvent, Category = "Skrymt Actor", meta = (DisplayName = "Start Day"))
	void StartDay_Blueprint();
};
