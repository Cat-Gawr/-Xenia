
#ifndef XENIA_HID_SDL_SDL_HID_H_
#define XENIA_HID_SDL_SDL_HID_H_

#include <memory>

#include "xenia/hid/input_system.h"

namespace xe {
namespace hid {
namespace sdl {

std::unique_ptr<InputDriver> Create(xe::ui::Window* window,
                                    size_t window_z_order);

}  // namespace sdl
}  // namespace hid
}  // namespace xe

#endif  // XENIA_HID_SDL_SDL_HID_H_


/// ****************************************
/// Kona - nome cambiato 
