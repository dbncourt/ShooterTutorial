// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Weapon.generated.h"

UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EWeaponType : uint8
{
	EPistol UMETA(DisplayName = "Pistol"),
	ERifle  UMETA(DisplayName = "Rifle"),
	EShotgun UMETA(DisplayName = "Shotgun")
};

UCLASS()
class SHOOTERTUTORIAL_API AWeapon : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeapon();

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void Tick( float DeltaSeconds ) override;

	UFUNCTION(BlueprintPure, Category = "Weapon")
	int32 GetIndexInBackpack();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetIndexInBackpack(int32 IndexInBackpack);

	UFUNCTION(BlueprintPure, Category = "Weapon")
	FName GetAttachSocketName_FPP();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetAttachSocketName_FPP(FName AttachSocketName_FPP);

	UFUNCTION(BlueprintPure, Category = "Weapon")
	FName GetAttachSocketName_TPP();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
	void SetAttachSocketName_TPP(FName AttachSocketName_TPP);

protected:
	USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USkeletalMeshComponent* WeaponMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Meta = (ExposeOnSpawn = true))
	int32 IndexInBackpack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName AttachSocketName_FPP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FName AttachSocketName_TPP;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	EWeaponType WeaponType;
};