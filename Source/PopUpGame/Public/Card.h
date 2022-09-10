// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/PlayerController.h"
#include "PGPlayerController.h"
#include "Card.generated.h"

UCLASS()
class POPUPGAME_API ACard : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	UMaterial* Highlight;

	UPROPERTY(EditAnywhere)
		UMaterial* RegularMaterial;

	UFUNCTION()
	void CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
		void CustomOnEndMouseOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
		void CustomOnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

	UFUNCTION()
		void CustomReleased(UPrimitiveComponent* TouchedComponent, FKey ButtonReleased);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		UStaticMeshComponent* MeshComp;

private:
	bool selected = false;
	FVector GameBoardPlane;
	FVector GameBoardNormal;
};
