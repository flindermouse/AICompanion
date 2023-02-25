// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Attack.h"

#include "Companion.h"
#include "CompanionController.h"
#include "Enemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTT_Attack::UBTT_Attack(){
    NodeName = TEXT("Attack");
}

EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent &OwnerComp, 
                                    uint8 *NodeMemory){
    Super::ExecuteTask(OwnerComp, NodeMemory); 

    if(OwnerComp.GetAIOwner()){
        ACompanionController* palAI = Cast<ACompanionController>(OwnerComp.GetAIOwner());
        if(palAI){
            ACompanion* pal = Cast<ACompanion>(palAI->GetPawn());
            if(pal){
                if(OwnerComp.GetBlackboardComponent()){
                    AEnemy* enemy = Cast<AEnemy>(OwnerComp.GetBlackboardComponent()->   
                                        GetValueAsObject(GetSelectedBlackboardKey()));
                    if(enemy){
                        if(enemy->DecreaseHealth(pal->DoSomeDamage())){
                            return EBTNodeResult::Failed; // enemy is died so return false to end attack loop
                        }
                        return EBTNodeResult::Succeeded; // attack succeeded
                        
                    }
                    else{
                        UE_LOG(LogTemp, Display, TEXT("can't cast enemy (BTT_Attack)"));
                    }
                }
                else{
                    UE_LOG(LogTemp, Display, TEXT("can't get blackboard (BTT_Attack)"));
                }
            }
            else{
                UE_LOG(LogTemp, Display, TEXT("can't cast companion (BTT_Attack)"));
            }
        }
        else{
            UE_LOG(LogTemp, Display, TEXT("can't cast ai controller (BTT_Attack)"));
        }
    }

    return EBTNodeResult::Failed;
}