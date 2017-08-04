// Copyright 2017 Arctic Beard Studio. All Rights Reserved.

#include "BTTask_RandomLocationFromHome.h"
#include "EngineUtils.h"
//#include "Skrymt.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
//#include "Runtime/Engine/Classes /AI/Navigation/NavigationSystem.h"
#include "Runtime/AIModule/Classes/Blueprint/AIBlueprintHelperLibrary.h"



EBTNodeResult::Type UBTTask_RandomLocationFromHome::ExecuteTask(class UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{



	//Get controller of the owner component
	AAIController* AICon = Cast<AAIController>(OwnerComp.GetAIOwner());

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
	
	UBlackboardComponent* BlackboardComp = nullptr;
	if (AICon && (AICon->GetPawn()))
	{
		Pawn = AICon->GetPawn();
		BlackboardComp = UAIBlueprintHelperLibrary::GetBlackboard(Pawn);
		float Radius = BlackboardComp->GetValueAsFloat(BBRadius);
		Homelocation = BlackboardComp->GetValueAsVector(Home); //Pawn->GetActorLocation();
		UNavigationSystem* NavSys = UNavigationSystem::GetCurrent(Pawn);
		NavSys->GetRandomReachablePointInRadius(Homelocation, Radius, NewLocation);//   GetRandomReachablePointInRadius(Pawn->GetWorld(), Actorlocation, 2000.f);
		//NavSys->GetRandomPointInNavigableRadius(Homelocation, Radius, NewLocation);																	/*	Pawn->GetActorRotation()*/
		
	}

	//If the blackboard component is valid print out a text
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsVector(Key, NewLocation.Location);
		//UE_LOG(LogTemp, Warning, TEXT("BlackBoardComponent successfully found!"));
		return EBTNodeResult::Succeeded;
	}


	return EBTNodeResult::Type();
}

