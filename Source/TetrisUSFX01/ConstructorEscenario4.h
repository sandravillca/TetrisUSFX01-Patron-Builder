// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ConstructorEscenario.h"
#include "Block.h"
#include "ConstructorEscenario4.generated.h"

UCLASS()
class TETRISUSFX01_API AConstructorEscenario4 : public AActor, public IConstructorEscenario
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AConstructorEscenario4();
private:
	//The Lodging Actor
	UPROPERTY()
		class AEscenarioPlano* Escenario;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
private:

	TArray<ABlock*> Blocks;

	UPROPERTY(EditAnywhere)
		TArray<class UMaterial*> Colors;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	virtual void ConstruirColores() override;
	virtual void ConstruirTipoPieza() override;
	virtual class AEscenarioPlano* GetEscenarioPlano() override;
	int Index;
	void getIndex(int Index);
};
