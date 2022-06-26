// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Board.h"

// Sets default values
ABP_Board::ABP_Board()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComp"));
	MeshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	RootComponent = MeshComp;
}

// Called when the game starts or when spawned
void ABP_Board::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_Board::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

