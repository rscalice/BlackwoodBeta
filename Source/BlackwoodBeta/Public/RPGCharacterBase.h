// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "BaseActorAttributes.h"
#include "RPGCharacterBase.generated.h"

UCLASS()
class BLACKWOODBETA_API ARPGCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Attributes")
	const class UBaseActorAttributes* BaseActorAttributes;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Attributes")
	class UAbilitySystemComponent* AbilitySystemComponent;

	virtual void HealthAttributeChanged(const FOnAttributeChangeData& Data);
	virtual void StaminaAttributeChanged(const FOnAttributeChangeData& Data);
	virtual void ExperienceAttributeChanged(const FOnAttributeChangeData& Data);
	virtual void LevelAttributeChanged(const FOnAttributeChangeData& Data);

	UFUNCTION(BlueprintImplementableEvent, Category = "Base Attributes")
	void OnHealthChanged(float Health);

	UFUNCTION(BlueprintImplementableEvent, Category = "Base Attributes")
	void OnStaminaChanged(float Stamina);

	UFUNCTION(BlueprintImplementableEvent, Category = "Base Attributes")
	void OnExperienceChanged(float Experience);

	UFUNCTION(BlueprintImplementableEvent, Category = "Base Attributes")
	void OnLevelChanged(float Experience);

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
