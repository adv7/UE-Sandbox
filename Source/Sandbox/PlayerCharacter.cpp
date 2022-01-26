// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerCharacter.h"
#include "Sword.h"

// Sets default values
APlayerCharacter::APlayerCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void APlayerCharacter::BeginPlay()
{
	Super::BeginPlay();
	
	Sword = GetWorld()->SpawnActor<ASword>(SwordClass);
	Sword->AttachToComponent(GetMesh(), FAttachmentTransformRules::KeepRelativeTransform, TEXT("SwordSocket"));
	Sword->SetOwner(this);

}

// Called every frame
void APlayerCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void APlayerCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("FastAttack"), EInputEvent::IE_Pressed, this, &APlayerCharacter::Attack);

}

void APlayerCharacter::Attack()
{
	Sword->SwordAttack();
}
