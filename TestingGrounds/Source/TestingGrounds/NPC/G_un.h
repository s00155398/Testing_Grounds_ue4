// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "G_un.generated.h"

UCLASS()
class TESTINGGROUNDS_API AG_un : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AG_un();


	/** Gun mesh: 1st person view (seen only by self) */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USkeletalMeshComponent* FP_Gun;

	/** Location on gun mesh where projectiles should spawn. */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	class USceneComponent* FP_MuzzleLocation;

	/** Projectile class to spawn */
	UPROPERTY(EditDefaultsOnly, Category = Projectile)
	TSubclassOf<class ABallProjectile> ProjectileClass;

	/** Sound to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class USoundBase* FireSound;

	/** AnimMontage to play each time we fire */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation1P;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimInstance* AnimInstance1P;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
	class UAnimMontage* FireAnimation3P;

	UPROPERTY()
	class UAnimInstance* AnimInstance3P;

	/** Gun muzzle's offset from the characters location */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Gameplay)
		FVector GunOffset;

	/** Fires a projectile. */
	UFUNCTION(BlueprintCallable, Category = "Input")
	void OnFire();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	


public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	
	
};
