// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorEscenario2.h"
#include "EscenarioPlano.h"

// Sets default values
AConstructorEscenario2::AConstructorEscenario2()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConstructorEscenario2::BeginPlay()
{
	Super::BeginPlay();

	//Spawn the Lodging Actors
	Escenario = GetWorld()->SpawnActor<AEscenarioPlano>(AEscenarioPlano::StaticClass());
	//Attach it to the Builder (this)
	Escenario->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void AConstructorEscenario2::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConstructorEscenario2::ConstruirColores()
{
	Escenario->setColor(2);
}

void AConstructorEscenario2::ConstruirTipoPieza()
{
	std::vector<std::vector<std::pair<float, float>>> Shapes =
	{
		{{-35.0,50.0},{35.0,60.0},{-35.0,100.0},{35.0,120.0}}

	};
	Escenario->SetTipoPieza(Shapes);
}

AEscenarioPlano* AConstructorEscenario2::GetEscenarioPlano()
{
	//Returns the Lodging Actor of the Builder (this)
	return Escenario;
}
