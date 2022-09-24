// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PGPlayerController.h"
#include "Card.h"
#include "GridSquare.generated.h"

UCLASS()
class POPUPGAME_API AGridSquare : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AGridSquare();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(VisibleAnywhere, Category = "Components")
	UStaticMeshComponent* MeshComp;

	UPROPERTY(EditAnywhere)
		UMaterial* Moveable;

	UPROPERTY(EditAnywhere)
		UMaterial* Highlight;

	UPROPERTY(EditAnywhere)
		UMaterial* RegularMaterial;

	UPROPERTY(EditAnywhere)
	FIntPoint coordinates;

	UFUNCTION()
		void CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
		void CustomOnEndMouseOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
		void CustomOnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	int activeCntr = 0;
};
