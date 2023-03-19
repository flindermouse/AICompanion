// Fill out your copyright notice in the Description page of Project Settings.


#include "BTS_PickupLocation.h"

#include "AIController.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

UBTS_PickupLocation::UBTS_PickupLocation(){
    NodeName = TEXT("update pickup location");
}

void UBTS_PickupLocation::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, 
					                float DeltaSeconds){
    Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);    

    if(!OwnerComp.GetAIOwner()) return;
    if(!OwnerComp.GetAIOwner()->GetPawn()) return;

    FVector startP = OwnerComp.GetAIOwner()->GetPawn()->GetActorLocation();
	FVector endP = startP + UGameplayStatics::GetPlayerPawn(GetWorld(), 0)->GetActorForwardVector() * 1000; 

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