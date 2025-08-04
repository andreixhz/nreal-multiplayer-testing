// Copyright Epic Games, Inc. All Rights Reserved.


#include "MiguelMauseMPPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "MiguelMauseMPCameraManager.h"

AMiguelMauseMPPlayerController::AMiguelMauseMPPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = AMiguelMauseMPCameraManager::StaticClass();
}

void AMiguelMauseMPPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}
