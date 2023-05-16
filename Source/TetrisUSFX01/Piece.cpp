// Fill out your copyright notice in the Description page of Project Settings.


#include "Piece.h"
#include "Components/SceneComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"
#include <vector>


// Sets default values
APiece::APiece()
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
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_8;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_9;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_10;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_11;
        ConstructorHelpers::FObjectFinderOptional<UMaterial> Color_12;

        //Inicio Constructor de Struct
        FConstructorStatics() :
            Color_0(TEXT("Material'/Game/Mesh/Material_0.Material_0'")), Color_1(TEXT("Material'/Game/Mesh/Material_1.Material_1'"))
            , Color_2(TEXT("Material'/Game/Mesh/Material_2.Material_2'")), Color_3(TEXT("Material'/Game/Mesh/Material_3.Material_3'"))
            , Color_4(TEXT("Material'/Game/Mesh/Material_4.Material_4'")), Color_5(TEXT("Material'/Game/Mesh/Material_5.Material_5'"))
            , Color_6(TEXT("Material'/Game/Mesh/Material_6.Material_6'")), Color_7(TEXT("Material'/Game/Mesh/Material_7.Material_7'"))
            , Color_8(TEXT("Material'/Game/Mesh/Material_0.Material_0'")), Color_9(TEXT("Material'/Game/Mesh/Material_1.Material_1'"))
            , Color_10(TEXT("Material'/Game/Mesh/Material_2.Material_2'")), Color_11(TEXT("Material'/Game/Mesh/Material_3.Material_3'"))
            , Color_12(TEXT("Material'/Game/Mesh/Material_4.Material_4'"))
        {
        }

        //Fin Constructor de Struct
    };

    //Instanciamos el Struct con un objeto de nombre ConstructorStatics.
    static FConstructorStatics ConstructorStatics;

    //Vamos anadiendo a nuestro TArray de UMaterials, cada uno de los colores encontrados gracias a ConstructorHelpers.
    Colors.Add(ConstructorStatics.Color_0.Get());
    Colors.Add(ConstructorStatics.Color_1.Get());
    Colors.Add(ConstructorStatics.Color_2.Get());
    Colors.Add(ConstructorStatics.Color_3.Get());
    Colors.Add(ConstructorStatics.Color_4.Get());
    Colors.Add(ConstructorStatics.Color_5.Get());
    Colors.Add(ConstructorStatics.Color_6.Get());
    Colors.Add(ConstructorStatics.Color_7.Get());
    Colors.Add(ConstructorStatics.Color_8.Get());
    Colors.Add(ConstructorStatics.Color_9.Get());
    Colors.Add(ConstructorStatics.Color_10.Get());
    Colors.Add(ConstructorStatics.Color_11.Get());
    Colors.Add(ConstructorStatics.Color_12.Get());

}

// Called when the game starts or when spawned
void APiece::BeginPlay()
{
    Super::BeginPlay();
    SpawnBlocks();
}

// Called every frame
void APiece::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);

}

void APiece::SpawnBlocks()
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
}

void APiece::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
    UE_LOG(LogTemp, Warning, TEXT("Piezas eliminadas"));
}

//void APiece::Dismiss()
//{
//    Blocks.Empty();
//}

void APiece::DrawDebugLines()
{
    for (ABlock* B : Blocks)
    {
        FVector V1 = B->GetActorLocation();
        FVector V2(V1.X, V1.Y, 5.0f);
        DrawDebugLine(GetWorld(), V1, V2, FColor::Green, false, 1, 0, 1);
    }
}

void APiece::TestRotate()
{
    auto RotateVector = [this](FVector OldVector) {
        FVector ActorVector = this->GetActorLocation();
        FVector BlockVector = OldVector;
        FVector TempVector = BlockVector - ActorVector;
        TempVector = ActorVector + TempVector.RotateAngleAxis(90.0, FVector(1.0, 0.0, 0.0));
        return TempVector;
    };

    if (!CheckWillCollision(RotateVector))
    {
        UE_LOG(LogTemp, Warning, TEXT("now can rotate"));
        FRotator NewRotation = this->GetActorRotation() + FRotator(0.0, 0.0, -90.0);
        //FRotator NewRotation = this->GetActorRotation() + FRotator(90.0, 0.0, 0.0);
        this->SetActorRelativeRotation(NewRotation);
        /*if (RotateSoundCue)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), RotateSoundCue, GetActorLocation(), GetActorRotation());
        }*/
    }
}

void APiece::RotarEspalda() {
    auto RotateVector = [this](FVector OldVector) {
        FVector ActorVector = this->GetActorLocation();
        FVector BlockVector = OldVector;
        FVector TempVector = BlockVector - ActorVector;
        TempVector = ActorVector + TempVector.RotateAngleAxis(90.0, FVector(1.0, 0.0, 0.0));
        return TempVector;
    };

    if (!CheckWillCollision(RotateVector))
    {
        UE_LOG(LogTemp, Warning, TEXT("now can rotate"));
        FRotator NewRotation = this->GetActorRotation() + FRotator(+90.0, 0.0, 0.0);
        //FRotator NewRotation = this->GetActorRotation() + FRotator(90.0, 0.0, 0.0);
        this->SetActorRelativeRotation(NewRotation);
        /*if (RotateSoundCue)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), RotateSoundCue, GetActorLocation(), GetActorRotation());
        }*/
    }
}

