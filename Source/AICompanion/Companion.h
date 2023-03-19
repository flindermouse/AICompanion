// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Companion.generated.h"

UCLASS()
class AICOMPANION_API ACompanion : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACompanion();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UFUNCTION(BlueprintCallable, Category = "Action")
	void AttackAction();
	UFUNCTION(BlueprintCallable, Category = "Damage")
	float DoSomeDamage();
	UFUNCTION(BlueprintPure, Category = "Damage")
	float GetBaseDamage() const {return baseDamage;}
	UFUNCTION(BluePrintCallable, Category = "Damage")
	void SetBaseDamage(float newBase) {baseDamage = newBase;}

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, 
		Category = "Components", meta = (AllowPrivateAccess = "true"))
	class UBoxComponent* boxComp;
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, 
		Category = "Components", meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* mesh;

	UPROPERTY(VisibleAnywhere, Category = "Damage")
	float baseDamage = 35.f;
};
