#include "xenia/apu/nop/nop_audio_system.h"

#include "xenia/apu/apu_flags.h"

namespace xe {
namespace apu {
namespace nop {

std::unique_ptr<AudioSystem> NopAudioSystem::Create(cpu::Processor* processor) {
  return std::make_unique<NopAudioSystem>(processor);
}

NopAudioSystem::NopAudioSystem(cpu::Processor* processor)
    : AudioSystem(processor) {}

NopAudioSystem::~NopAudioSystem() = default;

X_STATUS NopAudioSystem::CreateDriver(size_t index,
                                      xe::threading::Semaphore* semaphore,
                                      AudioDriver** out_driver) {
  return X_STATUS_NOT_IMPLEMENTED;
}

void NopAudioSystem::DestroyDriver(AudioDriver* driver) { assert_always(); }

}  // namespace nop
}  // namespace apu
}  // namespace xe
