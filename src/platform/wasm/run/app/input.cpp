// The app's pad (docs/wasm-port.md "The macOS app"): the SDL layer's input backend (src/platform/sdl/input/), SDL3
// gamepads as Xbox controllers and, while no gamepad is connected, the keyboard as pad 0 (docs/native-play.md's map;
// HULK_KEYMAP, HULK_KEY_SCRIPT for unattended runs). The module asks once a presented frame (gfx.c), outside replays.
#include <stdint.h>
#include <string.h>

#include "input/hulk_input.cpp"

typedef uint32_t u32;

// XINPUT_GAMEPAD's 18 bytes (HulkPadState's layout) for `port`: 1 with a pad there, else 0
extern "C" u32 hulk_app_pad(u32 port, uint8_t* out18)
{
    static_assert(sizeof(HulkPadState) == 18, "HulkPadState is XINPUT_GAMEPAD");
    HulkPadState s;
    if (!hulk_input_read(port, &s))
        return 0;
    memcpy(out18, &s, 18);
    return 1;
}
