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
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void AttackAnim();
	UFUNCTION(BlueprintCallable, Category = "Animation")
	void StartDefaultAnim();

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

private:
	void MoveForward(float axis);
	void MoveRight(float axis);

	UPROPERTY(VisibleAnywhere, Category = "Commands")
	bool waiting = false;

	UPROPERTY(VisibleAnywhere, Category = "Damage")
	float baseDamage = 35.f;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animations",
		meta = (AllowPrivateAccess = "true"))
	UAnimationAsset* attack;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Animations",
		meta = (AllowPrivateAccess = "true"))
	UAnimBlueprint* defaultMove;

	USkeletalMeshComponent* skelly;
	FTimerHandle handle;

public:
	UFUNCTION(BlueprintCallable, Category = "Companion Commands")
	void ClearCommands();
	UFUNCTION(BlueprintCallable, Category = "Companion Commands")
	void CommandWait();
	UFUNCTION(BlueprintCallable, Category = "Companion Commands")
	void CommandReturn();
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
