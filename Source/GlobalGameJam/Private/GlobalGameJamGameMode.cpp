// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.

#include "GlobalGameJam.h"
#include "GlobalGameJamGameMode.h"
#include "GlobalGameJamCharacter.h"
#include "Robot.h"

AGlobalGameJamGameMode::AGlobalGameJamGameMode(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/Blueprints/MyCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}

	static ConstructorHelpers::FClassFinder<ARobot> RobotPawnBPClass(TEXT("/Game/Blueprints/Robot"));
	RobotCharacter = RobotPawnBPClass.Class;
}

void AGlobalGameJamGameMode::BeginPlay()
{
	FString OutError;
	UGameViewportClient* Viewport = GetWorld()->GetGameViewport();	
	
	DefaultPawnClass = RobotCharacter;
	Viewport->CreatePlayer(1, OutError, true);
	Viewport->CreatePlayer(2, OutError, true);
	Viewport->CreatePlayer(3, OutError, true);
}
