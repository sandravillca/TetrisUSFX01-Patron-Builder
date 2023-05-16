// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include <functional>
#include "Block.h"
#include "EscenarioInterface.h"
#include <vector>
#include "EscenarioPlano.generated.h"

UCLASS()
class TETRISUSFX01_API AEscenarioPlano : public AActor, public IEscenarioInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AEscenarioPlano();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY()
		class USceneComponent* SceneComponent;

	UPROPERTY(EditAnywhere)
		TArray<class UMaterial*> Colors;

private:

	TArray<ABlock*> Blocks;
	int Index;
	//int color;
	int tipoColor;
	std::vector<std::vector<std::pair<float, float >> > tipoPieza;
	//std::vector<std::vector<std::pair<float, float>>> tipoPieza =
	//{

	//	{{-20.0, 0.0}, {-10.0, 0.0}, {0.0, 0.0}, {10.0, 0.0}},
	//	{{0.0, 10.0}, {0.0, 0.0}, {10.0, 0.0}, {20.0, 0.0}},
	//	{{-20.0, 0.0}, {-10.0, 0.0}, {0.0, 0.0}, {0.0, 10.0}},
	//	{{0.0, 0.0}, {10.0, 0.0}, {0.0, -10.0}, {10.0, -10.0}},
	//	{{-10.0, -10.0}, {0.0, -10.0}, {0.0, 0.0}, {10.0, 0.0}},
	//	{{-10.0, 0.0}, {0.0, 0.0}, {0.0, 10.0}, {10.0, 0.0}},
	//	{{-10.0, 0.0}, {0.0, 0.0}, {0.0, -10.0}, {10.0, -10.0}},
	//	//{{-20.0, 10.0}, {-10.0, 0.0}, {0.0, 10.0}, {10.0, 0.0}},
	//};

public:
	void SpawnBlocks();
	//int GenerarColor(int _tipoColor);
	int GetIndex() const { return Index; }
	void setColor(int _color) {
		tipoColor = _color;
		//GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Blue, TEXT("El tipo color es: ") + FString::FromInt(tipoColor));
	}
	int getTipoColor() {
		return tipoColor;
	}

	void SetTipoPieza(std::vector<std::vector<std::pair<float, float>>> _tipoPieza) {
		tipoPieza = _tipoPieza;
	}
};
