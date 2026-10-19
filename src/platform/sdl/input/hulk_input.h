// The native input backend (docs/native-audio-input.md): Xbox controller state from an input source. Typed and
// pointer-sized; src/platform/sdl/xdk/input_xpp.cpp gives the game the XPP shape (handles, XINPUT_STATE,
// XGetDeviceChanges) on top of it.
#ifndef HULK_PLATFORM_SDL_INPUT_H
#define HULK_PLATFORM_SDL_INPUT_H

#ifdef __cplusplus
extern "C" {
#endif

#define HULK_INPUT_PORTS 4

// The Xbox gamepad (the 18 bytes after XINPUT_STATE's packet number). Layout and bits from the game's own table at
// 0x4cd6a8 (name, offset, bit): buttons word, then 8 analog buttons, then the thumbs.
enum {
    HULK_PAD_DPAD_UP = 0x01, HULK_PAD_DPAD_DOWN = 0x02, HULK_PAD_DPAD_LEFT = 0x04, HULK_PAD_DPAD_RIGHT = 0x08,
    HULK_PAD_START = 0x10, HULK_PAD_BACK = 0x20, HULK_PAD_LEFT_THUMB = 0x40, HULK_PAD_RIGHT_THUMB = 0x80
};
enum {
    HULK_PAD_A = 0, HULK_PAD_B = 1, HULK_PAD_X = 2, HULK_PAD_Y = 3, HULK_PAD_BLACK = 4, HULK_PAD_WHITE = 5,
    HULK_PAD_LEFT_TRIGGER = 6, HULK_PAD_RIGHT_TRIGGER = 7
};
enum { HULK_THUMB_LX = 0, HULK_THUMB_LY = 1, HULK_THUMB_RX = 2, HULK_THUMB_RY = 3 };

typedef struct HulkPadState {
    unsigned short buttons;     // +0x0
    unsigned char analog[8];    // +0x2: A B X Y Black White LeftTrigger RightTrigger, 0..255
    short thumb[4];             // +0xa: LX LY RX RY, -32768..32767, Y positive up
} HulkPadState;

// An input source: what the XPP layer reads. SDL gamepads (default) or, later, a recorded stream for native
// replays (design in docs/native-audio-input.md). Ports are 0..3.
typedef struct HulkInputSource {
    const char* name;
    void* self;
    void (*update)(void* self);                                   // pump the source; detects hot-plug
    unsigned (*connected)(void* self);                            // bit p: a pad in port p
    unsigned (*generation)(void* self, unsigned port);            // changes whenever port p's pad changes
    int (*read)(void* self, unsigned port, HulkPadState* out);    // 1: read, 0: no pad
    void (*rumble)(void* self, unsigned port, unsigned short left, unsigned short right);
} HulkInputSource;

// Starts input (idempotent): the source from HULK_INPUT_SOURCE ("sdl", the default; "none"), unless
// hulk_input_set_source ran first. Pads present now are reported as inserted by the first hulk_input_changes.
int hulk_input_init(void);
void hulk_input_shutdown(void);
void hulk_input_set_source(const HulkInputSource* src);       // tests and replays; 0 = back to the default
const HulkInputSource* hulk_input_source(void);
const HulkInputSource* hulk_input_sdl_source(void);           // the SDL3 gamepad source

// Xbox semantics on top of the source (XGetDevices / XGetDeviceChanges): bits per port.
unsigned hulk_input_devices(void);
int hulk_input_changes(unsigned* inserted, unsigned* removed);   // since the last call; 1 when anything changed
int hulk_input_read(unsigned port, HulkPadState* out);
void hulk_input_rumble(unsigned port, unsigned short left, unsigned short right);
unsigned hulk_input_generation(unsigned port);

// SDL -> Xbox conversions (exposed for the tests)
unsigned char hulk_input_trigger(short sdl_axis);      // 0..32767 -> 0..255
short hulk_input_thumb_y(short sdl_axis);              // SDL positive-down -> Xbox positive-up

#ifdef __cplusplus
}
#endif

#endif
