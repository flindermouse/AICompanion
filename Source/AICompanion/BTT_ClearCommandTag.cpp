// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_ClearCommandTag.h"

#include "CompanionController.h"
#include "Pal.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTT_ClearCommandTag::UBTT_ClearCommandTag(){
    NodeName = TEXT("Clear Tag");
}

EBTNodeResult::Type UBTT_ClearCommandTag::ExecuteTask(UBehaviorTreeComponent &OwnerComp, 
                                                        uint8 *NodeMemory){
    Super::ExecuteTask(OwnerComp, NodeMemory); 

    if(!OwnerComp.GetAIOwner()) return EBTNodeResult::Failed;
    
    ACompanionController* palAI = Cast<ACompanionController>(OwnerComp.GetAIOwner());
    if(!palAI){
        UE_LOG(LogTemp, Display, TEXT("can't cast ai controller (BTT_ClearCommandTag)"));
        return EBTNodeResult::Failed;
    }
    
    APal* pal = Cast<APal>(palAI->GetPawn());
    if(!pal){
        UE_LOG(LogTemp, Display, TEXT("can't cast companion (BTT_ClearCommandTag)"));
        return EBTNodeResult::Failed;
    }
    
    pal->ClearCommands();
    return EBTNodeResult::Succeeded;              
}