// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "MyTestPawnGilles.generated.h"

UCLASS()
class DREOANDORTWIN_API AMyTestPawnGilles : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyTestPawnGilles();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	float health;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
