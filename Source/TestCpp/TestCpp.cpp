// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestCpp.h"
#include "Modules/ModuleManager.h"

class FTestCppModule final : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override
	{
		UE_LOG(LogTemp, Log, TEXT("Hello World"));
	}
};

IMPLEMENT_PRIMARY_GAME_MODULE(FTestCppModule, TestCpp, "TestCpp");
