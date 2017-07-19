// Fill out your copyright notice in the Description page of Project Settings.

#include "TextureLibrary.h"

FColor UTextureLibrary::GetTexturePixel(UTexture2D* MyTexture2D, int32 X, int32 Y)
{
	FColor* FormatedImageData = static_cast<FColor*>(MyTexture2D->PlatformData->Mips[0].BulkData.Lock(LOCK_READ_ONLY));
	return FColor();
}
