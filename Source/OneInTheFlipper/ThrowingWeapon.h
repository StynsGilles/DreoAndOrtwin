// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ThrowingWeapon.generated.h"

enum class FWeaponState
{
	Held,
	Flying,
	Ragdoll
};

UCLASS()
class ONEINTHEFLIPPER_API AThrowingWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AThrowingWeapon();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UStaticMeshComponent* pUStaticMeshComponent;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	void Throw(const FVector& forceNormal);

	void HandleFlyState(float DeltaTime);

private:
	UFUNCTION()
	void OnStaticMeshComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit);

private:
	UPROPERTY(EditAnywhere)
	float FlySpeed;
	UPROPERTY(EditAnywhere)
	float RotationSpeed;

	FWeaponState WeaponState;
};
