#include "CLog.h"

DEFINE_LOG_CATEGORY_STATIC(GamePlay, Warning, All)

void CLog::Print(int32 InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, FString::FromInt(InValue));
}

void CLog::Print(float InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, FString::SanitizeFloat(InValue));
}

void CLog::Print(const FString& InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, InValue);
}

void CLog::Print(const FVector& InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, InValue.ToString());
}

void CLog::Print(const FRotator& InValue, int32 InKey, float InDuration, FColor InColor)
{
	GEngine->AddOnScreenDebugMessage(InKey, InDuration, InColor, InValue.ToString());
}

void CLog::Log(int32 InValue)
{
	UE_LOG(GamePlay, Warning, TEXT("%d"), InValue);
}

void CLog::Log(float InValue)
{
	UE_LOG(GamePlay, Warning, TEXT("%f"), InValue);
}

void CLog::Log(const FString& InValue)
{
	UE_LOG(GamePlay, Warning, TEXT("%s"), *InValue);
}

void CLog::Log(const FVector& InValue)
{
	UE_LOG(GamePlay, Warning, TEXT("%s"), *InValue.ToString());
}

void CLog::Log(const FRotator& InValue)
{
	UE_LOG(GamePlay, Warning, TEXT("%s"), *InValue.ToString());
}

void CLog::Log(UObject* InObject)
{
	FString Message;
	if (InObject)
	{
		Message.Append(InObject->GetName());
	}

	Message.Append(InObject ? " is not null" : "NULL");

	UE_LOG(GamePlay, Warning, TEXT("%s"), *Message);
}

void CLog::Log(const FString& InFuncName, int32 InLineNumber)
{
	FString Message;
	Message.Append(InFuncName);
	Message.Append(", ");
	Message.Append(FString::FromInt(InLineNumber));

	UE_LOG(GamePlay, Warning, TEXT("%s"), *Message);
}
