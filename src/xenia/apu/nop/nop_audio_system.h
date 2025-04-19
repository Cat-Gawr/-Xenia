#ifndef XENIA_APU_NOP_NOP_AUDIO_SYSTEM_H_
#define XENIA_APU_NOP_NOP_AUDIO_SYSTEM_H_

#include "xenia/apu/audio_system.h"

namespace xe {
namespace apu {
namespace nop {

class NopAudioSystem : public AudioSystem {
 public:
  explicit NopAudioSystem(cpu::Processor* processor);
  ~NopAudioSystem() override;

  static bool IsAvailable() { return true; }

  static std::unique_ptr<AudioSystem> Create(cpu::Processor* processor);

  X_STATUS CreateDriver(size_t index, xe::threading::Semaphore* semaphore,
                        AudioDriver** out_driver) override;
  void DestroyDriver(AudioDriver* driver) override;
};

}  // namespace nop
}  // namespace apu
}  // namespace xe

#endif  // XENIA_APU_NOP_NOP_AUDIO_SYSTEM_H_
