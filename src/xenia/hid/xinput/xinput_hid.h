
#ifndef XENIA_HID_XINPUT_XINPUT_HID_H_
#define XENIA_HID_XINPUT_XINPUT_HID_H_

#include <memory>

#include "xenia/hid/input_system.h"

namespace xe {
namespace hid {
namespace xinput {

std::unique_ptr<InputDriver> Create(xe::ui::Window* window,
                                    size_t window_z_order);

}  // namespace xinput
}  // namespace hid
}  // namespace xe

#endif  // XENIA_HID_XINPUT_XINPUT_HID_H_
