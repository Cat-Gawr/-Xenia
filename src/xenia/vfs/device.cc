#include "xenia/vfs/device.h"

#include "xenia/base/logging.h"

namespace xe {
namespace vfs {

Device::Device(const std::string_view mount_path) : mount_path_(mount_path) {}
Device::~Device() = default;

}  // namespace vfs
}  // namespace xe
