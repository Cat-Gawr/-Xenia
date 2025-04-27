#ifndef XENIA_CPU_COMPILER_PASSES_FINALIZATION_PASS_H_
#define XENIA_CPU_COMPILER_PASSES_FINALIZATION_PASS_H_

#include "xenia/cpu/compiler/compiler_pass.h"

namespace xe {
namespace cpu {
namespace compiler {
namespace passes {

class FinalizationPass : public CompilerPass {
 public:
  FinalizationPass();
  ~FinalizationPass() override;

  bool Run(hir::HIRBuilder* builder) override;

 private:
};

}  // namespace passes
}  // namespace compiler
}  // namespace cpu
}  // namespace xe

#endif  // XENIA_CPU_COMPILER_PASSES_FINALIZATION_PASS_H_
