// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "PopupGameMode.generated.h"

/**
 * 
 */
UCLASS()
class POPUPGAME_API APopupGameMode : public AGameModeBase
{
	GENERATED_BODY()
	protected:

		UPROPERTY(EditDefaultsOnly, Category = "Spectating")
			TSubclassOf<AActor> SpectatingViewpointClass;

	public:

		APopupGameMode();

};
