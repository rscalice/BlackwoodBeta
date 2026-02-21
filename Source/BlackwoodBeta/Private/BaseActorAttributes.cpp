// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseActorAttributes.h"
#include <Net\UnrealNetwork.h>

void UBaseActorAttributes::OnRep_Health(const FGameplayAttributeData& OldHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, Health, OldHealth);
}

void UBaseActorAttributes::OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, MaxHealth, OldMaxHealth);
}

void UBaseActorAttributes::OnRep_Stamina(const FGameplayAttributeData& OldStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, Stamina, OldStamina);
}

void UBaseActorAttributes::OnRep_MaxStamina(const FGameplayAttributeData& OldMaxStamina)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, MaxStamina, OldMaxStamina);
}

void UBaseActorAttributes::OnRep_Defense(const FGameplayAttributeData& OldDefense)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, Defense, OldDefense);
}

void UBaseActorAttributes::OnRep_Experience(const FGameplayAttributeData& OldExperience)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, Experience, OldExperience);
}

void UBaseActorAttributes::OnRep_MaxExperience(const FGameplayAttributeData& OldMaxExperience)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, MaxExperience, OldMaxExperience);
}

void UBaseActorAttributes::OnRep_Damage(const FGameplayAttributeData& OldDamage)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, Damage, OldDamage);
}

void UBaseActorAttributes::OnRep_Level(const FGameplayAttributeData& OldLevel)
{
	GAMEPLAYATTRIBUTE_REPNOTIFY(UBaseActorAttributes, Level, OldLevel);
}

void UBaseActorAttributes::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME_CONDITION_NOTIFY(UBaseActorAttributes, Health, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseActorAttributes, Stamina, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseActorAttributes, Experience, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseActorAttributes, Level, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseActorAttributes, Defense, COND_None, REPNOTIFY_Always);
	DOREPLIFETIME_CONDITION_NOTIFY(UBaseActorAttributes, Damage, COND_None, REPNOTIFY_Always);
}

void UBaseActorAttributes::PreAttributeChange(const FGameplayAttribute& Attribute, float& delta)
{
	Super::PreAttributeChange(Attribute, delta);

	if (Attribute == GetHealthAttribute())
	{
	}
}

void UBaseActorAttributes::PostGameplayEffectExecute(const FGameplayEffectModCallbackData& Data)
{
	Super::PostGameplayEffectExecute(Data);

    if (Data.EvaluatedData.Attribute == GetDamageAttribute())
    {
        // 1. Get the damage magnitude
        float LocalDamageDone = GetDamage();
        SetDamage(0.f); // 2. Reset meta-attribute

        if (LocalDamageDone > 0.f)
        {
			float defense = FMath::Clamp(GetDefense(), 0.f, 500.f);
			float newDamage = LocalDamageDone * ((1000 - defense) / 1000);
			//UE_LOGFMT(LogCore, Warning, "Defense: {defense}, DamageDone: {damage} | New Damage {new}",
			//	defense, LocalDamageDone, newDamage);

            // 3. Apply damage to Health
            float NewHealth = GetHealth() - newDamage;
            SetHealth(FMath::Clamp(NewHealth, 0.f, GetMaxHealth()));
        }
    }
    else if (Data.EvaluatedData.Attribute == GetHealthAttribute())
    {
        // 4. Handle direct health changes (e.g., healing or direct damage)
        SetHealth(FMath::Clamp(GetHealth(), 0.f, GetMaxHealth()));
    }
}
