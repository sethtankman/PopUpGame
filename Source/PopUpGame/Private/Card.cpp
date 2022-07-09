// Fill out your copyright notice in the Description page of Project Settings.


#include "Card.h"

// Sets default values
ACard::ACard()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	Highlight = CreateDefaultSubobject<UMaterial>(TEXT("Highlight Material"));
	RegularMaterial = CreateDefaultSubobject<UMaterial>(TEXT("Regular Material"));

	MeshComp->OnBeginCursorOver.AddDynamic(this, &ACard::CustomOnBeginMouseOver);
	MeshComp->OnEndCursorOver.AddDynamic(this, &ACard::CustomOnEndMouseOver);
}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
	
	MeshComp->SetMaterial(0, RegularMaterial);
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACard::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


void ACard::CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent)
{
	MeshComp->SetMaterial(0, Highlight);
}

void ACard::CustomOnEndMouseOver(UPrimitiveComponent* TouchedComponent) {
	MeshComp->SetMaterial(0, RegularMaterial);
}