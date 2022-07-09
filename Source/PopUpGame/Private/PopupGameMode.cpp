// Fill out your copyright notice in the Description page of Project Settings.


#include "PopupGameMode.h"

APopupGameMode::APopupGameMode()
{
	// set default pawn class to our Blueprinted character
	//static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/Blueprints/BP_Player"));
	//DefaultPawnClass = PlayerPawnClassFinder.Class;

	// use our custom HUD class
	//HUDClass = AFPSHUD::StaticClass();
}