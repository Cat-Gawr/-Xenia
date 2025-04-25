#include "xenia/cpu/backend/assembler.h"

namespace xe {
namespace cpu {
namespace backend {

Assembler::Assembler(Backend* backend) : backend_(backend) {}

Assembler::~Assembler() { Reset(); }

bool Assembler::Initialize() { return true; }

void Assembler::Reset() {}

}  // namespace backend
}  // namespace cpu
}  // namespace xe
