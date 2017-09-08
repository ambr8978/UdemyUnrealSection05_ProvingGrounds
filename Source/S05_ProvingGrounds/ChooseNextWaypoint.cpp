// Fill out your copyright notice in the Description page of Project Settings.

#include "ChooseNextWaypoint.h"
#include "Runtime/AIModule/Classes/BehaviorTree/BlackboardComponent.h"
#include "Runtime/AIModule/Classes/AIController.h"
#include "PatrolRouteComponent.h"
#include "PatrollingGuard.h"

EBTNodeResult::Type UChooseNextWaypoint::ExecuteTask(UBehaviorTreeComponent & OwnerComp, uint8 * NodeMemory)
{	
	//Get the patrol points - this whole function is freaking terrible would refactor but keeping for class consistency
	AAIController* AIController = OwnerComp.GetAIOwner();
	APawn* ControlledPawn = AIController->GetPawn();
	UPatrolRouteComponent* PatrolRoute = ControlledPawn->FindComponentByClass<UPatrolRouteComponent>();
	if (!ensure(PatrolRoute)) 
	{ 
		return EBTNodeResult::Failed;
	};

	TArray<AActor*> PatrolPoints = PatrolRoute->GetPatrolPoints();
	if (PatrolPoints.Num() == 0)
	{
		UE_LOG(LogTemp, Warning, TEXT("Patrol route contains no patrol points"));
		return EBTNodeResult::Failed;
	}

	/*
	Set NextWaypoint (AActor) Blackboard key to the AActor in PatrolPoints at the index
	specified by the NextWaypointIndex Blackboard key.
	*/
	UBlackboardComponent* BlackboardComp = OwnerComp.GetBlackboardComponent();
	int32 Index = BlackboardComp->GetValueAsInt(IndexKey.SelectedKeyName);
	BlackboardComp->SetValueAsObject(WaypointKey.SelectedKeyName, PatrolPoints[Index]);
	
	/*
	Incremement the NextWaypointIndex Blackboard key using mod operator so that we cycle
	through our patrol points.
	*/
	int NextIndex = (Index + 1) % (PatrolPoints.Num());
	BlackboardComp->SetValueAsInt(IndexKey.SelectedKeyName, NextIndex);

	return EBTNodeResult::Succeeded;
}