// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BasicEnemyAIController.generated.h"

/**
*
*/
UCLASS()
class SKRYMT_API ABasicEnemyAIController : public AAIController
{
	GENERATED_BODY()

private:

	/** BlackboardComponent - used to initialize blackboard values and set/get values from a blackboard asset */
	UBlackboardComponent* BlackboardComp;

	/** BehaviorTreeComponent - used to start a behavior tree */
	UBehaviorTreeComponent* BehaviorTreeComp;

	/** Blackboard Key Value Name */
	const FName BlackboardEnemyKey = FName("PlayerUnit");
	const FName Home = FName("Home");
	const FName LocationToGo = FName("LocationToGo");
	const FName Fleeing = FName("Fleeing");

	/** The function that fires when the perception of our AI gets updated */
	UFUNCTION()
		void OnPerceptionUpdated(TArray<AActor*> UpdatedActors);

	///** A Sight Sense config for our AI */
	//UAISenseConfig_Sight* Sight;

protected:
	/** A Sight Sense config for our AI */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perception")
	//UPROPERTY(EditAnywhere)
		UAISenseConfig_Sight* Sight;

	/** The Behavior Tree that contains the logic of our AI */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ai")
	//UPROPERTY(EditAnywhere)
		UBehaviorTree* BehaviorTree;

	/** The Perception Component of our AI */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Perception")
		UAIPerceptionComponent* AIPerceptionComponent;

public:

	//ABasicEnemyAIController();

	ABasicEnemyAIController(const FObjectInitializer& ObjectInitializer);
	//{
	//	Sight = ObjectInitializer.CreateDefaultSubobject<UAISenseConfig_Sight>(this, TEXT("SightSense"));


	//	Sight->SightRadius = 2000.f;
	//	Sight->LoseSightRadius = 2100.f;
	//	Sight->PeripheralVisionAngleDegrees = 360.f;
	//	//Sight->SetMaxAge(15.f);

	//	//Tell the sight sense to detect everything
	//	Sight->DetectionByAffiliation.bDetectEnemies = true;
	//	Sight->DetectionByAffiliation.bDetectFriendlies = true;
	//	Sight->DetectionByAffiliation.bDetectNeutrals = true;

	//	//Register the sight sense to our Perception Component
	//	AIPerceptionComponent->ConfigureSense(*Sight);
	//}

	virtual void Possess(APawn* InPawn) override;

	/** Returns the seeing pawn. Returns null, if our AI has no target */
	AActor* GetSeeingPawn();


};
