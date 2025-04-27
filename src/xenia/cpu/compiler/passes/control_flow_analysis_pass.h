#ifndef XENIA_CPU_COMPILER_PASSES_CONTROL_FLOW_ANALYSIS_PASS_H_
#define XENIA_CPU_COMPILER_PASSES_CONTROL_FLOW_ANALYSIS_PASS_H_

#include "xenia/cpu/compiler/compiler_pass.h"

namespace xe {
namespace cpu {
namespace compiler {
namespace passes {

class ControlFlowAnalysisPass : public CompilerPass {
 public:
  ControlFlowAnalysisPass();
  ~ControlFlowAnalysisPass() override;

  bool Run(hir::HIRBuilder* builder) override;

 private:
};

}  // namespace passes
}  // namespace compiler
}  // namespace cpu
}  // namespace xe

#endif  // XENIA_CPU_COMPILER_PASSES_CONTROL_FLOW_ANALYSIS_PASS_H_
