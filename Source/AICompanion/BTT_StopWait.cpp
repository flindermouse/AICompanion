// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_StopWait.h"

#include "CompanionController.h"
#include "Pal.h"
#include "GameFramework/PawnMovementComponent.h"

UBTT_StopWait::UBTT_StopWait(){
    NodeName = TEXT("Clear Wait");
}

EBTNodeResult::Type UBTT_StopWait::ExecuteTask(UBehaviorTreeComponent &OwnerComp, 
                                            uint8 *NodeMemory){
    Super::ExecuteTask(OwnerComp, NodeMemory); 

    if(!OwnerComp.GetAIOwner()) return EBTNodeResult::Failed;
    
    ACompanionController* palAI = Cast<ACompanionController>(OwnerComp.GetAIOwner());
    if(!palAI){
        UE_LOG(LogTemp, Display, TEXT("can't cast ai controller (BTT_StopWait)"));
        return EBTNodeResult::Failed;
    }
    
    APal* pal = Cast<APal>(palAI->GetPawn());
    if(!pal){
        UE_LOG(LogTemp, Display, TEXT("can't cast companion (BTT_StopWait)"));
        return EBTNodeResult::Failed;
    }

    pal->SetIsWaiting(false);
    pal->GetMovementComponent()->ResetMoveState();

    return EBTNodeResult::Succeeded;
}