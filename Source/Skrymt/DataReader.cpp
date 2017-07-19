// Fill out your copyright notice in the Description page of Project Settings.

#include "DataReader.h"

FTableRowBase* UDataReader::GetData(FName Name, const TCHAR* Path)
{
	UDataTable* DataTable = LoadObject<UDataTable>(NULL, Path, NULL, LOAD_None, NULL);
	FString ContextString;
	return DataTable->FindRow<FTableRowBase>(Name, ContextString);
}

FActionData UDataReader::GetActionData(FName RowName)
{
	UDataTable* ActionDataTable = LoadObject<UDataTable>(NULL, TEXT("/Game/Data/ActionDataTable.ActionDataTable"), NULL, LOAD_None, NULL);
	FString ContextString;
	return *ActionDataTable->FindRow<FActionData>(RowName, ContextString);
}

FApplyEffectData UDataReader::GetApplyEffectData(FName RowName)
{
	UDataTable* ActionDataTable = LoadObject<UDataTable>(NULL, TEXT("/Game/Data/ApplyEffectDataTable.ApplyEffectDataTable"), NULL, LOAD_None, NULL);
	FString ContextString;
	return *ActionDataTable->FindRow<FApplyEffectData>(RowName, ContextString);
}
