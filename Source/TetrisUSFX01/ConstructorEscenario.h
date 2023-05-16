// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "ConstructorEscenario.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UConstructorEscenario : public UInterface
{
	GENERATED_BODY()
};

/**
 *
 */
class TETRISUSFX01_API IConstructorEscenario
{
	GENERATED_BODY()

		// Add interface functions to this class. This is the class that will be inherited to implement this interface.
public:
	virtual void ConstruirColores() = 0;
	virtual void ConstruirTipoPieza() = 0;
	virtual class AEscenarioPlano* GetEscenarioPlano() = 0;
};
