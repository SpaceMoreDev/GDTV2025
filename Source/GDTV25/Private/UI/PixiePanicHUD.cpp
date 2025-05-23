﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "UI/PixiePanicHUD.h"

#include "UI/PixiePanicPlayerUI.h"

void APixiePanicHUD::BeginPlay()
{
	Super::BeginPlay();
	SpawnPlayerHUD();
}

void APixiePanicHUD::SpawnPlayerHUD()
{
	UPixiePanicPlayerUI* PlayerUI = Cast<UPixiePanicPlayerUI>(CreateWidget(GetWorld(), DefaultPlayerUI));
	PlayerUI->AddToViewport(0);
	CurrentUIInstance = PlayerUI;
	UE_LOG(LogTemp, Warning, TEXT("Drew HUD"));
}
