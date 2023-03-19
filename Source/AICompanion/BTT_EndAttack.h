// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "BehaviorTree/Tasks/BTTask_BlackboardBase.h"
#include "BTT_EndAttack.generated.h"

/**
 * 
 */
UCLASS()
class AICOMPANION_API UBTT_EndAttack : public UBTTask_BlackboardBase
{
	GENERATED_BODY()

public:
	UBTT_EndAttack();

protected:
	EBTNodeResult::Type ExecuteTask(UBehaviorTreeComponent &OwnerComp, uint8 *NodeMemory);

};
