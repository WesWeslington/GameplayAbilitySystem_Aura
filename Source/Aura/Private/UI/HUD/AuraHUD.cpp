// Created by Wes Gilbert through the Druid Mechanics Udemy Course


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/AuraUserWidget.h"
void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

	UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(), OverlayWidgetClass);
	Widget->AddToViewport();
}
