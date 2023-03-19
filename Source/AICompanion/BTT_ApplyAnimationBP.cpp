// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_ApplyAnimationBP.h"

#include "CompanionController.h"
#include "Pal.h"

UBTT_ApplyAnimationBP::UBTT_ApplyAnimationBP(){
    NodeName = TEXT("Apply AnimBP");
}

EBTNodeResult::Type UBTT_ApplyAnimationBP::ExecuteTask(UBehaviorTreeComponent &OwnerComp, 
                                                        uint8 *NodeMemory){
    Super::ExecuteTask(OwnerComp, NodeMemory); 

    if(!OwnerComp.GetAIOwner()) return EBTNodeResult::Failed;
    
    ACompanionController* palAI = Cast<ACompanionController>(OwnerComp.GetAIOwner());
    if(!palAI){
        UE_LOG(LogTemp, Display, TEXT("can't cast ai controller (BTT_ApplyAnimationBP)"));
        return EBTNodeResult::Failed;
    }
    
    APal* pal = Cast<APal>(palAI->GetPawn());
    if(!pal){
        UE_LOG(LogTemp, Display, TEXT("can't cast companion (BTT_ApplyAnimationBP)"));
        return EBTNodeResult::Failed;
    }
    
    pal->StartDefaultAnim();

    return EBTNodeResult::Succeeded; 
}