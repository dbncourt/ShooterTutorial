// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Weapon.h"
#include "Engine/GameInstance.h"
#include "ShooterGameInstance.generated.h"

USTRUCT()
struct FWeaponBackpackItem
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	AWeapon* WeaponToSpawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	UTexture2D* BackpackImage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	bool isSelected;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	int32 InSlot;

	FWeaponBackpackItem()
	{
		WeaponToSpawn = nullptr;
		BackpackImage = nullptr;
		isSelected = false;
		InSlot = 0;
	}

	void Destroy()
	{
		WeaponToSpawn = nullptr;
		BackpackImage = nullptr;
	}
};

/**
*
*/
UCLASS()
class SHOOTERTUTORIAL_API UShooterGameInstance : public UGameInstance
{
	GENERATED_BODY()

	UShooterGameInstance();

public:
	UFUNCTION(BlueprintCallable, Category = "Items")
	uint8 CanAddWeaponToWeaponSelected();

	UFUNCTION(BlueprintCallable, Category = "Items")
	void SetBackpackItemSelected(int32 BackPackItemIndex, bool IsSelected, int32 WhichSlot);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Items")
	TArray<FWeaponBackpackItem> Backpack_Weapons;

};
