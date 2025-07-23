// Fill out your copyright notice in the Description page of Project Settings.


#include "ABPlayerController.h"

void AABPlayerController::PostInitializeComponents()
{
	Super::PostInitializeComponents();
	ABLOG_S(Warning);
}

void AABPlayerController::OnPossess(APawn* aPawn)
{
	ABLOG_S(Warning);
	Super::OnPossess(aPawn);
}

void AABPlayerController::BeginPlay() 
{
	Super::BeginPlay();

	/*
	* FInputModeGameOnly : 키보드와 마우스 입력이 오직 게임에만 전달
	* FInputModeUIOnly : UI에만 입력(ex:메뉴화면)
	* FInputModeGameAndUI
	*/
	FInputModeGameOnly InputMode;
	SetInputMode(InputMode);
}