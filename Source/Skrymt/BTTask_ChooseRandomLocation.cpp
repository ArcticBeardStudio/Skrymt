// just a basic template to check if c++ tast is working correctly

#include "BTTask_ChooseRandomLocation.h"
#include "EngineUtils.h"
#include "Skrymt.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
//#include "Runtime/Engine/Classes /AI/Navigation/NavigationSystem.h"
#include "Runtime/AIModule/Classes/Blueprint/AIBlueprintHelperLibrary.h"





EBTNodeResult::Type UBTTask_ChooseRandomLocationC::ExecuteTask(class UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{


	//for (TActorIterator<ANavigationData> ActorItr(GetWorld()); ActorItr; ++ActorItr)
	//{
	//	// Same as with the Object Iterator, access the subclass instance with the * or -> operators.
	//	ANavigationData *Data = *ActorItr;
	//	Data->ActorHasTag()
	//	ClientMessage(ActorItr->GetName());
	//	ClientMessage(ActorItr->GetActorLocation().ToString());
	//}











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
	FVector actorlocation;
	FVector NewLocation;
	FName key = FName("MoveToLocation");
	UBlackboardComponent* BlackboardComp = nullptr;
	if (AICon && (AICon->GetPawn()))
	{
		Pawn = AICon->GetPawn();
		actorlocation = Pawn->GetActorLocation();
		UNavigationSystem* NavSys = UNavigationSystem::GetCurrent(Pawn);
		NewLocation =  NavSys->GetRandomReachablePointInRadius(Pawn->GetWorld(),actorlocation, 2000.f);
		BlackboardComp = UAIBlueprintHelperLibrary::GetBlackboard(Pawn);
	}

	//If the blackboard component is valid print out a text
	if (BlackboardComp)
	{
		BlackboardComp->SetValueAsVector(key, NewLocation);
		//UE_LOG(LogTemp, Warning, TEXT("BlackBoardComponent successfully found!"));
		return EBTNodeResult::Succeeded;
	}


	return EBTNodeResult::Type();
}

