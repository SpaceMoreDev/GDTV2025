// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "PixiePanicCustomerWidget.generated.h"

class UTextBlock;
/**
 * 
 */
UCLASS()
class GDTV25_API UPixiePanicCustomerWidget : public UUserWidget
{
	GENERATED_BODY()

public:

	UPROPERTY(meta=(BindWidget))
	UTextBlock* ItemText;
	
};
