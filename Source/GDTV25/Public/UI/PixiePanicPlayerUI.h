// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PixiePanicPlayerUI.generated.h"

class UTextBlock;
class UPixiePanicBar;
/**
 * 
 */
UCLASS(Blueprintable)
class GDTV25_API UPixiePanicPlayerUI : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(meta = (BindWidget))
	UPixiePanicBar* HealthBar;

	UPROPERTY(meta = (BindWidget))
	UTextBlock* WaveCount;
};
