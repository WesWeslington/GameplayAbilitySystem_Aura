// Created by Wes Gilbert through the Druid Mechanics Udemy Course


#include "AbilitySystem/AuraAbilitySystemComponent.h"

void UAuraAbilitySystemComponent::AbilityActorInfoSet()
{
	OnGameplayEffectAppliedDelegateToSelf.AddUObject(this, &UAuraAbilitySystemComponent::EffectApplied);
}

void UAuraAbilitySystemComponent::EffectApplied(UAbilitySystemComponent* AbilitySystemComponent, const FGameplayEffectSpec& EffectSpec, FActiveGameplayEffectHandle ActiveEffectHandle)
{
	FGameplayTagContainer TagContainer;
	EffectSpec.GetAllAssetTags(TagContainer);

	for (const FGameplayTag& Tag : TagContainer)
	{
		//TODO: Broadcast the tag to the WidgetController

		const FString Msg = FString::Printf(TEXT("GE Tag: %s"), *Tag.ToString());
			GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Magenta, Msg);
	}
}

