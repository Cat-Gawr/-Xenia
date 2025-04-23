#include "xenia/hid/sdl/sdl_hid.h"

#include "xenia/hid/sdl/sdl_input_driver.h"

namespace xe {
namespace hid {
namespace sdl {

std::unique_ptr<InputDriver> Create(xe::ui::Window* window,
                                    size_t window_z_order) {
  return std::make_unique<SDLInputDriver>(window, window_z_order);
}

}  // namespace sdl
}  // namespace hid
}  // namespace xe
