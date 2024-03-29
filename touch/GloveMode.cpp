/*
 * Copyright (C) 2021-2024 The LineageOS Project
 * SPDX-License-Identifier: Apache-2.0
 */

#define LOG_TAG "GloveModeService"

#include "GloveMode.h"

#include <fstream>

namespace vendor {
namespace lineage {
namespace touch {
namespace V1_0 {
namespace implementation {

const std::string kGloveModePath = "/sys/devices/platform/soc/990000.i2c/i2c-0/0-0038/fts_glove_mode";

Return<bool> GloveMode::isEnabled() {
    std::ifstream file(kGloveModePath);
    bool enabled;

    file >> enabled;

    return enabled;
}

Return<bool> GloveMode::setEnabled(bool enabled) {
    std::ofstream file(kGloveModePath);

    file << enabled << std::flush;

    return !file.fail();
}

}  // namespace implementation
}  // namespace V1_0
}  // namespace touch
}  // namespace lineage
}  // namespace vendor
