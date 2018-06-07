// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Tile.generated.h"
class UActorPool; 

USTRUCT()
struct FSpawnPosition
{
	GENERATED_USTRUCT_BODY()

	FVector Location;
	float Rotation; 
	float Scale;
};

USTRUCT(BlueprintType)
struct FSpawnParameters
{
	GENERATED_USTRUCT_BODY()

		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		int MinSpawn;
	
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		int MaxSpawn;
	
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		float MinScale;
	
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		float MaxScale;
	
		UPROPERTY(BlueprintReadWrite, EditDefaultsOnly)
		float Radius;

	/*FSpawnParameters()
	{
		MinSpawn = 1;
		MaxSpawn = 1;
		MinScale = 1;
		MaxScale = 1;
		Radius = 100;
	}*/
};

UCLASS()
class TESTINGGROUNDS_API ATile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATile();

	UFUNCTION(BlueprintCallable)
	void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, float Radius, int MinScale, int MaxScale);

	UFUNCTION(BlueprintCallable)
	void PlaceAIPawns(TSubclassOf<APawn> ToSpawn, int MinSpawn, int MaxSpawn, float Radius, int MinScale, int MaxScale);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MinExtent;

	UPROPERTY(EditDefaultsOnly, Category = "Spawning")
	FVector MaxExtent;

	UPROPERTY(EditDefaultsOnly, Category = "Navigation")
	FVector NavigationBoundsOffSet;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Actor Pool")
		void SetPool(UActorPool* Pool);

	

	
private:
	bool CanSpawnAtLocation(FVector Location, float Radius);

	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	template<class T>
	void RandomlyPlaceActors(TSubclassOf<T> ToSpawn, int MinSpawn, int MaxSpawn, float Radius, int MinScale, int MaxScale);

	void PlaceActor(TSubclassOf<AActor> ToSpawn, const FSpawnPosition SpawnPosition);

	void PlaceActor(TSubclassOf<APawn> ToSpawn, const FSpawnPosition SpawnPosition);

	TArray<FSpawnPosition> RandomSpawnPositions(int MinSpawn, int MaxSpawn, float Radius, int MinScale, int MaxScale);

	
	
	void PositionNavMeshBoundsVolume();

	UActorPool* Pool;

	AActor* NavmeshBoundsVolume;
};

