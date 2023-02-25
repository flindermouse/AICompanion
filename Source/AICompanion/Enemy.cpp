// Fill out your copyright notice in the Description page of Project Settings.


#include "Enemy.h"

// Sets default values
AEnemy::AEnemy()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AEnemy::BeginPlay()
{
	Super::BeginPlay();
	
	currentHealth = maxHealth;
}

// Called every frame
void AEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

float AEnemy::GetHealthAsPercent() const{
	return currentHealth / maxHealth;
}

bool AEnemy::DecreaseHealth(float damage){
	currentHealth -= damage;
	UE_LOG(LogTemp, Display, TEXT("current health: %f"), currentHealth);
	if(currentHealth <= 0){
		DetachFromControllerPendingDestroy(); 
		Destroy();
		UE_LOG(LogTemp, Warning, TEXT("enemy destroyed"))

		return true;
	}
	return false;
}