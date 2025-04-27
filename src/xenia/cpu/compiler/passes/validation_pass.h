#ifndef XENIA_CPU_COMPILER_PASSES_VALIDATION_PASS_H_
#define XENIA_CPU_COMPILER_PASSES_VALIDATION_PASS_H_

#include "xenia/cpu/compiler/compiler_pass.h"

namespace xe {
namespace cpu {
namespace compiler {
namespace passes {

class ValidationPass : public CompilerPass {
 public:
  ValidationPass();
  ~ValidationPass() override;

  bool Run(hir::HIRBuilder* builder) override;

 private:
  bool ValidateInstruction(hir::Block* block, hir::Instr* instr);
  bool ValidateValue(hir::Block* block, hir::Instr* instr, hir::Value* value);
};

}  // namespace passes
}  // namespace compiler
}  // namespace cpu
}  // namespace xe

#endif  // XENIA_CPU_COMPILER_PASSES_VALIDATION_PASS_H_
