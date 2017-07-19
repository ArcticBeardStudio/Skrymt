// Fill out your copyright notice in the Description page of Project Settings.

#include "TextureLibrary.h"

// Gets the color value of a textures pixel
FColor UTextureLibrary::GetTexturePixel(UTexture2D* Texture, int32 X, int32 Y)
{
	/* Temporary comment for a successful compile
	// Get first mip level
	FTexture2DMipMap* Mip0 = &Texture->PlatformData->Mips[0];
	// Lock the data for reading
	FColor* FormatedImageData = static_cast<FColor*>(Mip0->BulkData.Lock(LOCK_READ_ONLY));
	// Get texture size
	int32 Width = Mip0->SizeX;
	int32 Height = Mip0->SizeY;
	// Initialize result as (255, 0, 255) pink
	FColor Result = FColor(255, 0, 255);
	// Check if we're inside texture bounds
	if (X >= 0 && X < Width && Y = > 0 && Y < Height)
	{
		// Set result to pixel color
		Result = FormatedImageData[X + Y * Width];
	}
	// Unlock the the data
	Mip0->BulkData.Unlock();
	// Return our result
	return Result;
	*/
	return FColor();
}
