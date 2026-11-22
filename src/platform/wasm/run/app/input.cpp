// The app's pad (docs/wasm-port.md "The macOS app"): the SDL layer's input backend (src/platform/sdl/input/), SDL3
// gamepads as Xbox controllers and the keyboard as pad 0, merged with a gamepad there (docs/native-play.md's map;
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
    // with a gamepad on port 0 the SDL layer stops reading the keyboard (kb_active); the app keeps both: the
    // keyboard's buttons and triggers add to the pad's, a stick the keyboard pushes overrides the pad's (wapp2)
    static int kb_env = -1;
    if (kb_env < 0) {
        const char* e = SDL_getenv("HULK_KEYBOARD");
        const char* h = SDL_getenv("HULK_GFX_HIDDEN");
        kb_env = !((e && *e == '0') || (h && *h && *h != '0'));     // (kb_active's switches)
    }
    if (port == 0 && kb_env && !kb_active() && SDL_WasInit(SDL_INIT_VIDEO)) {
        HulkPadState k;
        kb_read(&k);
        s.buttons |= k.buttons;
        for (int i = 0; i < 8; i++)
            if (k.analog[i] > s.analog[i])
                s.analog[i] = k.analog[i];
        if (k.thumb[HULK_THUMB_LX] || k.thumb[HULK_THUMB_LY]) {
            s.thumb[HULK_THUMB_LX] = k.thumb[HULK_THUMB_LX];
            s.thumb[HULK_THUMB_LY] = k.thumb[HULK_THUMB_LY];
        }
        if (k.thumb[HULK_THUMB_RX] || k.thumb[HULK_THUMB_RY]) {
            s.thumb[HULK_THUMB_RX] = k.thumb[HULK_THUMB_RX];
            s.thumb[HULK_THUMB_RY] = k.thumb[HULK_THUMB_RY];
        }
    }
    memcpy(out18, &s, 18);
    return 1;
}
