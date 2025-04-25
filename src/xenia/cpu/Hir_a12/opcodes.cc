#include "xenia/cpu/hir/opcodes.h"

namespace xe {
namespace cpu {
namespace hir {

#define DEFINE_OPCODE(num, name, sig, flags) \
  const OpcodeInfo num##_info = {            \
      flags,                                 \
      sig,                                   \
      name,                                  \
      num,                                   \
  };
#include "xenia/cpu/hir/opcodes.inl"
#undef DEFINE_OPCODE

}  // namespace hir
}  // namespace cpu
}  // namespace xe
