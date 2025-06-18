// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class MYACTORS_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:
	int32 count = 0;

public:	
	// Sets default values for this actor's properties
	AMyActor();
	int32 Step();
	void Move10Times();
	float Distance(int x1, int x2, int y1, int y2);
	void TryTriggerEvent(int Probability);
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	
	

};
