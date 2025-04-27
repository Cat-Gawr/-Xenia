
#ifndef XENIA_CPU_COMPILER_PASSES_CONSTANT_PROPAGATION_PASS_H_
#define XENIA_CPU_COMPILER_PASSES_CONSTANT_PROPAGATION_PASS_H_

#include "xenia/cpu/compiler/passes/conditional_group_subpass.h"

namespace xe {
namespace cpu {
namespace compiler {
namespace passes {

class ConstantPropagationPass : public ConditionalGroupSubpass {
 public:
  ConstantPropagationPass();
  ~ConstantPropagationPass() override;

  bool Run(hir::HIRBuilder* builder, bool& result) override;

 private:
};

}  // namespace passes
}  // namespace compiler
}  // namespace cpu
}  // namespace xe

#endif  // XENIA_CPU_COMPILER_PASSES_CONSTANT_PROPAGATION_PASS_H_
