// Fill out your copyright notice in the Description page of Project Settings.


#include "Companion.h"

// Sets default values
ACompanion::ACompanion()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACompanion::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACompanion::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACompanion::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float ACompanion::DoSomeDamage(){
	UE_LOG(LogTemp, Display, TEXT("Attacking!"));
	return baseDamage;
}