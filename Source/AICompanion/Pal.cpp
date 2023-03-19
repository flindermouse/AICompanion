// Fill out your copyright notice in the Description page of Project Settings.


#include "Pal.h"

#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
APal::APal(){
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void APal::BeginPlay(){
	Super::BeginPlay();	
}

// Called every frame
void APal::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void APal::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent){
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, 
							&APal::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &APal::MoveRight);
}

float APal::DoSomeDamage(){
	UE_LOG(LogTemp, Display, TEXT("Attacking!"));
	return baseDamage;
}

void APal::MoveForward(float axis){
	AddMovementInput(GetActorForwardVector() * axis);
}

void APal::MoveRight(float axis){
	AddMovementInput(GetActorRightVector() * axis);
}

void APal::ClearCommands(){
	gameplayTags.Reset();
	SetIsAttacking(false);
	SetIsWandering(false);
	EndWait();
}

void APal::CommandWait(){		
	ClearCommands();

	SetIsWaiting(true);
	GetMovementComponent()->Deactivate();

	gameplayTags.AddTag(FGameplayTag::RequestGameplayTag(FName(TEXT("Command.Wait"))));
}

void APal::CommandReturn(){
	ClearCommands();
	gameplayTags.AddTag(FGameplayTag::RequestGameplayTag(FName(TEXT("Command.Return"))));
}

void APal::CommandWander(){
	ClearCommands();

	SetIsWandering(true);
	gameplayTags.AddTag(FGameplayTag::RequestGameplayTag(FName(TEXT("Command.Wander"))));
}

void APal::EndWait(){
	if(!IsWaiting()) return;

	SetIsWaiting(false);

	// allow time for pal to stand up before turning movement back on
	GetWorld()->GetTimerManager().SetTimer(handle, this, &APal::AllowMovement, 2.f, false);
}

void APal::AllowMovement(){
	GetMovementComponent()->Activate();
}