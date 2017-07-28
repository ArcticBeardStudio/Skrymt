// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#include "EventObject.h"
#include "SkrymtPlayerState.h"
#include "EventManager.h"


UEventObject::UEventObject()
{
	// Read data

	//this->OnStart();
}

UEventObject::UEventObject(FName id, float duration, float numberofchildren, TSet<FName> effectTags, TSet<FName> tagsRecevied, TSet<FName> tagsLost, TArray<FName> children)
{
	this->ID = id;
	this->Duration = duration;
	this->NumberOfChildren = numberofchildren;
	this->EffectTags = effectTags;
	this->TagsRecevied = tagsRecevied;
	this->TagsLost = tagsLost;
	this->Children = children;
}

void UEventObject::OnEffect_Implementation()
{
	
}

void UEventObject::OnStart_Implementation()
{
	// Set tags for the world
}

void UEventObject::OnExpired_Implementation()
{
	// Remove tags from the world
}

bool UEventObject::CheckIfTriggered()
{
	if (this->bTriggered)
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Emerald, FString::Printf(TEXT("Bool True")));
		this->Trigger();
		return true;
	}
	else if (this->CheckConditions())
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Emerald, FString::Printf(TEXT("CheckConditions true")));
		this->Trigger();
		return true;
	}
	else
	{
		GEngine->AddOnScreenDebugMessage(-1, 10.f, FColor::Emerald, FString::Printf(TEXT("Else")));
		return false;
	}
}

bool UEventObject::CheckConditions_Implementation()
{
	return true;
}

void UEventObject::Trigger_Implementation()
{
	GetTypedOuter<UEventManager>()->OnEventTriggered.Broadcast(this);
}

void UEventObject::CreateEventUI_Implementation()
{

}

void UEventObject::Terminate()
{
	this->OnExpired();
	this->bTerminated = true;
	// Communicate with event manager that this event should be terminated
}

void UEventObject::TickEvent()
{
	
	if (!this->CheckIfTriggered())
	{
		
		if (this->Duration > 0.0f)
		{
			this->Duration = this->Duration - 1.0f;
			this->OnEffect();
		}
		else
		{

			this->Terminate();
		}
	}

}

ASkrymtPlayerState* UEventObject::GetPlayerState()
{ 
	return GetTypedOuter<ASkrymtPlayerState>();
}

APlayerController* UEventObject::GetFirstLocalPlayer()
{
	return GetPlayerState()->GetWorld()->GetFirstPlayerController();
}