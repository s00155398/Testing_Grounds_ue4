// Fill out your copyright notice in the Description page of Project Settings.

#include "InfiniteGameMode.h"
#include "EngineUtils.h"
#include "AI/Navigation/NavMeshBoundsVolume.h"
#include "EngineUtils.h"
#include "ActorPool.h"

AInfiniteGameMode::AInfiniteGameMode()
{
	NavmeshBoundsVolumePool = CreateDefaultSubobject<UActorPool>(FName("Nav mesh bounds volume Pool"));
}


void AInfiniteGameMode::AddToPool(class ANavMeshBoundsVolume *VolumeToAdd)
{
	NavmeshBoundsVolumePool->Add(VolumeToAdd);
}

void AInfiniteGameMode::PopulateBoundsVolumePool()
{
	auto VolumeIterator = TActorIterator<ANavMeshBoundsVolume>(GetWorld());
	while (VolumeIterator)
	{
		AddToPool(*VolumeIterator);
		++VolumeIterator;
	}
}


