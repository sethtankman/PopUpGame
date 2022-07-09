// Fill out your copyright notice in the Description page of Project Settings.


#include "PGPlayerController.h"

void APGPlayerController::BeginPlay()
{
	Super::BeginPlay();

	bShowMouseCursor = true;
	bEnableMouseOverEvents = true;
}