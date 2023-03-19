// Fill out your copyright notice in the Description page of Project Settings.


#include "Companion.h"

#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
ACompanion::ACompanion(){
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//set collision and mesh
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("Box Collision"));
	RootComponent = boxComp;

	mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Base Mesh"));
	mesh->SetupAttachment(boxComp);
}

// Called when the game starts or when spawned
void ACompanion::BeginPlay(){
	Super::BeginPlay();
}

// Called every frame
void ACompanion::Tick(float DeltaTime){
	Super::Tick(DeltaTime);
}

void ACompanion::AttackAction(){
	//FVector impOrigin = (GetActorLocation() - 1);
	//mesh->AddRadialImpulse(impOrigin, 10.f, 10.f, ERadialImpulseFalloff::RIF_Linear, false);
}

float ACompanion::DoSomeDamage(){
	UE_LOG(LogTemp, Display, TEXT("Attacking!"));
	return baseDamage;
}