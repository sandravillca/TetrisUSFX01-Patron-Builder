// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorEscenario3.h"
#include "EscenarioPlano.h"

// Sets default values
AConstructorEscenario3::AConstructorEscenario3()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConstructorEscenario3::BeginPlay()
{
	Super::BeginPlay();

	//Spawn the Lodging Actors
	Escenario = GetWorld()->SpawnActor<AEscenarioPlano>(AEscenarioPlano::StaticClass());
	//Attach it to the Builder (this)
	Escenario->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
}

// Called every frame
void AConstructorEscenario3::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConstructorEscenario3::ConstruirColores()
{
	Escenario->setColor(2);
}

void AConstructorEscenario3::ConstruirTipoPieza()
{
	std::vector<std::vector<std::pair<float, float>>> Shapes =
	{
		{{0.0,80.0},{0.0,90.0},{0.0,100.0}}

	};
	Escenario->SetTipoPieza(Shapes);
}

AEscenarioPlano* AConstructorEscenario3::GetEscenarioPlano()
{
	//Returns the Lodging Actor of the Builder (this)
	return Escenario;
}
