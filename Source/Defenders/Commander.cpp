// Fill out your copyright notice in the Description page of Project Settings.

#include "Commander.h"
#include "Components/InputComponent.h"
#include "ConstructorHelpers.h"

// Sets default values
ACommander::ACommander()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	comboCount = 1;
}

// Called when the game starts or when spawned
void ACommander::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACommander::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);


}

// Called to bind functionality to input
void ACommander::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ACommander::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ACommander::MoveRight);

}


void ACommander::MoveForward(float amount)
{
	if (Controller && amount)
	{
		AddMovementInput(GetActorForwardVector(), amount);
	}

}

void ACommander::MoveRight(float amount)
{
	if (Controller && amount)
	{
		AddMovementInput(GetActorRightVector(), amount);
	}
}
