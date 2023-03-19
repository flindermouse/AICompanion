// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_CurrentEnemyLocation.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTS_CurrentEnemyLocation::UBTS_CurrentEnemyLocation(){
    NodeName = TEXT("update current enemy location");
}

void UBTS_CurrentEnemyLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, 
					        float DeltaSeconds){
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);    

    FVector startP = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
	FVector endP = startP + UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorForwardVector() * 750; 
	//DrawDebugLine(GetWorld(), startP, endP, FColor::Red, false, 2.f, (uint8)0U, 12.f);
    //DrawDebugSphere(GetWorld(), endP, 100, 12, FColor::Red);

	FCollisionShape sphere = FCollisionShape::MakeSphere(100);
    FHitResult hitRes;
    bool hasHit = GetWorld()->SweepSingleByChannel(hitRes, startP, endP, 
								FQuat::Identity, ECC_GameTraceChannel1, sphere);

    if(hasHit){
        UE_LOG(LogTemp, Display, TEXT("enemy found!"));
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), hitRes.GetActor());        
    }
    else{
        //UE_LOG(LogTemp, Display, TEXT("no enemy seen"));
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
}