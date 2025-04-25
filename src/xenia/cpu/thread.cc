#include "xenia/cpu/thread.h"
#include "xenia/cpu/thread_state.h"

namespace xe {
namespace cpu {

thread_local Thread* Thread::current_thread_ = nullptr;

Thread::Thread() {}
Thread::~Thread() {}

bool Thread::IsInThread() { return current_thread_ != nullptr; }

Thread* Thread::GetCurrentThread() { return current_thread_; }
uint32_t Thread::GetCurrentThreadId() {
  return Thread::GetCurrentThread()->thread_state()->thread_id();
}

}  // namespace cpu
}  // namespace xe
