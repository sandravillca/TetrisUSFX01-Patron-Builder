// Fill out your copyright notice in the Description page of Project Settings.


#include "ConstructorEscenario4.h"
#include "EscenarioPlano.h"
#include <vector>

// Sets default values
AConstructorEscenario4::AConstructorEscenario4()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AConstructorEscenario4::BeginPlay()
{
	Super::BeginPlay();
	
	//Spawn the Lodging Actors
	Escenario = GetWorld()->SpawnActor<AEscenarioPlano>(AEscenarioPlano::StaticClass());
	//Attach it to the Builder (this)
	Escenario->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called every frame
void AConstructorEscenario4::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AConstructorEscenario4::ConstruirColores()
{
	Escenario->setColor(2);
}

void AConstructorEscenario4::ConstruirTipoPieza()
{
    std::vector<std::vector<std::pair<float, float>>> Shapes =
    {
        {{-20.0, 0.0}, {-10.0, 0.0}, {0.0, 0.0}, {10.0, 0.0}},
        {{0.0, 10.0}, {0.0, 0.0}, {10.0, 0.0}, {20.0, 0.0}},
        {{-20.0, 0.0}, {-10.0, 0.0}, {0.0, 0.0}, {0.0, 10.0}},
        {{0.0, 0.0}, {10.0, 0.0}, {0.0, -10.0}, {10.0, -10.0}},
        {{-10.0, -10.0}, {0.0, -10.0}, {0.0, 0.0}, {10.0, 0.0}},
        {{-10.0, 0.0}, {0.0, 0.0}, {0.0, 10.0}, {10.0, 0.0}},
        {{-10.0, 0.0}, {0.0, 0.0}, {0.0, -10.0}, {10.0, -10.0}},
        //piezas creadas
        {{-10.0, 10.0}, {0.0, -10.0}, {0.0, 0.0}, {10.0, 10.0}},
        {{-10.0, -10.0}, {0.0, 0.0}, {10.0, 10.0}, {20.0, 20.0}},
        {{-20.0, 0.0}, {0.0, 0.0}, {0.0, 10.0}, {0.0, -10.0}},
        {{-10.0, 0.0}, {0.0, 0.0}, {0.0, -10.0}, {10.0, 10.0}},
        {{0.0, -20.0}, {0.0, 0.0}, {0.0, -10.0}, {-10.0, 10.0}},

        /*{{-20.0, 10.0}, {-10.0, 0.0}, {0.0, 10.0}, {10.0, 0.0}},
        {{-10.0, 0.0}, {10.0, 0.0}, {30.0, 0.0}, {10.0, -10.0}},*/
    };
    const int Index = FMath::RandRange(0, Shapes.size() - 1);
    //const int Index = 7;
    UE_LOG(LogTemp, Warning, TEXT("index=%d"), Index);

    const std::vector<std::pair<float, float>>& YZs = Shapes[Index];
    for (auto&& YZ : YZs)
    {
        FRotator Rotation(0.0, 0.0, 0.0);
        ABlock* B = GetWorld()->SpawnActor<ABlock>(this->GetActorLocation(), Rotation);
        B->BlockMesh->SetMaterial(1, Colors[Index]);
        B->BlockMesh->SetMaterial(0, Colors[7]);
        Blocks.Add(B);
        B->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
        B->SetActorRelativeLocation(FVector(0.0, YZ.first, YZ.second));

    }
	Escenario->SetTipoPieza(Shapes);

}

void getIndex(int _Index) {
    Index = _Index;
}
AEscenarioPlano* AConstructorEscenario4::GetEscenarioPlano()
{
	//Returns the Lodging Actor of the Builder (this)
	return Escenario;
}

