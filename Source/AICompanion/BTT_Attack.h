// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"

#include "BTT_Attack.generated.h"

/**
 * 
 */
UCLASS()
class AICOMPANION_API UBTT_Attack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_Attack();

protected:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory);
	
};
