/******************************************************************************
 * Copyright 2018 The Apollo Authors. All Rights Reserved.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 *****************************************************************************/
#pragma once

#include <memory>
#include <string>

#include "modules/perception/onboard/proto/lidar_component_config.pb.h"

#include "cyber/cyber.h"
#include "modules/perception/base/sensor_meta.h"
#include "modules/perception/lidar/app/lidar_obstacle_tracking.h"
#include "modules/perception/onboard/inner_component_messages/inner_component_messages.h"
#include "modules/perception/onboard/inner_component_messages/lidar_inner_component_messages.h"
#include "modules/perception/pipeline/pipeline.h"

namespace apollo {
namespace perception {
namespace onboard {

class LidarTrackingComponent : public cyber::Component<LidarFrameMessage> {
 public:
  using PipelineConfig = pipeline::PipelineConfig;

 public:
  LidarTrackingComponent() : tracker_(nullptr) {}
  ~LidarTrackingComponent() = default;

  bool Init() override;
  bool Proc(const std::shared_ptr<LidarFrameMessage>& message) override;

 private:
  bool InitAlgorithmPlugin();
  bool InternalProc(const std::shared_ptr<const LidarFrameMessage>& in_message,
                    const std::shared_ptr<SensorFrameMessage>& out_message);

 private:
  std::unique_ptr<lidar::BaseLidarObstacleTracking> tracker_;
  pipeline::PipelineConfig lidar_tracking_config_;

  base::SensorInfo sensor_info_;
  std::string main_sensor_name_;
  std::string output_channel_name_;
  std::shared_ptr<apollo::cyber::Writer<SensorFrameMessage>> writer_;
};

CYBER_REGISTER_COMPONENT(LidarTrackingComponent);

}  // namespace onboard
}  // namespace perception
}  // namespace apollo
