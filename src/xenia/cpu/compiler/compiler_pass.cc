#include "xenia/cpu/compiler/compiler_pass.h"

#include "xenia/cpu/compiler/compiler.h"

namespace xe {
namespace cpu {
namespace compiler {

CompilerPass::CompilerPass() : processor_(nullptr), compiler_(nullptr) {}

CompilerPass::~CompilerPass() = default;

bool CompilerPass::Initialize(Compiler* compiler) {
  processor_ = compiler->processor();
  compiler_ = compiler;
  return true;
}

Arena* CompilerPass::scratch_arena() const {
  return compiler_->scratch_arena();
}

}  // namespace compiler
}  // namespace cpu
}  // namespace xe
