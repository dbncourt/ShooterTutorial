// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterTutorial.h"
#include "ShooterGameInstance.h"

UShooterGameInstance::UShooterGameInstance()
{
}

uint8 UShooterGameInstance::CanAddWeaponToWeaponSelected()
{
	uint8 HowManyItemsSelected = 0;
	for (FWeaponBackpackItem item : this->Backpack_Weapons)
	{
		if (item.isSelected)
		{
			++HowManyItemsSelected;
		}
	}

	return HowManyItemsSelected;
}

void UShooterGameInstance::SetBackpackItemSelected(int32 BackPackItemIndex, bool IsSelected, int32 WhichSlot)
{
	this->Backpack_Weapons[BackPackItemIndex].isSelected = IsSelected;
	this->Backpack_Weapons[BackPackItemIndex].InSlot = WhichSlot;
}