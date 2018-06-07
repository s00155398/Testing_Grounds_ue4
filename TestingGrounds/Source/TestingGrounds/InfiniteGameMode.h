// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "TestingGroundsGameMode.h"
#include "InfiniteGameMode.generated.h"

UCLASS()
class TESTINGGROUNDS_API AInfiniteGameMode : public ATestingGroundsGameMode
{
	GENERATED_BODY()
	
public:
	AInfiniteGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
		void PopulateBoundsVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Nav mesh bounds volume pool")
	class UActorPool* NavmeshBoundsVolumePool;

private:
	void AddToPool(class ANavMeshBoundsVolume *VolumeToAdd);

	
	
};
