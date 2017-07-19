// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

//#include "CoreMinimal.h"
#include "Engine.h"
#include "GameFramework/Actor.h"
#include "Building.generated.h"


USTRUCT(Blueprintable)
struct FBuildingData : public FTableRowBase
{
	GENERATED_USTRUCT_BODY()


		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Housing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Garrison;

	UPROPERTY(BlueprintReadOnly, Category = "Building")
		FString Mesh;



};

UCLASS()
class SKRYMT_API ABuilding : public AActor
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")

		UStaticMeshComponent * tempmesh;

	ABuilding(const FObjectInitializer& ObjectInitializer)
		: Super(ObjectInitializer)
	{
		tempmesh = ObjectInitializer.CreateDefaultSubobject<UStaticMeshComponent>(this, TEXT("Mesh"));

	}



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	//UStaticMesh CurrentMesh;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 health;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Armor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Housing;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Building")
		uint8 Garrison;
public:


	/*SM_asset for mesh*/

	UFUNCTION(BlueprintCallable)
		virtual void Construction(uint8 modifier);
	UFUNCTION(BlueprintCallable)
		virtual void Produce(uint8 modifier);
	UFUNCTION(BlueprintCallable)
		virtual void repair(uint8 modifier);
	UFUNCTION(BlueprintCallable)
		void MeshChange(FString filepath);
	// Called every frame
	//virtual void Tick(float DeltaTime) override;



};

