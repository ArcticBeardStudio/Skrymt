// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#include "BTTask_RandomLocationFromHome.h"
#include "EngineUtils.h"
#include "Skrymt.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AIVillagerController.h"
//#include "Runtime/AIModule/Classes/AIController.h"
//#include "Runtime/Engine/Classes /AI/Navigation/NavigationSystem.h"

#include "Runtime/AIModule/Classes/Blueprint/AIBlueprintHelperLibrary.h"



EBTNodeResult::Type UBTTask_RandomLocationFromHome::ExecuteTask(class UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{



	//Get controller of the owner component
	AAIVillagerController* AICon = Cast<AAIVillagerController>(OwnerComp.GetAIOwner());

	//check if it's valid
	if (AICon == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	//check if the pawn is valid
	if (AICon->GetPawn() == nullptr)
	{
		return EBTNodeResult::Failed;
	}

	//If both valid get the blackboard component of the pawn
	AActor* Pawn = nullptr;
	FVector Homelocation;
	//FVector NewLocation;
	FNavLocation NewLocation;
	FName Key = FName("MoveToLocation");
	FName Home = FName("HomeLocation");
	FName BBRadius = FName("Radius");
	float Radius;
	

	UBlackboardComponent* BlackboardComp = nullptr;
	if (AICon && (AICon->GetPawn()))
	{
		Pawn = AICon->GetPawn();
		
		//BlackboardComp = Pawn->GetController()->FindComponentByClass<UBlackboardComponent>();
		BlackboardComp =  UAIBlueprintHelperLibrary::GetBlackboard(Pawn);
		Radius = BlackboardComp->GetValueAsFloat(BBRadius);
		Homelocation = BlackboardComp->GetValueAsVector(Home); //Pawn->GetActorLocation();

		UNavigationSystem* NavSys = UNavigationSystem::GetCurrent(Pawn);
		//NavSys->GetRandomReachablePointInRadius(Homelocation, AICon->GetWalkRadius(), NewLocation);//   GetRandomReachablePointInRadius(Pawn->GetWorld(), Actorlocation, 2000.f);
		NavSys->GetRandomPointInNavigableRadius( Homelocation, AICon->GetWalkRadius(), NewLocation);
		/*	Pawn->GetActorRotation()*/
		//GEngine->AddOnScreenDebugMessage(30, 10.f, FColor::Blue, FString::Printf(TEXT("Days Worked = '%f'"), Radius));
		/*FString TheFloatStr = FString::SanitizeFloat(Radius);
		FString TheFloatStrx = FString::SanitizeFloat(NewLocation.Location.X);
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, *TheFloatStr);
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Blue, *TheFloatStrx);*/
		//UE_LOG(LogTemp, Warning, TEXT("Set Variables Building"));
		//NavSys->GetRandomReachablePointInRadius(BlackboardComp->GetValueAsVector(Home), BlackboardComp->GetValueAsFloat(BBRadius) , NewLocation);


	}

	//If the blackboard component is valid print out a text
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsVector(Key, NewLocation.Location);

		/*FString TheFloatString = FString::SanitizeFloat(Radius);
		FString TheFloatStringx = FString::SanitizeFloat(NewLocation.Location.X);
		FString TheFloatStringy = FString::SanitizeFloat(NewLocation.Location.Y);
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Red, *TheFloatString);
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Blue, *TheFloatStringx);
		GEngine->AddOnScreenDebugMessage(-1, 1.0, FColor::Blue, *TheFloatStringy);*/
		//UE_LOG(LogTemp, Warning, TEXT("BlackBoardComponent successfully found!"));
		return EBTNodeResult::Succeeded;
	}


	return EBTNodeResult::Type();
}

