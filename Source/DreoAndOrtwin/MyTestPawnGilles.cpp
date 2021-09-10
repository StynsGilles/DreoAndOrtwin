// Fill out your copyright notice in the Description page of Project Settings.


#include "MyTestPawnGilles.h"

// Sets default values
AMyTestPawnGilles::AMyTestPawnGilles()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyTestPawnGilles::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyTestPawnGilles::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyTestPawnGilles::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

