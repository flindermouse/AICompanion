// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GameplayTagAssetInterface.h"
#include "Pal.generated.h"


UCLASS()
class AICOMPANION_API APal : public ACharacter, public IGameplayTagAssetInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	APal();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:
	UFUNCTION(BlueprintCallable, Category = "Damage")
	float DoSomeDamage();
	UFUNCTION(BlueprintPure, Category = "Damage")
	float GetBaseDamage() const {return baseDamage;}
	UFUNCTION(BluePrintCallable, Category = "Damage")
	void SetBaseDamage(float newBase) {baseDamage = newBase;}

	UFUNCTION(BlueprintPure, Category = "Commands")
	bool IsWaiting() const {return waiting;}
	UFUNCTION(BlueprintCallable, Category = "Commands")
	void SetIsWaiting(bool wait) {waiting = wait;}

	UFUNCTION(BlueprintPure, Category = "Commands")
	bool IsWandering() const {return wandering;}
	UFUNCTION(BlueprintCallable, Category = "Commands")
	void SetIsWandering(bool wander) {wandering = wander;}

	UFUNCTION(BlueprintPure, Category = "Commands")
	bool IsAttacking() const {return attacking;}
	UFUNCTION(BlueprintCallable, Category = "Commands")
	void SetIsAttacking(bool attack) {attacking = attack;}


private:
	void MoveForward(float axis);
	void MoveRight(float axis);

	UPROPERTY(VisibleAnywhere, Category = "Commands")
	bool waiting = false;
	UPROPERTY(VisibleAnywhere, Category = "Commands")
	bool wandering = false;
	UPROPERTY(VisibleAnywhere, Category = "Commands")
	bool attacking = false;

	UPROPERTY(VisibleAnywhere, Category = "Damage")
	float baseDamage = 35.f;

	//for delaying movement restoration after wait command
	FTimerHandle handle;

public:
	UFUNCTION(BlueprintCallable, Category = "Companion Commands")
	void ClearCommands();
	UFUNCTION(BlueprintCallable, Category = "Companion Commands")
	void CommandWait();
	UFUNCTION(BlueprintCallable, Category = "Companion Commands")
	void CommandReturn();
	UFUNCTION(BlueprintCallable, Category = "Companion Commands")
	void CommandWander();
	UFUNCTION(BlueprintPure, Category = "Companion Commands")
	bool HasCommand() const {return !gameplayTags.IsEmpty();}

	//Gameplay Tags
	virtual void GetOwnedGameplayTags(FGameplayTagContainer& TagContainer) const override { TagContainer = gameplayTags; return; }

private:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "GameplayTags", meta = (AllowPrivateAccess = "true"))
	FGameplayTagContainer gameplayTags;

	void EndWait();
	void AllowMovement();

};
