// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionObj.h"

// Sets default values
AInteractionObj::AInteractionObj()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	PlaneMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("PlaneMesh"));
	SetRootComponent(PlaneMesh);

}

// Called when the game starts or when spawned
void AInteractionObj::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AInteractionObj::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

