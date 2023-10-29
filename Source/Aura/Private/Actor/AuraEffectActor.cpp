// Created by Wes Gilbert through the Druid Mechanics Udemy Course


#include "Actor/AuraEffectActor.h"
#include "AbilitySystemBlueprintLibrary.h"
#include "AbilitySystemComponent.h"

AAuraEffectActor::AAuraEffectActor()
{
	PrimaryActorTick.bCanEverTick = false;
	
	SetRootComponent(CreateDefaultSubobject<USceneComponent>("SceneRoot"));

}



void AAuraEffectActor::BeginPlay()
{
	Super::BeginPlay();
	

}

void AAuraEffectActor::ApplyEffectToTarget(AActor* Target, TSubclassOf<UGameplayEffect> GameplayEffectClass)
{
	UAbilitySystemComponent* TargetAbilitySystemComponent = UAbilitySystemBlueprintLibrary::GetAbilitySystemComponent(Target);
	if (TargetAbilitySystemComponent == nullptr)return;

	check(GameplayEffectClass);

	FGameplayEffectContextHandle EffectContextHandle = TargetAbilitySystemComponent->MakeEffectContext();
	EffectContextHandle.AddSourceObject(this); //So we know what object caused this context
	FGameplayEffectSpecHandle EffectSpecHandle = TargetAbilitySystemComponent->MakeOutgoingSpec(GameplayEffectClass, 1.f, EffectContextHandle);
	TargetAbilitySystemComponent->ApplyGameplayEffectSpecToSelf(*EffectSpecHandle.Data.Get());
}


