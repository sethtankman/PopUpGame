// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
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
		UMaterial* Highlight;

	UPROPERTY(EditAnywhere)
		UMaterial* RegularMaterial;

	UFUNCTION()
		void CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent);

	UFUNCTION()
		void CustomOnEndMouseOver(UPrimitiveComponent* TouchedComponent);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
};
