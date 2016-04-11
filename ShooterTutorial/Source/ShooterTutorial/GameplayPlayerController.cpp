// Fill out your copyright notice in the Description page of Project Settings.

#include "ShooterTutorial.h"
#include "GameplayPlayerController.h"

AGameplayPlayerController::AGameplayPlayerController()
{
	this->MouseSensitivityMin = 0.1f;
	this->MouseSensitivityMax = 2.0f;
	this->MouseSensitivityCurrent = 1.0f;

	this->TouchSensitivityMin = 15.0f;
	this->TouchSensitivityMax = 5.0f;
	this->TouchSensitivityCurrent = 10.0f;

	this->GyroSensitivityMin = 20.0f;
	this->GyroSensitivityMax = 60.0f;
	this->GyroSensitivityCurrent = 40.0f;

	this->LastTilt = FVector(0.0f, 0.0f, 0.0f);
	this->LastTouch = FVector(0.0f, 0.0f, 0.0f);
}



EControllingDevice AGameplayPlayerController::GetCurrentControllingDevice()
{
	return this->CurrentControllingDevice;
}

void AGameplayPlayerController::SetCurrentControllingDevice(EControllingDevice NewControllingDevice)
{
	this->CurrentControllingDevice = NewControllingDevice;
}

float AGameplayPlayerController::GetSensitivity(EControllingDevice WhichDevice, bool isCurrentDevice)
{
	float LocalSensitivity = 0.0f;

	if (isCurrentDevice)
	{
		switch (this->CurrentControllingDevice)
		{
			case EControllingDevice::EMouse:
				{
					LocalSensitivity = this->MouseSensitivityCurrent;
					break;
				}
			case EControllingDevice::ETouch:
				{
					LocalSensitivity = this->TouchSensitivityCurrent;
					break;
				}
			case EControllingDevice::EGyro:
				{
					LocalSensitivity = this->GyroSensitivityCurrent;
					break;
				}
		}
	}
	else
	{
		switch (WhichDevice)
		{
			case EControllingDevice::EMouse:
				{
					LocalSensitivity = this->MouseSensitivityCurrent;
					break;
				}
			case EControllingDevice::ETouch:
				{
					LocalSensitivity = this->TouchSensitivityCurrent;
					break;
				}
			case EControllingDevice::EGyro:
				{
					LocalSensitivity = this->GyroSensitivityCurrent;
					break;
				}
		}
	}
	
	return LocalSensitivity;
}

void AGameplayPlayerController::SetSensitivity(EControllingDevice WhichDevice, float NewSensitivity)
{
	switch (WhichDevice)
	{
		case EControllingDevice::EMouse:
			{
				this->MouseSensitivityCurrent = NewSensitivity;
				break;
			}
		case EControllingDevice::ETouch:
			{
				this->TouchSensitivityCurrent = NewSensitivity;
				break;
			}
		case EControllingDevice::EGyro:
			{
				this->GyroSensitivityCurrent = NewSensitivity;
				break;
			}
	}
}

void AGameplayPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	this->InputComponent->BindAxis("MouseX", this, &AGameplayPlayerController::InputAxisMouseX);
	this->InputComponent->BindAxis("MouseY", this, &AGameplayPlayerController::InputAxisMouseY);
	this->InputComponent->BindTouch(EInputEvent::IE_Pressed, this, &AGameplayPlayerController::TouchPressed);
	this->InputComponent->BindTouch(EInputEvent::IE_Axis, this, &AGameplayPlayerController::TouchMoved);
}

bool AGameplayPlayerController::InputMotion(const FVector & Tilt, const FVector & RotationRate, const FVector & Gravity, const FVector & Acceleration)
{
	if (this->CurrentControllingDevice == EControllingDevice::EGyro)
	{
		FVector NewTilt = ((this->GyroSensitivityCurrent * Tilt) - this->LastTilt);
		this->AddPitchInput(NewTilt.Z);
		this->AddYawInput(NewTilt.X);
		this->LastTilt = NewTilt;
		return true;
	}
	return false;
}

void AGameplayPlayerController::InputAxisMouseY(float value)
{
	if (this->CurrentControllingDevice == EControllingDevice::EMouse)
	{
		this->AddPitchInput(this->MouseSensitivityCurrent * value);
	}
}

void AGameplayPlayerController::InputAxisMouseX(float value)
{
	if (this->CurrentControllingDevice == EControllingDevice::EMouse)
	{
		this->AddYawInput(this->MouseSensitivityCurrent * value);
	}
}

void AGameplayPlayerController::TouchPressed(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		this->LastTouch = Location;
	}
}

void AGameplayPlayerController::TouchMoved(ETouchIndex::Type FingerIndex, FVector Location)
{
	if (FingerIndex == ETouchIndex::Touch1)
	{
		this->AddYawInput(((Location.X - this->LastTouch.X) / this->TouchSensitivityCurrent));
		this->AddPitchInput(((Location.Y - this->LastTouch.Y) / this->TouchSensitivityCurrent));
		this->LastTouch = Location;
	}
}