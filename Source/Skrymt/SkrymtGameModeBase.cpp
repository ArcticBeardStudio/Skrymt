// Fill out your copyright notice in the Description page of Project Settings.

#include "SkrymtGameModeBase.h"
#include "Blueprint/UserWidget.h"




void ASkrymtGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	if (HUDWidgetClass != nullptr)
	{
		CurrentWidget = CreateWidget<UUserWidget>(GetWorld(), HUDWidgetClass);
		if (CurrentWidget != nullptr)
		{
			CurrentWidget->AddToViewport();
		}
	}
}

void ASkrymtGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void ASkrymtGameModeBase::EndOfTheDay()
{
	
}