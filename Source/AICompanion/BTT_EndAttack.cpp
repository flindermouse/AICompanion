// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_EndAttack.h"

#include "CompanionController.h"
#include "Pal.h"

UBTT_EndAttack::UBTT_EndAttack(){
    NodeName = TEXT("End Attack");
}

EBTNodeResult::Type UBTT_EndAttack::ExecuteTask(UBehaviorTreeComponent &OwnerComp, 
                                    uint8 *NodeMemory){
    Super::ExecuteTask(OwnerComp, NodeMemory); 

    if(!OwnerComp.GetAIOwner()){
        UE_LOG(LogTemp, Display, TEXT("can't get controller (BTT_EndAttack)"));
        return EBTNodeResult::Failed;
    } 
    
    ACompanionController* palAI = Cast<ACompanionController>(OwnerComp.GetAIOwner());
    if(!palAI){
        UE_LOG(LogTemp, Display, TEXT("can't cast ai controller (BTT_EndAttack)"));
        return EBTNodeResult::Failed;
    }
    
    APal* pal = Cast<APal>(palAI->GetPawn());
    if(!pal){
        UE_LOG(LogTemp, Display, TEXT("can't cast companion (BTT_EndAttack)"));
        return EBTNodeResult::Failed;
    }
      
    UE_LOG(LogTemp, Display, TEXT("ending attack"));  
    pal->SetIsAttacking(false); 

    return EBTNodeResult::Succeeded; 
}