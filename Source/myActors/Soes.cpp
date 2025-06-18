// Fill out your copyright notice in the Description page of Project Settings.


#include "Soes.h"

// Sets default values
ASoes::ASoes()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ASoes::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("액터 스폰 성공!"));
}

// Called every frame
void ASoes::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

