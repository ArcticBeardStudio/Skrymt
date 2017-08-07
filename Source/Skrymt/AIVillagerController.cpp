// Fill out your copyright notice in the Description page of Project Settings.

#include "AIVillagerController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"

#include "ControlableCharacter.h"
#include  "Barrack.h"
#include <vector>



void AAIVillagerController::OnPerceptionUpdated(TArray<AActor*> UpdatedActors)
{
	//If our character exists inside the UpdatedActors array, register him
	//to our blackboard component
	FName Enemy = FName("Enemy");

	for (AActor* Actor : UpdatedActors)
	{
		/*for (FName Enemy : Enemyclassnames)
		Actor->IsA<AControlableCharacter>()
		{*/
			//Check if correct-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------
			if (Actor->ActorHasTag(Enemy) && !GetSeeingPawn())
			{
				//Actor->ActorHasTag(Enemy);
				BlackboardComp->SetValueAsObject(BlackboardEnemyKey, Actor);
				BlackboardComp->SetValueAsBool(Fleeing, true);
				return;
			}
		//}
	}
	//UE_LOG(LogTemp, Log, TEXT("Hello world!"));
	//The character doesn't exist in our updated actors - so make sure
	//to delete any previous reference of him from the blackboard
	BlackboardComp->SetValueAsObject(BlackboardEnemyKey, nullptr);
}



AAIVillagerController::AAIVillagerController()
{
	//Components Init.
	BehaviorTreeComp = CreateDefaultSubobject<UBehaviorTreeComponent>(FName("BehaviorComp"));

	BlackboardComp = CreateDefaultSubobject<UBlackboardComponent>(FName("BlackboardComp"));



	AIPerceptionComponent = CreateDefaultSubobject<UAIPerceptionComponent>(FName("PerceptionComp"));

	//Create a Sight Sense
	Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(FName("Sight Config"));
	//Sight = CreateDefaultSubobject<UAISenseConfig_Sight>(FName("Sight Config"));

	Sight->SightRadius = 2000.f;
	Sight->LoseSightRadius = 2100.f;
	Sight->PeripheralVisionAngleDegrees = 120.f;
	//Sight->SetMaxAge(15.f);
	
	//BlackboardComp->SetValueAsVector(Home, me->GetActorLocation());
	
	
	//Tell the sight sense to detect everything
	Sight->DetectionByAffiliation.bDetectEnemies = true;
	Sight->DetectionByAffiliation.bDetectFriendlies = true;
	Sight->DetectionByAffiliation.bDetectNeutrals = true;

	//Register the sight sense to our Perception Component
	AIPerceptionComponent->ConfigureSense(*Sight);

	
	BlackboardComp->SetValueAsFloat(RadiusToWalkFromHome, WalkRadiusFromHome);
	//BlackboardComp->SetValueAsVector(Home, me->GetActorLocation());
}

//AAIVillagerController::AAIVillagerController()
//{
//
//}

float AAIVillagerController::GetWalkRadius()
{
	return WalkRadiusFromHome;
}

void AAIVillagerController::Set()
{
	/*ACharacter* me = GetCharacter();
	float test1 = BlackboardComp->SetValueAsFloat(RadiusToWalkFromHome, WalkRadiusFromHome);
	FVector test2  = BlackboardComp->SetValueAsVector(Home, me->GetActorLocation());
	bool test3 = BlackboardComp->SetValueAsBool(Init, true);*/
}

void AAIVillagerController::Possess(APawn* InPawn)
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
	AIPerceptionComponent->OnPerceptionUpdated.AddDynamic(this, &AAIVillagerController::OnPerceptionUpdated);
}

AActor* AAIVillagerController::GetSeeingPawn()
{
	//Return the seeing pawn
	UObject* object = BlackboardComp->GetValueAsObject(BlackboardEnemyKey);

	return object ? Cast<AActor>(object) : nullptr;
}