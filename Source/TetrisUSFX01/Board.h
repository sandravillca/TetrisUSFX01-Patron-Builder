// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "EscenarioPlano.h"
#include "Piece.h"
#include "Board.generated.h"

UCLASS()
class TETRISUSFX01_API ABoard : public APawn
{
	GENERATED_BODY()


public:
	// Sets default values for this pawn's properties

	ABoard();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY()
		APiece* CurrentPiece;
	UPROPERTY()
		AEscenarioPlano* CurrentEscenario;

	void Rotate();
	void MoveLeft();
	void MoveRight();
	void MoveDown();
	void NewPiece();
	void CheckLine();
	void MoveDownToEnd();


	void CambiarNivel();
	int Random = 0;
private:

	enum PieceStatus { PS_NOT_INITED, PS_MOVING, PS_GOT_BOTTOM };
	PieceStatus Status = PS_NOT_INITED;

	const float CoolDown = 0.5f;
	float CoolLeft = 0.5f;
	bool bGameOver = false;

	bool CheckGameOver();

	UPROPERTY(VisibleAnywhere, Category = "Main")
		class AConstructorEscenario1* ConstructorEscenario1;

	UPROPERTY(VisibleAnywhere, Category = "Main")
		class AConstructorEscenario2* ConstructorEscenario2;

	UPROPERTY(VisibleAnywhere, Category = "Main")
		class AConstructorEscenario3* ConstructorEscenario3;
	UPROPERTY(VisibleAnywhere, Category = "Main")
		class ADirector* Director;
};