void APiece::RotarFrente() {
    auto RotateVector = [this](FVector OldVector) {
        FVector ActorVector = this->GetActorLocation();
        FVector BlockVector = OldVector;
        FVector TempVector = BlockVector - ActorVector;
        TempVector = ActorVector + TempVector.RotateAngleAxis(90.0, FVector(1.0, 0.0, 0.0));
        return TempVector;
    };

    if (!CheckWillCollision(RotateVector))
    {
        UE_LOG(LogTemp, Warning, TEXT("now can rotate"));
        FRotator NewRotation = this->GetActorRotation() + FRotator(-90.0, 0.0, 0.0);
        //FRotator NewRotation = this->GetActorRotation() + FRotator(90.0, 0.0, 0.0);
        this->SetActorRelativeRotation(NewRotation);
        /*if (RotateSoundCue)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), RotateSoundCue, GetActorLocation(), GetActorRotation());
        }*/
    }
}

//void APiece::EndPlay(const EEndPlayReason::Type EndPlayReason)
//{
//    UE_LOG(LogTemp, Warning, TEXT("Pieces Deleted"));
//}

void APiece::Dismiss()
{
    Blocks.Empty();
}

void APiece::MoveLeft()
{
    auto MoveVectorLeft = [](FVector OldVector) {
        OldVector.Y -= 10.0f;
        return OldVector;
    };

    if (!CheckWillCollision(MoveVectorLeft))
    {
        FVector NewLocation = GetActorLocation();
        NewLocation.Y -= 10;
        SetActorLocation(NewLocation);

        /* if (MoveLeftRightSoundCue)
         {
             UGameplayStatics::PlaySoundAtLocation(GetWorld(), MoveLeftRightSoundCue, GetActorLocation(), GetActorRotation());
         }*/
    }
}

void APiece::MoveRight()
{
    auto MoveVectorRight = [](FVector OldVector) {
        OldVector.Y += 10.0f;
        return OldVector;
    };

    if (!CheckWillCollision(MoveVectorRight))
    {
        FVector NewLocation = GetActorLocation();
        NewLocation.Y += 10;
        SetActorLocation(NewLocation);

        /*if (MoveLeftRightSoundCue)
        {
            UGameplayStatics::PlaySoundAtLocation(GetWorld(), MoveLeftRightSoundCue, GetActorLocation(), GetActorRotation());
        }*/
    }
}

bool APiece::MoveDown(bool PlaySound)
{
    auto MoveVectorDown = [](FVector OldVector) {
        OldVector.Z -= 10.0f;
        // UE_LOG(LogTemp, Warning, TEXT("Cambiandoooo"))
             //////////
        return OldVector;
    };

    if (!CheckWillCollision(MoveVectorDown))
    {
        FVector NewLocation = GetActorLocation();
        NewLocation.Z -= 10;
        //UE_LOG(LogTemp, Warning, TEXT("Cambiandoooo"))
        SetActorLocation(NewLocation);

        return true;
    }
    else
    {
        return false;
    }
}

bool APiece::CheckWillCollision(std::function<FVector(FVector OldLocation)> ChangeBeforeCheck)
{
    FCollisionQueryParams Params;
    for (ABlock* B : Blocks)
    {
        Params.AddIgnoredActor(B);//consulta de colicion ignorando el actor
    }

    for (ABlock* B : Blocks)
    {
        FVector TempVector = B->GetActorLocation();//ubicacion del bloque
        TempVector = ChangeBeforeCheck(TempVector);//cambia la ubicacion del bloque
        //UE_LOG(LogTemp, Warning, TEXT("Esta bajando"))

        TArray<struct FOverlapResult> OutOverlaps;// resultado
        FCollisionShape CollisionShape;
        CollisionShape.SetBox(FVector(4.0f, 4.0f, 4.0f));
        FCollisionResponseParams ResponseParam;
        bool b = GetWorld()->OverlapMultiByChannel(OutOverlaps,
            TempVector, B->GetActorQuat(), ECollisionChannel::ECC_WorldDynamic,
            CollisionShape, Params, ResponseParam);//saber si se detecto la colision 

        if (b)
        {

            for (auto&& Result : OutOverlaps)
            {
                UE_LOG(LogTemp, Warning, TEXT("OverLapped with actor %s, component=%s"), *Result.GetActor()->GetName(),
                    *Result.GetComponent()->GetName());//nos imrime el nombre del actor
                //ScorePuntos = ScorePuntos + 1;
                //UE_LOG(LogTemp, Warning, TEXT("Bajnando"))

            }
            return true;
        }
    }

    return false;
}

//por cada desenso que resiva 1 punto
