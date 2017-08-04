// Fill out your copyright notice in the Description page of Project Settings.

#pragma once


#include "AIController.h"
#include "VillagerCharacter.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "AIVillagerController.generated.h"

/**
*
*/
UCLASS()
class SKRYMT_API AAIVillagerController : public AAIController
{
	GENERATED_BODY()

private:

	/** BlackboardComponent - used to initialize blackboard values and set/get values from a blackboard asset */
	UBlackboardComponent* BlackboardComp;

	/** BehaviorTreeComponent - used to start a behavior tree */
	UBehaviorTreeComponent* BehaviorTreeComp;
	AVillagerCharacter* me;
	/** Blackboard Key Value Name */
	const FName BlackboardEnemyKey = FName("Enemy");
	const FName Home = FName("HomeLocation");
	const FName LocationToGo = FName("LocationToGo");
	const FName Fleeing = FName("Fleeing");
	 
	const FName RadiusToWalkFromHome = FName("WalkRadiusFromHome");
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

	/** The Radius the villager can move from Home*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VillagerControllerStats")
		uint8 WalkRadiusFromHome;

public:

	AAIVillagerController();

	virtual void Possess(APawn* InPawn) override;

	/** Returns the seeing pawn. Returns null, if our AI has no target */
	AActor* GetSeeingPawn();

	UFUNCTION(BlueprintCallable, Category = "Villager")
		void Set();
};
