// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "PixiePanicHUD.generated.h"

class UPixiePanicPlayerUI;
/**
 * 
 */
UCLASS()
class GDTV25_API APixiePanicHUD : public AHUD
{
	GENERATED_BODY()

protected:
	virtual void BeginPlay() override;
	void DrawHUD();
public:
	UPROPERTY(EditDefaultsOnly,BlueprintReadOnly,Category="UI")
	TSubclassOf<UPixiePanicPlayerUI> DefaultPlayerUI;
	UPROPERTY(Transient)
	UPixiePanicPlayerUI* CurrentUIInstance;
};
