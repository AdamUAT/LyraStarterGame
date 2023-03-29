// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Camera/PlayerCameraManager.h"
#include "LyraPlayerCameraManager.generated.h"


#define LYRA_CAMERA_DEFAULT_FOV			(80.0f)
#define LYRA_CAMERA_DEFAULT_PITCH_MIN	(-360.0f)
#define LYRA_CAMERA_DEFAULT_PITCH_MAX	(360.0f)

class ULyraUICameraManagerComponent;

/**
 * ALyraPlayerCameraManager
 *
 *	The base player camera manager class used by this project.
 */
UCLASS(notplaceable, MinimalAPI)
class ALyraPlayerCameraManager : public APlayerCameraManager
{
	GENERATED_BODY()

public:

	ALyraPlayerCameraManager(const FObjectInitializer& ObjectInitializer);

	ULyraUICameraManagerComponent* GetUICameraComponent() const;

protected:

	virtual void UpdateViewTarget(FTViewTarget& OutVT, float DeltaTime) override;

	virtual void DisplayDebug(UCanvas* Canvas, const FDebugDisplayInfo& DebugDisplay, float& YL, float& YPos) override;

private:
	/** The UI Camera Component, controls the camera when UI is doing something important that gameplay doesn't get priority over. */
	UPROPERTY(Transient)
	ULyraUICameraManagerComponent* UICamera;
};
