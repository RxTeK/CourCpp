#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Materials/Material.h"
#include "BP_RandomColor.generated.h"


UCLASS()
class TESTCPP_API ABP_RandomColor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABP_RandomColor();
	float randomNumber();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* SuperMesh;

	UPROPERTY(VisibleAnywhere)
	UMaterial* material;
};
