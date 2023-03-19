// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_CheckForTags.h"

#include "CompanionController.h"
#include "Pal.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTS_CheckForTags::UBTS_CheckForTags(){
    NodeName = TEXT("check command tags");
}

void UBTS_CheckForTags::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, 
					                float DeltaSeconds){
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);    

	if(!OwnerComp.GetAIOwner()) return;
    
    ACompanionController* palAI = Cast<ACompanionController>(OwnerComp.GetAIOwner());
    if(!palAI){
        UE_LOG(LogTemp, Display, TEXT("can't cast ai controller (BTS_CheckForTags)"));
        return;
    }
    
    APal* pal = Cast<APal>(palAI->GetPawn());
    if(!pal){
        UE_LOG(LogTemp, Display, TEXT("can't cast companion (BTS_CheckForTags)"));
        return;
    }
    
    if(pal->HasCommand()){
        OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true); 
    }
    else{
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }

}