
#include "xenia/cpu/backend/null_backend.h"

#include "xenia/cpu/backend/assembler.h"
#include "xenia/cpu/function.h"

namespace xe {
namespace cpu {
namespace backend {

void NullBackend::CommitExecutableRange(uint32_t guest_low,
                                        uint32_t guest_high) {}

std::unique_ptr<Assembler> NullBackend::CreateAssembler() { return nullptr; }

std::unique_ptr<GuestFunction> NullBackend::CreateGuestFunction(
    Module* module, uint32_t address) {
  return nullptr;
}

uint64_t NullBackend::CalculateNextHostInstruction(ThreadDebugInfo* thread_info,
                                                   uint64_t current_pc) {
  return current_pc;
}

}  // namespace backend
}  // namespace cpu
}  // namespace xe
