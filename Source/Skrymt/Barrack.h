// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Building.h"
//#include "GameFramework/Actor.h"
#include "Barrack.generated.h"

UCLASS()
class SKRYMT_API ABarrack : public ABuilding
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties

	/*ABarrack(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
	{
	tempmesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));


	}*/

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	/*UFUNCTION(BlueprintCallable)
	virtual void Construction() override;
	UFUNCTION(BlueprintCallable)
	virtual void Produce() override;
	UFUNCTION(BlueprintCallable)
	void repair() override;*/
	/*virtual void Tick(float DeltaTime) override;*/



};
