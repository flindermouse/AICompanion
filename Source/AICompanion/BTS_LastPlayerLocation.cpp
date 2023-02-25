// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_LastPlayerLocation.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTS_LastPlayerLocation::UBTS_LastPlayerLocation(){
    NodeName = TEXT("update last known location");
}

void UBTS_LastPlayerLocation::TickNode(UBehaviorTreeComponent& OwnerComp, 
        uint8* NodeMemory, float DeltaSeconds){
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

    APawn* player = UGameplayStatics::GetPlayerPawn(GetWorld(), 0);
    if(player){
        OwnerComp.GetBlackboardComponent()->SetValueAsVector(GetSelectedBlackboardKey(),
                    player->GetActorLocation());
    }
} 