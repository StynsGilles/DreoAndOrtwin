// Fill out your copyright notice in the Description page of Project Settings.


#include "ThrowingWeapon.h"

// Sets default values
AThrowingWeapon::AThrowingWeapon()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create a static mesh component and attach it to the root component
	pUStaticMeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(FName("StaticMeshComponent"));
	pUStaticMeshComponent->AttachToComponent(RootComponent, FAttachmentTransformRules::KeepRelativeTransform);
	SetRootComponent(pUStaticMeshComponent);

	// Enable physics
	pUStaticMeshComponent->SetCollisionEnabled(ECollisionEnabled::PhysicsOnly);
	pUStaticMeshComponent->SetSimulatePhysics(true);
}

// Called when the game starts or when spawned
void AThrowingWeapon::BeginPlay()
{
	Super::BeginPlay();

	// Setup component functions
	pUStaticMeshComponent->OnComponentHit.AddDynamic(this, &AThrowingWeapon::OnStaticMeshComponentHit);
}

// Called every frame
void AThrowingWeapon::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	switch (WeaponState)
	{
	case FWeaponState::Held:
		break;
	case FWeaponState::Flying:
		HandleFlyState(DeltaTime);
		break;
	default:;
	}
}

void AThrowingWeapon::Throw(const FVector& forceNormal)
{
	WeaponState = FWeaponState::Flying;

	// Launch the projectile

	// TODO: Alter vector so that the weapon is thrown in an arc
	const FVector launchImpulse{ forceNormal * 5000.f };
	pUStaticMeshComponent->AddImpulse((launchImpulse));
}

void AThrowingWeapon::HandleFlyState(float DeltaTime)
{
	// Handle rotation while flying
	const FRotator flyingRotationDelta{ -RotationSpeed, 0.f, 0.f };
	pUStaticMeshComponent->AddLocalRotation(flyingRotationDelta);
}

void AThrowingWeapon::OnStaticMeshComponentHit(UPrimitiveComponent* HitComponent, AActor* OtherActor,
	UPrimitiveComponent* OtherComponent, FVector NormalImpulse, const FHitResult& Hit)
{
	WeaponState = FWeaponState::Ragdoll;
	//UE_LOG(LogTemp, Warning, TEXT("Weapon hit: %s"), *OtherActor->GetName());
}

