// Copyright 1998-2014 Epic Games, Inc. All Rights Reserved.
#pragma once
#include "GameFramework/GameMode.h"
#include "GlobalGameJamGameMode.generated.h"

UCLASS(minimalapi)
class AGlobalGameJamGameMode : public AGameMode
{
	GENERATED_BODY()
	
	virtual void BeginPlay();

public:
	AGlobalGameJamGameMode(const FObjectInitializer& ObjectInitializer);

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = RobotPawn)
	TSubclassOf<APawn> RobotCharacter;

};



