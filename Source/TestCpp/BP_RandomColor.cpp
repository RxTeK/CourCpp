// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_RandomColor.h"

// Sets default values
ABP_RandomColor::ABP_RandomColor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	
	SuperMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("My Super Mesh"));
}

float ABP_RandomColor::randomNumber ()
{
	float random = FMath::RandRange(0, 100);
	random = random/100;
	return(random);
}

// Called when the game starts or when spawned
void ABP_RandomColor::BeginPlay()
{
	Super::BeginPlay();
	
	FTimerDelegate timerDelegate;
	timerDelegate.BindLambda([&]()
	{
		if (SuperMesh->GetMaterial(0))
            	{
            		FName name = FName("Base Color");
            		FVector color = FVector(randomNumber(), randomNumber(), randomNumber());
            		SuperMesh->SetVectorParameterValueOnMaterials(name, color );
					UE_LOG(LogTemp, Display, TEXT("Random Color"));
            	}
	});
	FTimerHandle timerHandle;
	GetWorld()->GetTimerManager().SetTimer(timerHandle, timerDelegate, 2.0f, true);
}

// Called every frame
void ABP_RandomColor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



