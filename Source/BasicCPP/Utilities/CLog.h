#pragma once

#include "CoreMinimal.h"

#define PrintLine() {CLog::Log(__FUNCTION__, __LINE__);}

class CLog
{
public:
	static void Print(int32 InValue, int32 InKey = -1, float InDuration = 10.f, FColor InColor = FColor::Black);
	static void Print(float InValue, int32 InKey = -1, float InDuration = 10.f, FColor InColor = FColor::Black);
	static void Print(const FString& InValue, int32 InKey = -1, float InDuration = 10.f, FColor InColor = FColor::Black);
	static void Print(const FVector& InValue, int32 InKey = -1, float InDuration = 10.f, FColor InColor = FColor::Black);
	static void Print(const FRotator& InValue, int32 InKey = -1, float InDuration = 10.f, FColor InColor = FColor::Black);

	static void Log(int32 InValue);	//CLog::Log
	static void Log(float InValue);	//CLog::Log
	static void Log(const FString& InValue);	//CLog::Log
	static void Log(const FVector& InValue);	//CLog::Log
	static void Log(const FRotator& InValue);	//CLog::Log
	static void Log(UObject* InObject);	//CLog::Log
	static void Log(const FString& InFuncName, int32 InLineNumber);	//CLog::Log

};

//DrawDebug