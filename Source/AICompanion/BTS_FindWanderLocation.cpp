// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_FindWanderLocation.h"

#include "AIController.h"
#include "NavigationSystem.h"
#include "Pal.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTS_FindWanderLocation::UBTS_FindWanderLocation(){
    NodeName = TEXT("find place to go");
}

void UBTS_FindWanderLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, 
					                    float DeltaSeconds){
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);    

    if(!OwnerComp.GetAIOwner()) return;
    if(!OwnerComp.GetAIOwner()->GetPawn()) return;

    float patrolRad = 350.f;
    
    APal* pal = Cast<APal>(OwnerComp.GetAIOwner()->GetPawn());
    if(!pal) return;
    if(!pal->IsWandering()){
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
        return;
    }

    FNavLocation patrolPoint;
    const UNavigationSystemV1* navSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(this);
    bool gotPatrol = navSys->GetRandomReachablePointInRadius(OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation(), 
                                                                patrolRad, patrolPoint);
    
    if(gotPatrol){
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), patrolPoint.Location);
    }
    else{
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(), 
                                                                OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation());
    }

 
}