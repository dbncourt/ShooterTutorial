// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/PlayerController.h"
#include "GameplayPlayerController.generated.h"

/**
 *
 */
UENUM(BlueprintType)		//"BlueprintType" is essential to include
enum class EControllingDevice : uint8
{
	EMouse 	UMETA(DisplayName = "Mouse"),
	ETouch 	UMETA(DisplayName = "Touch"),
	EGyro	UMETA(DisplayName = "Gyro")
};

UCLASS()
class SHOOTERTUTORIAL_API AGameplayPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGameplayPlayerController();

	UFUNCTION(BlueprintPure, Category = "Movement")
	EControllingDevice GetCurrentControllingDevice();

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void SetCurrentControllingDevice(EControllingDevice NewControllingDevice);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	float GetSensitivity(EControllingDevice WhichDevice, bool isCurrentDevice);

	UFUNCTION(BlueprintCallable, Category = "Movement")
	void SetSensitivity(EControllingDevice WhichDevice, float NewSensitivity);

protected:
	virtual void SetupInputComponent() override;

	virtual bool InputMotion(const FVector& Tilt, const FVector& RotationRate, const FVector& Gravity, const FVector& Acceleration) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MouseSensitivityMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MouseSensitivityMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float MouseSensitivityCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float TouchSensitivityMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float TouchSensitivityMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float TouchSensitivityCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float GyroSensitivityMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float GyroSensitivityMax;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	float GyroSensitivityCurrent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Movement")
	EControllingDevice CurrentControllingDevice;

private:
	void InputAxisMouseY(float value);
	void InputAxisMouseX(float value);

	void TouchPressed(ETouchIndex::Type, FVector Location);
	void TouchMoved(ETouchIndex::Type, FVector Location);

private:
	FVector LastTilt;
	FVector LastTouch;
};