// Fill out your copyright notice in the Description page of Project Settings.

#include "Runtime/Engine/Classes/Engine/World.h"
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
	MeshComp->OnClicked.AddDynamic(this, &ACard::CustomOnClicked);
	MeshComp->OnReleased.AddDynamic(this, &ACard::CustomReleased);

	// When we have more cards, make a database or something to fetch data from.
	energy = 2;
	startPoint = FIntPoint(4, 1);
	coordinates = startPoint;
}

// Called when the game starts or when spawned
void ACard::BeginPlay()
{
	Super::BeginPlay();
	
	TArray<AActor*> foundActors;
	UGameplayStatics::GetAllActorsOfClass(this, ABP_Board::StaticClass(), foundActors);
	if (foundActors.Num() > 0)
	{
		GameBoard = (ABP_Board*)foundActors[0];
		UE_LOG(LogTemp, Warning, TEXT("GameBoard found!"));
	}
	else {
		UE_LOG(LogTemp, Warning, TEXT("GameBoard Not found!"));
	}

	MeshComp->SetMaterial(0, RegularMaterial);
	GameBoardPlane = FVector(0, 0, 1);
	GameBoardNormal = FVector(0, 0, 1);
}

// Called every frame
void ACard::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	/*if (beingDragged) {
		// WorldLocation = GetActorLocation();
		// FVector WorldDirection = GetActorForwardVector();
		float mouseX;
		float mouseY;
		UGameplayStatics::GetPlayerController(GetWorld(), 0)->GetMousePosition(mouseX, mouseY);
		MeshComp->SetWorldLocation(FVector::PointPlaneProject(FVector(-mouseX + 700, -mouseY + 500, 0), GameBoardPlane, GameBoardNormal));
	} */
	if (selected) {
		for (FConstPlayerControllerIterator Iterator = GetWorld()->GetPlayerControllerIterator(); Iterator; ++Iterator)
		{
			APlayerController* PlayerController = Iterator->Get();
			if (APGPlayerController* pc = Cast<APGPlayerController>(PlayerController))
			{
				if (pc->selectedSquare.IsNearlyZero(0.001f) == false) {
					MeshComp->SetWorldLocation(pc->selectedSquare);
					MeshComp->SetWorldRotation(FRotator(180,0,180));
					selected = false;
					MeshComp->SetMaterial(0, RegularMaterial);
					pc->selectedSquare = FVector(0, 0, 0);
				}
			}
		}
	}
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
	if (selected == false)
		MeshComp->SetMaterial(0, RegularMaterial);
}

void ACard::CustomOnClicked(UPrimitiveComponent* TouchedComponent, FKey ButtonPressed) {
	//Convertmouselocationtoworldspace
	selected = !selected;
	if (selected)
	{

	}
	UE_LOG(LogTemp, Warning, TEXT("Your message"));
}

void ACard::CustomReleased(UPrimitiveComponent* TouchedComponent, FKey ButtonReleased) {
	//selected = false;
}