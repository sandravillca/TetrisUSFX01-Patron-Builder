// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorEscenario1.h"
#include "EscenarioPlano.h"
#include <vector>

// Sets default values
AConstructorEscenario1::AConstructorEscenario1()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConstructorEscenario1::BeginPlay()
{
	Super::BeginPlay();

	//Spawn the Lodging Actors
	Escenario = GetWorld()->SpawnActor<AEscenarioPlano>(AEscenarioPlano::StaticClass());
	//Attach it to the Builder (this)
	Escenario->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void AConstructorEscenario1::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConstructorEscenario1::ConstruirColores()
{
	Escenario->setColor(2);
}

void AConstructorEscenario1::ConstruirTipoPieza()
{
	std::vector<std::vector<std::pair<float, float>>> Shapes =
	{
		{{-45.0,50.0},{45.0,60.0},{-45.0,100.0},{45.0,120.0} }

	};
	Escenario->SetTipoPieza(Shapes);
}

AEscenarioPlano* AConstructorEscenario1::GetEscenarioPlano()
{
	//Returns the Lodging Actor of the Builder (this)
	return Escenario;
}

