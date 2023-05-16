// Fill out your copyright notice in the Description page of Project Settings.

#include "EscenarioPlano.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include <vector>

// Sets default values
AEscenarioPlano::AEscenarioPlano()
{
    // Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;
    SceneComponent = CreateDefaultSubobject<USceneComponent>("Pieces Scene");
    RootComponent = SceneComponent;

    struct FConstructorStatics
    {
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_0;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_1;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_2;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_3;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_4;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_5;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_6;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_7;
        FConstructorStatics()
            : Color_0(TEXT("Material'/Game/Mesh/Material_0.Material_0'"))
            , Color_1(TEXT("Material'/Game/Mesh/Material_1.Material_1'"))
            , Color_2(TEXT("Material'/Game/Mesh/Material_2.Material_2'"))
            , Color_3(TEXT("Material'/Game/Mesh/Material_3.Material_3'"))
            , Color_4(TEXT("Material'/Game/Mesh/Material_4.Material_4'"))
            , Color_5(TEXT("Material'/Game/Mesh/Material_5.Material_5'"))
            , Color_6(TEXT("Material'/Game/Mesh/Material_6.Material_6'"))
            , Color_7(TEXT("Material'/Game/StarterContent/Materials/M_Metal_Brushed_Nickel.M_Metal_Brushed_Nickel'"))
        {
        }
    };
    static FConstructorStatics ConstructorStatics;
    Colors.Add(ConstructorStatics.Color_0.Get());
    Colors.Add(ConstructorStatics.Color_1.Get());
    Colors.Add(ConstructorStatics.Color_2.Get());
    Colors.Add(ConstructorStatics.Color_3.Get());
    Colors.Add(ConstructorStatics.Color_4.Get());
    Colors.Add(ConstructorStatics.Color_5.Get());
    Colors.Add(ConstructorStatics.Color_6.Get());
    Colors.Add(ConstructorStatics.Color_7.Get());

}

// Called when the game starts or when spawned
void AEscenarioPlano::BeginPlay()
{
    Super::BeginPlay();
    // SpawnBlocks();
}

// Called every frame
void AEscenarioPlano::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void AEscenarioPlano::SpawnBlocks()
{
    //std::vector<std::vector<std::pair<float, float>>> Shapes = tipoPieza;
    Index = FMath::RandRange(0, tipoPieza.size() - 1);
    UE_LOG(LogTemp, Warning, TEXT("index=%d"), Index);
    const std::vector<std::pair<float, float>>& YZs = tipoPieza[Index];
    for (auto&& YZ : YZs)
    {
        int color = Index;
        //GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Red, TEXT("El tipo color es: ") + FString::FromInt(getTipoColor()));
        if (getTipoColor() == 1) {
            color = FMath::RandRange(0, tipoPieza.size() - 1);
            //GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Yellow, TEXT("El tipo color es: ") + FString::FromInt(tipoColor));
        }
        else if (getTipoColor() == 3) {
            color = 7;
        }
        //int color = FMath::RandRange(0, Shapes.size() - 1);
        FRotator Rotation(0.0, 0.0, 0.0);
        //FVector Location (0.0, 0.0, 0.0);
        ABlock* B = GetWorld()->SpawnActor<ABlock>(this->GetActorLocation(), Rotation);
        B->BlockMesh->SetMaterial(1, Colors[color]);
        Blocks.Add(B);
        B->AttachToActor(this, FAttachmentTransformRules::KeepRelativeTransform);
        // FVector Location(0.0, 0.0, 120.0);
        B->SetActorRelativeLocation(FVector(0.0, YZ.first, YZ.second)); //colocamos los bloque en el vector que deseemos
       // B->SetActorRelativeLocation(Location);
    }
}

//void AEscenarioPlano::EndPlay(const EEndPlayReason::Type EndPlayReason)
//{
//    UE_LOG(LogTemp, Warning, TEXT("Piezas eliminadas"));
//}

