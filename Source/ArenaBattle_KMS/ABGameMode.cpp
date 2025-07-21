// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"
#include "ABPawn.h"
#include "ABPlayerController.h"

AABGameMode::AABGameMode()
{
	DefaultPawnClass = AABPawn::StaticClass();
	PlayerControllerClass = AABPlayerController::StaticClass();
	
	// 블루프린트 클래스 가져와서 사용하기
	/*static ConstructorHelpers::FClassFinder<APawn> BP_PAWN(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter.ThirdPersonCharacter"));
	if (BP_PAWN.Succeeded())
	{
		DefaultPawnClass = BP_PAWN.Class;
	}*/
}

void AABGameMode::PostLogin(APlayerController* NewPlayer)
{
	ABLOG(Warning, TEXT("PostLogin Begin"));
	Super::PostLogin(NewPlayer);
	ABLOG(Warning, TEXT("PostLogin End"));
}