// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_CheckForTags.h"

#include "AICompanionCharacter.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTS_CheckForTags::UBTS_CheckForTags(){
    NodeName = TEXT("check command tags");
}

void UBTS_CheckForTags::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, 
					        float DeltaSeconds){
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);    

	AAICompanionCharacter* player = Cast<AAICompanionCharacter>(UGameplayStatics::GetPlayerPawn(GetWorld(), 0)); 

    if(player){
        if(!player->Tags.IsEmpty()){
            OwnerComp.GetBlackboardComponent()->SetValueAsBool(GetSelectedBlackboardKey(), true); 
        }
        else{
            OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
        }
    }
    else{
        UE_LOG(LogTemp, Display, TEXT("unable to cast player (bts_check4tags)"));
    }

}