// Created by Wes Gilbert through the Druid Mechanics Udemy Course


#include "Character/AuraCharacter.h"
#include "Player/AuraPlayerState.h"
#include "Player/AuraPlayerController.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "UI/HUD/AuraHUD.h"

AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;

}

void AAuraCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	//Init on the server
	InitAbilityActorInfo();


}

void AAuraCharacter::OnRep_PlayerState()
{

	Super::OnRep_PlayerState();

	//Init on the client
	InitAbilityActorInfo();

}

void AAuraCharacter::InitAbilityActorInfo()
{

	//Super::InitAbilityActorInfo();

	AAuraPlayerState* AuraPlayerState = GetPlayerState<AAuraPlayerState>();
	check(AuraPlayerState);
	AuraPlayerState->GetAbilitySystemComponent()->InitAbilityActorInfo(AuraPlayerState, this);

	AbilitySystemComponent = AuraPlayerState->GetAbilitySystemComponent();
	Cast<UAuraAbilitySystemComponent>(AuraPlayerState->GetAbilitySystemComponent())->AbilityActorInfoSet();

	AttributeSet = AuraPlayerState->GetAttributeSet();

	//Initialize Overlay in HUD
	if (AAuraPlayerController* AuraPlayerController = Cast<AAuraPlayerController>(GetController()))
	{
		if (AAuraHUD* AuraHUD = Cast<AAuraHUD>(AuraPlayerController->GetHUD()))
		{
			AuraHUD->InitOverlay(AuraPlayerController, AuraPlayerState, AbilitySystemComponent, AttributeSet);
		}
	}
}

