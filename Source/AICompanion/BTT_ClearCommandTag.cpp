// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_ClearCommandTag.h"

#include "AICompanionCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTT_ClearCommandTag::UBTT_ClearCommandTag(){
    NodeName = TEXT("Clear Tag");
}

EBTNodeResult::Type UBTT_ClearCommandTag::ExecuteTask(UBehaviorTreeComponent &OwnerComp, 
                                    uint8 *NodeMemory){
    Super::ExecuteTask(OwnerComp, NodeMemory); 

    if(OwnerComp.GetBlackboardComponent()){
        AAICompanionCharacter* player = Cast<AAICompanionCharacter>(OwnerComp.GetBlackboardComponent()->   
                                            GetValueAsObject(GetSelectedBlackboardKey()));
        if(player){
            player->ClearCommands();
            return EBTNodeResult::Succeeded; // attack succeeded
            
        }
        else{
            UE_LOG(LogTemp, Display, TEXT("can't cast player (BTT_Clear)"));
        }
    }
    else{
        UE_LOG(LogTemp, Display, TEXT("can't get blackboard (BTT_Clear)"));
    }
            

    return EBTNodeResult::Failed;
}