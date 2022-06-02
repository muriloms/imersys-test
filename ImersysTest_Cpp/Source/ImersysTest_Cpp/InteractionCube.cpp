// Fill out your copyright notice in the Description page of Project Settings.


#include "InteractionCube.h"
#include "Components/BoxComponent.h"
#include "Components/WidgetComponent.h"
#include "Components/SphereComponent.h"
#include "ImersysCharacter.h"


// Sets default values
AInteractionCube::AInteractionCube()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	CubeMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("CubeMesh"));
	SetRootComponent(CubeMesh);

	CollisionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("CollisionBox"));
	CollisionBox->SetupAttachment(CubeMesh);

	MsgWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("MsgWidget"));
	MsgWidget->SetupAttachment(GetRootComponent());

}

// Called when the game starts or when spawned
void AInteractionCube::BeginPlay()
{
	Super::BeginPlay();
	
	CollisionBox->OnComponentBeginOverlap.AddDynamic(this, &AInteractionCube::MsgBoxOverlap);
	CollisionBox->OnComponentEndOverlap.AddDynamic(this, &AInteractionCube::MsgEndBoxOverlap);

	if (MsgWidget)
	{
		MsgWidget->SetVisibility(false);
	}
}

// Called every frame
void AInteractionCube::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInteractionCube::MsgBoxOverlap(UPrimitiveComponent* OnverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	if (OtherActor == nullptr) return;

	auto Character = Cast<AImersysCharacter>(OtherActor);

	if (Character)
	{
		if (MsgWidget)
		{
			MsgWidget->SetVisibility(true);
		}
	}


}

void AInteractionCube::MsgEndBoxOverlap(UPrimitiveComponent* OnverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
	if (OtherActor == nullptr) return;

	auto Character = Cast<AImersysCharacter>(OtherActor);

	if (Character)
	{
		if (MsgWidget)
		{
			MsgWidget->SetVisibility(false);
		}
	}
}

