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
	const FName BlackboardEnemyKey = FName("Enemy");
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
	UPROPERTY(EditAnywhere)
		UAISenseConfig_Sight* Sight;

	/** The Behavior Tree that contains the logic of our AI */
	UPROPERTY(EditAnywhere)
		UBehaviorTree* BehaviorTree;

	/** The Perception Component of our AI */
	UPROPERTY(EditAnywhere)
		UAIPerceptionComponent* AIPerceptionComponent;

public:

	ABasicEnemyAIController();

	virtual void Possess(APawn* InPawn) override;

	/** Returns the seeing pawn. Returns null, if our AI has no target */
	AActor* GetSeeingPawn();


};
