// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterTutorial.h"
#include "Weapon.h"


// Sets default values
AWeapon::AWeapon()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	this->RootComponent = SceneComponent;

	WeaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("WeaponMesh"));
	WeaponMesh->AttachTo(this->SceneComponent);
}

// Called when the game starts or when spawned
void AWeapon::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWeapon::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

int32 AWeapon::GetIndexInBackpack()
{
	return IndexInBackpack;
}

void AWeapon::SetIndexInBackpack(int32 IndexInBackpack)
{
	this->IndexInBackpack = IndexInBackpack;
}

FName AWeapon::GetAttachSocketName_FPP()
{
	return AttachSocketName_FPP;
}

void AWeapon::SetAttachSocketName_FPP(FName AttachSocketName_FPP)
{
	this->AttachSocketName_FPP = AttachSocketName_FPP;
}

FName AWeapon::GetAttachSocketName_TPP()
{
	return AttachSocketName_TPP;
}

void AWeapon::SetAttachSocketName_TPP(FName AttachSocketName_TPP)
{
	this->AttachSocketName_TPP = AttachSocketName_TPP;
}