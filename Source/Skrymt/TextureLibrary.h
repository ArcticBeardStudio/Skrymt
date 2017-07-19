// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "TextureLibrary.generated.h"

/**
 * 
 */
UCLASS()
class SKRYMT_API UTextureLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	// Gets the color value of a textures pixel
	UFUNCTION(BlueprintCallable, Category = "Texture")
	FColor GetTexturePixel(UTexture2D* Texture, int32 X, int32 Y);
};
