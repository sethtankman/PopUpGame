// Fill out your copyright notice in the Description page of Project Settings.
#include "GridSquare.h"

// Sets default values
AGridSquare::AGridSquare()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;

	Highlight = CreateDefaultSubobject<UMaterial>(TEXT("Highlight Material"));
	RegularMaterial = CreateDefaultSubobject<UMaterial>(TEXT("Regular Material"));

	MeshComp->OnBeginCursorOver.AddDynamic(this, &AGridSquare::CustomOnBeginMouseOver);
	MeshComp->OnEndCursorOver.AddDynamic(this, &AGridSquare::CustomOnEndMouseOver);
}

// Called when the game starts or when spawned
void AGridSquare::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGridSquare::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


void AGridSquare::CustomOnBeginMouseOver(UPrimitiveComponent* TouchedComponent)
{
	MeshComp->SetMaterial(0, Highlight);
}

void AGridSquare::CustomOnEndMouseOver(UPrimitiveComponent* TouchedComponent) {
	MeshComp->SetMaterial(0, RegularMaterial);
}

