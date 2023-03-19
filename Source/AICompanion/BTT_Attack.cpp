// Fill out your copyright notice in the Description page of Project Settings.


#include "BTT_Attack.h"

#include "CompanionController.h"
#include "Enemy.h"
#include "Pal.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTT_Attack::UBTT_Attack(){
    NodeName = TEXT("Attack");
}

EBTNodeResult::Type UBTT_Attack::ExecuteTask(UBehaviorTreeComponent &OwnerComp, 
                                    uint8 *NodeMemory){
    Super::ExecuteTask(OwnerComp, NodeMemory); 

    if(!OwnerComp.GetAIOwner()) return EBTNodeResult::Failed;
    
    ACompanionController* palAI = Cast<ACompanionController>(OwnerComp.GetAIOwner());
    if(!palAI){
        UE_LOG(LogTemp, Display, TEXT("can't cast ai controller (BTT_Attack)"));
        return EBTNodeResult::Failed;
    }
    
    APal* pal = Cast<APal>(palAI->GetPawn());
    if(!pal){
        UE_LOG(LogTemp, Display, TEXT("can't cast companion (BTT_Attack)"));
        return EBTNodeResult::Failed;
    }
    
    if(!OwnerComp.GetBlackboardComponent()){
        UE_LOG(LogTemp, Display, TEXT("can't get blackboard (BTT_Attack)"));
        return EBTNodeResult::Failed;
    }
    
    AEnemy* enemy = Cast<AEnemy>(OwnerComp.GetBlackboardComponent()->   
                        GetValueAsObject(GetSelectedBlackboardKey()));
    if(!enemy){
        UE_LOG(LogTemp, Display, TEXT("can't cast enemy (BTT_Attack)"));
        return EBTNodeResult::Failed;
    }
      
    pal->SetIsAttacking(true); 
    if(enemy->DecreaseHealth(pal->DoSomeDamage())){
        pal->SetIsAttacking(false);
        return EBTNodeResult::Failed; // no more enemy, fail to break from sequence 
    }

    return EBTNodeResult::Succeeded; // keep attacking
}