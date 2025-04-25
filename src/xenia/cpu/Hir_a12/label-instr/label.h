#ifndef XENIA_CPU_HIR_LABEL_H_
#define XENIA_CPU_HIR_LABEL_H_

namespace xe {
namespace cpu {
namespace hir {

class Block;

class Label {
 public:
  Block* block;
  Label* next;
  Label* prev;

  uint32_t id;
  char* name;

  void* tag;
};

}  // namespace hir
}  // namespace cpu
}  // namespace xe

#endif  // XENIA_CPU_HIR_LABEL_H_
