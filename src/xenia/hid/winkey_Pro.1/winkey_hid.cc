
#include "xenia/hid/winkey/winkey_hid.h"

#include "xenia/hid/winkey/winkey_input_driver.h"

namespace xe {
namespace hid {
namespace winkey {

std::unique_ptr<InputDriver> Create(xe::ui::Window* window,
                                    size_t window_z_order) {
  return std::make_unique<WinKeyInputDriver>(window, window_z_order);
}

}  // namespace winkey
}  // namespace hid
}  // namespace xe
