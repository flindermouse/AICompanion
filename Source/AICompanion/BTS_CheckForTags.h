// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Services/BTService_BlackboardBase.h"

#include "BTS_CheckForTags.generated.h"

/**
 * 
 */
UCLASS()
class AICOMPANION_API UBTS_CheckForTags : public UBTService_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTS_CheckForTags();

protected:
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, 
					float DeltaSeconds) override;

};
