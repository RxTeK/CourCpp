// Fill out your copyright notice in the Description page of Project Settings.


#include "BP_Trace.h"

#include "ImageCoreUtils.h"

// Sets default values
ABP_Trace::ABP_Trace()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	USceneComponent* Root = CreateDefaultSubobject<USceneComponent>(TEXT("Root"));
	SetRootComponent(Root);
}

// Called when the game starts or when spawned
void ABP_Trace::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ABP_Trace::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	const FVector Start = GetActorLocation();
	const FVector End = Start + GetActorForwardVector() * 50000.f;
	FHitResult Hit;
	FCollisionQueryParams params;
	params.AddIgnoredActor(this);
	GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECollisionChannel::ECC_Visibility, params);
	DrawDebugLine(GetWorld(), Start, End, FColor::White, false, 0, 0, 5);

	if (Hit.GetActor())
	UE_LOG(LogTemp, Display, TEXT("Le Mesh est: ""%s"), *Hit.GetActor()->GetName());
	
}

