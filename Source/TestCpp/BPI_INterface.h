// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "BPI_INterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UBPI_INterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class TESTCPP_API IBPI_INterface
{
	GENERATED_BODY()

	// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category ="BPI_Interact")
	void OnInteract();
};
