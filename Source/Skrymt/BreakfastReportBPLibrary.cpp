// Fill out your copyright notice in the Description page of Project Settings.

#include "BreakfastReportBPLibrary.h"
#define LOCTEXT_NAMESPACE "Your Namespace"

FText UBreakfastReportBPLibrary::GetFoodProduction()
{
	FText TestHUDText = LOCTEXT("Production", "1");
	return TestHUDText;
}

FText UBreakfastReportBPLibrary::GetWoodProduction()
{
	FText TestHUDText = LOCTEXT("Production", "27");
	return TestHUDText;
}

FText UBreakfastReportBPLibrary::GetGoldProduction()
{
	FText TestHUDText = LOCTEXT("Production", "3");
	return TestHUDText;
}

FText UBreakfastReportBPLibrary::GetStoneProduction()
{
	FText TestHUDText = LOCTEXT("Production", "4");
	return TestHUDText;
}

FText UBreakfastReportBPLibrary::GetOreProduction()
{
	FText TestHUDText = LOCTEXT("Production", "5");
	return TestHUDText;
}

FText UBreakfastReportBPLibrary::GetWeather()
{
	FText TestHUDText = LOCTEXT("Production", "Sun");
	return TestHUDText;
}


#undef LOCTEXT_NAMESPACE