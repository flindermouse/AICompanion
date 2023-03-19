// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Stay.h"

#include "CompanionController.h"
#include "Pal.h"
#include "GameFramework/PawnMovementComponent.h"

UBTT_Stay::UBTT_Stay(){
    NodeName = TEXT("Set Wait");
}

EBTNodeResult::Type UBTT_Stay::ExecuteTask(UBehaviorTreeComponent &OwnerComp, 
                                            uint8 *NodeMemory){
    Super::ExecuteTask(OwnerComp, NodeMemory); 

    if(!OwnerComp.GetAIOwner()) return EBTNodeResult::Failed;
    
    ACompanionController* palAI = Cast<ACompanionController>(OwnerComp.GetAIOwner());
    if(!palAI){
        UE_LOG(LogTemp, Display, TEXT("can't cast ai controller (BTT_Stay)"));
        return EBTNodeResult::Failed;
    }
    
    APal* pal = Cast<APal>(palAI->GetPawn());
    if(!pal){
        UE_LOG(LogTemp, Display, TEXT("can't cast companion (BTT_Stay)"));
        return EBTNodeResult::Failed;
    }

    pal->SetIsWaiting(true);
    pal->GetMovementComponent()->StopActiveMovement();

    return EBTNodeResult::Succeeded;
}