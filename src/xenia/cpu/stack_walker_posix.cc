#include "xenia/cpu/stack_walker.h"

#include "xenia/base/logging.h"

namespace xe {
namespace cpu {

std::unique_ptr<StackWalker> StackWalker::Create(
    backend::CodeCache* code_cache) {
  XELOGD("Stack walker unimplemented on posix");
  return nullptr;
}

}  // namespace cpu
}  // namespace xe
