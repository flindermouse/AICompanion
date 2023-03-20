// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_PickupLocation.h"

#include "AIController.h"
#include "Pal.h"
#include "BehaviorTree/BlackboardComponent.h"

UBTS_PickupLocation::UBTS_PickupLocation(){
    NodeName = TEXT("update pickup location");
}

void UBTS_PickupLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, 
					                float DeltaSeconds){
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);    

    if(!OwnerComp.GetAIOwner()) return;

    APal* pal = Cast<APal>(OwnerComp.GetAIOwner()->GetPawn());
    if(!pal) return;

    FVector startP = pal->GetActorLocation();
	FVector endP = startP + pal->GetActorForwardVector() * 1000; 

	FCollisionShape sphere = FCollisionShape::MakeSphere(150);
    FHitResult hitRes;
    bool hasHit = GetWorld()->SweepSingleByChannel(hitRes, startP, endP, 
								                    FQuat::Identity, ECC_GameTraceChannel2, sphere);

    if(hasHit){
        UE_LOG(LogTemp, Display, TEXT("pickup found!"));
        OwnerComp.GetBlackboardComponent()->SetValueAsObject(GetSelectedBlackboardKey(), hitRes.GetActor());        
    }
    else{
        OwnerComp.GetBlackboardComponent()->ClearValue(GetSelectedBlackboardKey());
    }
}