// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGCharacterBase.h"

// Sets default values
ARPGCharacterBase::ARPGCharacterBase()
{
	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	AbilitySystemComponent = CreateDefaultSubobject<UAbilitySystemComponent>("AbilitySystemComponent");
	BaseActorAttributes = CreateDefaultSubobject<UBaseActorAttributes>("BaseAttributeSet");

	if (IsValid(AbilitySystemComponent))
	{
		AbilitySystemComponent->SetIsReplicated(true);
	}
}

// Called when the game starts or when spawned
void ARPGCharacterBase::BeginPlay()
{
	Super::BeginPlay();
	if (IsValid(AbilitySystemComponent))
	{
		BaseActorAttributes = AbilitySystemComponent->GetSet<UBaseActorAttributes>();

		AbilitySystemComponent->GetGameplayAttributeValueChangeDelegate(BaseActorAttributes->GetHealthAttribute()).AddUObject(this, &ARPGCharacterBase::HealthAttributeChanged);
	}
}

void ARPGCharacterBase::HealthAttributeChanged(const FOnAttributeChangeData& Data)
{
	OnHealthChanged(Data.NewValue);
}


// Called every frame
void ARPGCharacterBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARPGCharacterBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

