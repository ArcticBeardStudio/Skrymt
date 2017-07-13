// Fill out your copyright notice in the Description page of Project Settings.

#include "Action.h"
#include "DataReader.h"
#include "AbilitySystemComponent.h"
#include "AbilitySystemComponentInterface.h"



void UAction::Execute(FName RowName, AActor* Target, AActor* Source)
{

	FActionData ActionData = UDataReader::GetActionData(RowName);
	switch (ActionData.ActionType)
	{
	case EActionTypes::ApplyEffect:		ApplyEffect(ActionData, Target, Source);					break;
	default:							UE_LOG(LogTemp, Error, TEXT("Invalid Action Type"));		break;
	}

	
}

void UAction::ApplyEffect(FActionData ActionData, AActor* Target, AActor* Source)
{
	UAbilitySystemComponent* AbilitySystemComponent;
	UE_LOG(LogTemp, Warning, TEXT("Executing Action on '%s'"), *Target->GetName());

	bool bImplementsInterface = Target->GetClass()->ImplementsInterface(UAbilitySystemComponentInterface::StaticClass());
	UE_LOG(LogTemp, Warning, TEXT("'%s' implements interface = %s"), *Target->GetName(), bImplementsInterface ? TEXT("TRUE") : TEXT("FALSE"));

	if (bImplementsInterface)
	{
		IAbilitySystemComponentInterface* AbilitySystemComponentInterface = Cast<IAbilitySystemComponentInterface>(Target);
		UE_LOG(LogTemp, Warning, TEXT("Executing Action passed on '%s'"), *Target->GetName());
		AbilitySystemComponent = AbilitySystemComponentInterface->Execute_GetAbilitySystemComponent(Target);

		FApplyEffectData ApplyEffectData = UDataReader::GetApplyEffectData(ActionData.ActionTypeName);
		UE_LOG(LogTemp, Warning, TEXT("Executing Action of type 'ApplyEffect' named '%s'"), *ActionData.ActionTypeName.ToString());
		UE_LOG(LogTemp, Warning, TEXT("'%s' should apply '%s'"), *ActionData.ActionTypeName.ToString(), *ApplyEffectData.Effect.ToString());
		AbilitySystemComponent->ApplyEffect(ApplyEffectData.Effect);
	}
}
