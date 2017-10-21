// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "S05_ProvingGroundsGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

class ANavMeshBoundsVolume;
class UActorPool;

UCLASS()
class S05_PROVINGGROUNDS_API AInfiniteTerrainGameMode : public AS05_ProvingGroundsGameMode
{
	GENERATED_BODY()

public:
	AInfiniteTerrainGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	UActorPool* NavMeshBoundsVolumePool;

private:
	void AddToPool(ANavMeshBoundsVolume* VolumeToAdd);
};
