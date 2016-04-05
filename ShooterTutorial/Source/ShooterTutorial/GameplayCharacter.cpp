// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterTutorial.h"
#include "GameplayCharacter.h"


// Sets default values
AGameplayCharacter::AGameplayCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	this->bUseControllerRotationYaw = false;

	this->GetMesh()->bOwnerNoSee = true;

	this->Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));
	this->Camera->AttachTo(this->RootComponent);
	this->Camera->bUsePawnControlRotation = true;
	this->Camera->SetRelativeLocation(FVector(0.0f, 0.0f, 76.0f));

	this->FPPMesh = CreateDefaultSubobject<USkeletalMeshComponent>(TEXT("FPPMesh"));
	this->FPPMesh->AttachTo(this->Camera);
	this->FPPMesh->bOnlyOwnerSee = true;
}

// Called when the game starts or when spawned
void AGameplayCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AGameplayCharacter::Tick( float DeltaTime )
{
	Super::Tick( DeltaTime );

}

// Called to bind functionality to input
void AGameplayCharacter::SetupPlayerInputComponent(class UInputComponent* InputComponent)
{
	Super::SetupPlayerInputComponent(InputComponent);

}

