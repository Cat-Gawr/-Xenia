#ifndef XENIA_CONFIG_H_
#define XENIA_CONFIG_H_

#include <filesystem>

namespace config {
void SetupConfig(const std::filesystem::path& config_folder);
void LoadGameConfig(const std::string_view title_id);
void SaveConfig();
}  // namespace config

#endif  // XENIA_CONFIG_H_
