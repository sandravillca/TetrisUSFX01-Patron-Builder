// Fill out your copyright notice in the Description page of Project Settings.


#include "Director.h"

// Sets default values
ADirector::ADirector()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirector::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void ADirector::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ADirector::SetConstructorEscenarioPlano(AActor* Constructor)
{
	//Cast the passed Actor and set the Builder
	ConstructorEscenario = Cast<IConstructorEscenario>(Constructor);
	if (!ConstructorEscenario) //Log Error if cast fails
	{
		GEngine->AddOnScreenDebugMessage(-1, 15.f, FColor::Red, TEXT("Invalid Cast! See Output log for more details"));
		UE_LOG(LogTemp, Error, TEXT("SetLodgingBuilder(): The Actor is not a LodgingBuilder! Are you sure that the Actor implements that interface ? "));
	}
}

AEscenarioPlano* ADirector::GetEscenarioPlano()
{
	if (ConstructorEscenario)
	{
		//Returns the Lodging of the Builder
		return ConstructorEscenario->GetEscenarioPlano();
	}
	//Log if the Builder is NULL
	UE_LOG(LogTemp, Error, TEXT("GetLodging(): Return nullptr"));
	return nullptr;
}

void ADirector::ConstruirEscenarioPlano()
{
	//Log if the Builder is NULL
	if (!ConstructorEscenario) {
		UE_LOG(LogTemp, Error, TEXT("ConstructLodging(): LodgingBuilder is NULL, make sure it's initialized."));
		return;
	}
	//Creates the buildings
	ConstructorEscenario->ConstruirColores();
	ConstructorEscenario->ConstruirTipoPieza();

}

