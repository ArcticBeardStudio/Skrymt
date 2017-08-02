// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"

#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISenseConfig_Sight.h"
#include "Perception/AISenseConfig_Hearing.h"
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
	int check = 0;
	const FName BlackboardEnemyKey = FName("PlayerUnit");
	const FName Home = FName("Home");
	const FName LocationToGo = FName("LocationToGo");
	const FName Fleeing = FName("Fleeing");
	const FName NewTarget = FName("NewTarget"); 
	const FName CurrentCheckedTarget = FName("CurrentCheckedTargetLocation");


	/** The function that fires when the perception of our AI gets updated */
	UFUNCTION()
		void OnPerceptionUpdated(TArray<AActor*> UpdatedActors);

	///** A Sight Sense config for our AI */
	//UAISenseConfig_Sight* Sight;

	/*UObject* temptarget;
	UObject* Blackboardobject;*/

protected:
	/** A Sight Sense config for our AI */
	UPROPERTY(EditAnywhere)
		UAISenseConfig_Sight* Sight;
	UPROPERTY(EditAnywhere)
		UAISenseConfig_Hearing* Hearing;

	/** The Behavior Tree that contains the logic of our AI */
	UPROPERTY(EditAnywhere)
		UBehaviorTree* BehaviorTree;

	/** The Perception Component of our AI */
	UPROPERTY(EditAnywhere)
		UAIPerceptionComponent* AIPerceptionComponent;

	//** Array with actors in perceptionrange from units*/
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TargetSearch")
		TArray<AActor*> viewableActors;

public:

	

	ABasicEnemyAIController();
	

	virtual void Possess(APawn* InPawn) override;

	/** Returns the seeing pawn. Returns null, if our AI has no target */
	AActor* GetSeeingPawn();


	/** Adds actor to viewableActors Array */
	UFUNCTION(BlueprintCallable, Category = "ViewableActors")
	void AddActorToViewableActor(AActor* actor);
	/** remove actor from viewableActors Array */
	UFUNCTION(BlueprintCallable, Category = "ViewableActors")
	void RemoveActorToViewableActor(AActor* actor);
	/** checks if actor is in viewableActors Array */
	UFUNCTION(BlueprintCallable, Category = "ViewableActors")
	bool ViewableActorHasActor(AActor* actor);

};
