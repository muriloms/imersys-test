// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ImersysTest_CppCharacter.h"
#include "ImersysCharacter.generated.h"

/**
 * 
 */
UCLASS()
class IMERSYSTEST_CPP_API AImersysCharacter : public AImersysTest_CppCharacter
{
	GENERATED_BODY()
	
public:
	AImersysCharacter();


	// Called every frame
	virtual void Tick(float DeltaTime) override;


private:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Trace Properties", meta = (AllowPrivateAccess = "true"))
	float LineTraceLenght;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Interaction, meta = (AllowPrivateAccess = "true"))
	bool bEnterBoxInteraction;

public:

	FORCEINLINE bool GetEnterBoxInteraction() const { return bEnterBoxInteraction; }
	

};
