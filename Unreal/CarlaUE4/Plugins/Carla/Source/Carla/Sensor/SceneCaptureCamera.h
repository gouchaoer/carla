// Copyright (c) 2017 Computer Vision Center (CVC) at the Universitat Autonoma
// de Barcelona (UAB).
//
// This work is licensed under the terms of the MIT license.
// For a copy, see <https://opensource.org/licenses/MIT>.

#pragma once

#include "Carla/Actor/ActorDefinition.h"
#include "Carla/Sensor/PixelReader.h"
#include "Carla/Sensor/ShaderBasedSensor.h"

#include "SceneCaptureCamera.generated.h"

/// A sensor that captures images from the scene.
UCLASS()
class CARLA_API ASceneCaptureCamera : public AShaderBasedSensor
{
  GENERATED_BODY()

public:

  static FActorDefinition GetSensorDefinition();

  ASceneCaptureCamera(const FObjectInitializer &ObjectInitializer);

protected:

  void PostPhysTick(UWorld *World, ELevelTick TickType, float DeltaSeconds) override;

  void SendPixelsInRenderThread(const TArray<FColor>& AtlasPixels, uint32 AtlasTextureWidth) override;
  /*

    void WritePixelsToBuffer(
      UTextureRenderTarget2D &RenderTarget,
      carla::Buffer &Buffer,
      uint32 Offset,
      FRHICommandListImmediate &InRHICmdList,
      bool DownloadTexture,
      bool RHIGPUReadBack
      );
      */

};
