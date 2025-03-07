// Fill out your copyright notice in the Description page of Project Settings.


#include "BasicEnemyAIController.h"
#include "BasicEnemyCharacter.h"
#include "Engine.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"


//#include <vector>



void ABasicEnemyAIController::OnPerceptionUpdated(TArray<AActor*> UpdatedActors)
{
	//If our character exists inside the UpdatedActors array, register him
	//to our blackboard component
	

	////UE_LOG(LogTemp, Log, TEXT("Hello world!"));
	////The character doesn't exist in our updated actors - so make sure
	////to delete any previous reference of him from the blackboard
	//BlackboardComp->SetValueAsObject(BlackboardEnemyKey, nullptr);


	//If our character exists inside the UpdatedActors array, register him
	//to our blackboard component
	FName Enemy = FName("PlayerOwned");
	ABasicEnemyCharacter* me = (ABasicEnemyCharacter*)GetCharacter();
	
	for (AActor* Actor : UpdatedActors)
	{
		/*for (FName Enemy : Enemyclassnames)
		Actor->IsA<AControlableCharacter>()
		{*/
		//Check if actor has enemy tag 
		if (Actor->ActorHasTag(Enemy) && !GetSeeingPawn())
		{
			//Actor->ActorHasTag(Enemy);
			if (!ViewableActorHasActor(Actor))
			{
				AddActorToViewableActor(Actor);
			}
			
			//BlackboardComp->SetValueAsObject(BlackboardEnemyKey, Actor);
			//BlackboardComp->SetValueAsBool(Fleeing, true);
			return;
		}
		//}
	}
	//UE_LOG(LogTemp, Log, TEXT("Hello world!"));
	//The character doesn't exist in our updated actors - so make sure
	//to delete any previous reference of him from the blackboard
	//BlackboardComp->SetValueAsObject(BlackboardEnemyKey, nullptr);


}



ABasicEnemyAIController::ABasicEnemyAIController()
{
	//Components Init.
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(FName("BehaviorComp"));

	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(FName("BlackboardComp"));
	


	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(FName("PerceptionComp"));

	//Create a Sight Sense
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(FName("Sight Config"));

	

	Sight->SightRadius = 1000.f;
	Sight->LoseSightRadius = 1100.f;
	Sight->PeripheralVisionAngleDegrees = 360.f;
	//Sight->SetMaxAge(15.f);

	//Tell the sight sense to detect everything
	Sight->DetectionByAffiliation.bDetectEnemies = true;
	Sight->DetectionByAffiliation.bDetectFriendlies = true;
	Sight->DetectionByAffiliation.bDetectNeutrals = true;


	//Register the sight sense to our Perception Component
	AIPerceptionComponent->ConfigureSense(*Sight);
	

	//Create a Hearing Sense
	Hearing = CreateDefaultSubobject<UAISenseConfig_Hearing>(FName("Hearing Config"));

	Hearing->HearingRange = 1000.f;
	Hearing->LoSHearingRange = 200.f;
	////Tell the Hearing sense to detect everything
	Hearing->DetectionByAffiliation.bDetectEnemies = true;
	Hearing->DetectionByAffiliation.bDetectFriendlies = true;
	Hearing->DetectionByAffiliation.bDetectNeutrals = true;


	AIPerceptionComponent->ConfigureSense(*Hearing);
}

void ABasicEnemyAIController::Possess(APawn* InPawn)
{
	Super::Possess(InPawn);

	if (BehaviorTree)
	{
		//Initialize the Blackboard and start the attached behavior tree
		BlackboardComp->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
		BehaviorTreeComp->StartTree(*BehaviorTree);
		BlackboardComp->SetValueAsVector(Home, InPawn->GetActorLocation());
		
		
	}


	//Register the OnPerceptionUpdated function to fire whenever the AIPerception get's updated
	AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &ABasicEnemyAIController::OnPerceptionUpdated);

}

AActor* ABasicEnemyAIController::GetSeeingPawn()
{
	//Return the seeing pawn
	UObject* object = BlackboardComp->GetValueAsObject(BlackboardEnemyKey);

	return object ? Cast<AActor>(object) : nullptr;
}
void ABasicEnemyAIController::AddActorToViewableActor(AActor* Actor)
{
	viewableActors.Add(Actor);
}
void ABasicEnemyAIController::RemoveActorToViewableActor(AActor* Actor)
{
	viewableActors.RemoveSingle(Actor);
}

bool ABasicEnemyAIController::ViewableActorHasActor(AActor* Actor)
{
	for (AActor* ArrayActor : viewableActors)
	{
		if (ArrayActor == Actor) return true;
	}
	return false;
}