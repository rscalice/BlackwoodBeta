#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AbilitySystemComponent.h"
#include "GameplayEffectExtension.h"
#include "BaseActorAttributes.generated.h"

#define ATTRIBUTE_ACCESSORS(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_PROPERTY_GETTER(ClassName, PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_GETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_SETTER(PropertyName) \
	GAMEPLAYATTRIBUTE_VALUE_INITTER(PropertyName)


/**
 *
 */
UCLASS()
class BLACKWOODBETA_API UBaseActorAttributes : public UAttributeSet
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Attributes", ReplicatedUsing = OnRep_Level)
	FGameplayAttributeData Level;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, Level);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Attributes", ReplicatedUsing = OnRep_Health)
	FGameplayAttributeData Health;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, Health);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Attributes", ReplicatedUsing = OnRep_MaxHealth)
	FGameplayAttributeData MaxHealth;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, MaxHealth);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Attributes", ReplicatedUsing = OnRep_Stamina)
	FGameplayAttributeData Stamina;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, Stamina);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Attributes", ReplicatedUsing = OnRep_MaxStamina)
	FGameplayAttributeData MaxStamina;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, MaxStamina);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Attributes", ReplicatedUsing = OnRep_Experience)
	FGameplayAttributeData Experience;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, Experience);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Attributes", ReplicatedUsing = OnRep_MaxExperience)
	FGameplayAttributeData MaxExperience;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, MaxExperience);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Attributes", ReplicatedUsing = OnRep_Defense)
	FGameplayAttributeData Defense;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, Defense);

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Base Attributes", ReplicatedUsing = OnRep_Damage)
	FGameplayAttributeData Damage;
	ATTRIBUTE_ACCESSORS(UBaseActorAttributes, Damage);


	UFUNCTION()
	virtual void OnRep_Level(const FGameplayAttributeData& OldLevel);

	UFUNCTION()
	virtual void OnRep_Health(const FGameplayAttributeData& OldHealth);

	UFUNCTION()
	virtual void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth);

	UFUNCTION()
	virtual void OnRep_Stamina(const FGameplayAttributeData& OldStamina);

	UFUNCTION()
	virtual void OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina);

	UFUNCTION()
	virtual void OnRep_Experience(const FGameplayAttributeData& OldExperience);

	UFUNCTION()
	virtual void OnRep_MaxExperience(const FGameplayAttributeData& OldMaxExperience);

	UFUNCTION()
	virtual void OnRep_Defense(const FGameplayAttributeData& OldDefense);


	UFUNCTION()
	virtual void OnRep_Damage(const FGameplayAttributeData& OldDamage);

	virtual void GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const;

	virtual void PreAttributeChange(const FGameplayAttribute& Attribute, float & delta);

	virtual void PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data);
};