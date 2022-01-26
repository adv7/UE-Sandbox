// Fill out your copyright notice in the Description page of Project Settings.


#include "Sword.h"
#include "Components/SkeletalMeshComponent.h"
#include "DrawDebugHelpers.h"

#define OUT

// Sets default values
ASword::ASword()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);

	Mesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("Mesh"));
	Mesh->SetupAttachment(Root);

}

// Called when the game starts or when spawned
void ASword::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASword::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ASword::SwordAttack()
{
	UE_LOG(LogTemp, Warning, TEXT("SwordAttack"));

	APawn* SwordOwner = Cast<APawn>(GetOwner());
	if (SwordOwner == nullptr) return;
	AController* SwordOwnerController = SwordOwner->GetController();
	if (SwordOwnerController == nullptr) return;

	FVector Location;
	FRotator Rotation;

	SwordOwnerController->GetPlayerViewPoint(OUT Location, OUT Rotation);


	DrawDebugCamera(GetWorld(), Location, Rotation, 90, 2, FColor::Red, true);
}
