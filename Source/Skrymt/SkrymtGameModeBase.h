// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "SkrymtGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API ASkrymtGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	

protected:

	/** The widget class to use for our HUD screen */
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Power", Meta = (BlueprintProtected = "true"))
		TSubclassOf<class UUserWidget> HUDWidgetClass;

	/** The instance of the HUD */
	UPROPERTY()
		class UUserWidget* CurrentWidget;




public:
	ASkrymtGameModeBase(const FObjectInitializer &ObjectInitializer);

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	/** Helper function for end of the day */
	UFUNCTION(BlueprintCallable, Category = "GameManager")
	void EndOfTheDay();

};
