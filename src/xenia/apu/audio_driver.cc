#include "xenia/apu/audio_driver.h"

namespace xe {
namespace apu {

AudioDriver::AudioDriver(Memory* memory) : memory_(memory) {}

AudioDriver::~AudioDriver() = default;

}  // namespace apu
}  // namespace xe
