// Fill out your copyright notice in the Description page of Project Settings.


#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
    UE_LOG(LogTemp, Warning, TEXT("BeginPlay 실행됨")); 
   	AMyActor::Move10Times();
    
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::Move10Times() {

	
    int32 x = 0;
    int32 y = 0;
    int32 prex = 0;
    int32 prey = 0;
    
    
    float logDistance;
    UE_LOG(LogTemp, Warning, TEXT(" 현재 좌표 (%d, %d)"), x, y);
    for (int32 i = 0; i < 100; i++)
    {
        int32 dx = Step();
        int32 dy = Step();
        //삼항 연산자: x + dx 가 100 미만이면  dx에 Step 함수에서 뽑은 랜덤 값 저장
        dx = (x + dx > 100) ? 0 : dx;
        dy = (y + dy > 100) ? 0 : dy;

        // 이전 좌표값 저장
        prex = x;
        prey = y;
        
        //좌표 누적
        x += dx;
        y += dy;
        //거리 구하기 (이전 x좌표값 - 현 x좌표) + (이전 y좌표값 - 현  y좌표값)
        // 둘다 제곱 후 더한 후 sqrt 함수로 루트 씌워서 distance 변수에 저장후 반환. 
        logDistance = AMyActor::Distance(prex, x, prey, y);

        

		
		UE_LOG(LogTemp, Warning, TEXT("이동 %d: 현재 좌표 (%d, %d)"), i + 1, x, y);
        UE_LOG(LogTemp, Warning, TEXT("이번 dx: %d, dy: %d"), dx, dy);

        UE_LOG(LogTemp, Warning, TEXT("이전 좌표와 거리: %f "),logDistance);
        AMyActor::TryTriggerEvent(50);

	}



}

float AMyActor::Distance(int x1, int x2, int y1, int y2) {

    float dx = x2 - x1;
    float dy = y2 - y1;
    float distance = FMath::Sqrt(FMath::Pow(dx,2) + FMath::Pow(dy,2));

    return distance;

}

void  AMyActor::TryTriggerEvent(int Probability){
    
    int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
    

    if (RandomValue <= Probability)
    {
        
        UE_LOG(LogTemp, Log, TEXT("Event Triggered!"));
        count++;
        UE_LOG(LogTemp, Log, TEXT("EventCount: %d"), count);
    }
    else
    {
        UE_LOG(LogTemp, Log, TEXT("Event Not Triggered"));
    }

}

int32 AMyActor::Step() {
	return FMath::RandRange(0, 1);
}
