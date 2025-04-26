

#include "xenia/hid/xinput/xinput_hid.h"

#include "xenia/hid/xinput/xinput_input_driver.h"

namespace xe {
namespace hid {
namespace xinput {

std::unique_ptr<InputDriver> Create(xe::ui::Window* window,
                                    size_t window_z_order) {
  return std::make_unique<XInputInputDriver>(window, window_z_order);
}

}  // namespace xinput
}  // namespace hid
}  // namespace xe
