// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "EngineMinimal.h"

/*
* ArenaBattle 이름의 로그 카테고리를 외부에 선언
* Log : 기본 로깅 수준
* All : 모든 로깅 레벨을 허용
*/ 
DECLARE_LOG_CATEGORY_EXTERN(ArenaBattle, Log, All);
// 현재 함수 이름과 코드 라인 정보를 생성(어디서 호출되었는지 추적 가능)
#define ABLOG_CALLINFO (FString(__FUNCTION__) + TEXT("(") + FString::FromInt(__LINE__) + TEXT(")"))
#define ABLOG_S(Verbosity) UE_LOG(ArenaBattle, Verbosity, TEXT("%s"), *ABLOG_CALLINFO)
#define ABLOG(Verbosity, Format, ...) UE_LOG(ArenaBattle, Verbosity, TEXT("%s %s"), *ABLOG_CALLINFO, *FString::Printf(Format, ##__VA_ARGS__))