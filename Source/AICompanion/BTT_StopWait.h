// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_StopWait.generated.h"

/**
 * 
 */
UCLASS()
class AICOMPANION_API UBTT_StopWait : public UBTTask_BlackboardBase
{
	GENERATED_BODY()
	
public:
	UBTT_StopWait();

protected:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory);
	
};
