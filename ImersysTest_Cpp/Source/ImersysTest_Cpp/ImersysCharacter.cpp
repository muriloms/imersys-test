// Fill out your copyright notice in the Description page of Project Settings.


#include "ImersysCharacter.h"
#include "DrawDebugHelpers.h"
#include "Camera/CameraComponent.h"
#include "InteractionObj.h"
#include "Engine/EngineTypes.h"


AImersysCharacter::AImersysCharacter() :
	LineTraceLenght(200.f)
{
}

void AImersysCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FHitResult OutHit;
	FVector Start = FirstPersonCameraComponent->GetComponentLocation();

	FVector ForwardVector = FirstPersonCameraComponent->GetForwardVector();
	FVector End = ((ForwardVector * LineTraceLenght) + Start);
	FCollisionQueryParams CollisionParams;

	if (GetWorld()->LineTraceSingleByChannel(OutHit, Start, End, ECC_Visibility, CollisionParams))
	{
		if (OutHit.bBlockingHit)
		{
			AInteractionObj* IntObj = Cast<AInteractionObj>(OutHit.GetActor());
			if (IntObj)
			{
				bEnterBoxInteraction = true;
			}
			
		}
	}
	else
	{
		bEnterBoxInteraction = false;
	}
	
}
