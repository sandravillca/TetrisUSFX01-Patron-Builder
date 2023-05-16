// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConstructorEscenario.h"
#include "Director.generated.h"

UCLASS()
class TETRISUSFX01_API ADirector : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ADirector();

private:
	//The Builder Actor, that must be a LodgingBuilder
	IConstructorEscenario* ConstructorEscenario;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	//Creates the buildings
	void ConstruirEscenarioPlano();       //Metodo para construir el escenario
	//Set the Builder Actor
	void SetConstructorEscenarioPlano(AActor* Constructor);   //Cuando construye un escenario se pasa como argumento ConstructorEscenario1

	//Get the Lodging of the Builder
	class AEscenarioPlano* GetEscenarioPlano();
};
