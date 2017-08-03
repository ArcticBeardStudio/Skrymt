// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#include "SkrymtButtonStyleFactory.h"
#include "UI/Styling/SkrymtButtonStyle.h"

USkrymtButtonStyleFactory::USkrymtButtonStyleFactory(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = USkrymtButtonStyle::StaticClass();
}

UObject * USkrymtButtonStyleFactory::FactoryCreateNew(UClass * Class, UObject * InParent, FName Name, EObjectFlags Flags, UObject * Context, FFeedbackContext * Warn)
{
	USkrymtButtonStyle* NewStyleAsset = NewObject<USkrymtButtonStyle>(InParent, Class, Name, Flags | RF_Transactional);
	return NewStyleAsset;
}
