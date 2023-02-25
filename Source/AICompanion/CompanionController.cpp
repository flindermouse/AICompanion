// Fill out your copyright notice in the Description page of Project Settings.


#include "CompanionController.h"

#include "BehaviorTree/BlackboardComponent.h"
#include "Kismet/GameplayStatics.h"

void ACompanionController::BeginPlay(){
    Super::BeginPlay();

    if(behave){
        RunBehaviorTree(behave);        
    }
}