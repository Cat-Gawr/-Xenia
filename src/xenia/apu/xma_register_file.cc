#include "xenia/apu/xma_register_file.h"

#include <cstring>

#include "xenia/base/math.h"

namespace xe {
namespace apu {

XmaRegisterFile::XmaRegisterFile() { std::memset(values, 0, sizeof(values)); }

const XmaRegisterInfo* XmaRegisterFile::GetRegisterInfo(uint32_t index) {
  switch (index) {
#define XE_XMA_REGISTER(index, name)          \
  case index: {                               \
    static const XmaRegisterInfo reg_info = { \
        #name,                                \
    };                                        \
    return &reg_info;                         \
  }
#include "xenia/apu/xma_register_table.inc"
#undef XE_XMA_REGISTER
    default:
      return nullptr;
  }
}

}  //  namespace apu
}  //  namespace xe
