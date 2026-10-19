// Input: XPP / XInput for the native image, on the input backend (src/platform/sdl/input/hulk_input.h,
// docs/native-audio-input.md). Each stand-in counts its calls (xdk_shim.h). Shapes from the game's call sites
// (docs/platform-boundary.md, rules 1-3):
//
//   0x26f020 / 0x26f070  XInitDevices(0, 0)
//   0x2691f0  XGetDeviceChanges(gamepad type, &inserted, &removed) -> BOOL, then XInputOpen(type, port, 0, 0) for
//             every changed port: the game opens pads only here, so the pads present at start-up are reported as
//             inserted by the first call (as on the Xbox)
//   0x278060 / 0x278500  XGetDeviceChanges / XGetDevices(memory-unit type): no memory units here
//   0x2685a0  XInputGetState(handle, 22 bytes): u32 packet number + the gamepad (hulk_input.h: layout from the
//             game's own table at 0x4cd6a8); 0 = success. XInputSetState(handle, feedback): the game skips rumble
//             while the feedback's status word (+0) reads ERROR_IO_PENDING; the motors are the two words at +0x42
//   0x268520 / 0x268780 / 0x269590  XInputClose(handle)
//
// Device types are identified by address: the game passes XPP's descriptors (library data, src/platform/sdl/xdk/
// library.h: hulk_lib_xpp_gamepad_type / hulk_lib_xpp_mu_type), or the XBE addresses as literals.
#include "imports.h"

// HULK_NATIVE_SDL: built with the SDL3 backends (tools/native_sdl.py; the native link once build/sa1/for-native9.md
// is in). Without it, the first skeleton's stand-ins: count the call, return 0.
#if defined(HULK_NATIVE_SDL)
#include "../input/hulk_input.h"

typedef __SIZE_TYPE__ hulk_uptr;

#define HULK_ERROR_SUCCESS 0u
#define HULK_ERROR_DEVICE_NOT_CONNECTED 1167u

extern "C" hulk_u32 hulk_lib_xpp_gamepad_type[1];     // library.cpp

static bool is_gamepad(hulk_u32 type)
{
    return type == (hulk_u32)(hulk_uptr)hulk_lib_xpp_gamepad_type || type == 0x003ea774u;
}

// handles: one per XInputOpen (a re-open of the same port gets a new one: the game closes the old handle after it
// stores the new one, 0x268780)
struct PadHandle {
    int open;
    unsigned port;
    unsigned gen;
    hulk_u32 packet;
    unsigned char last[18];
};
static PadHandle g_handles[16];

static PadHandle* handle(hulk_u32 h)
{
    for (unsigned i = 0; i < sizeof(g_handles) / sizeof(g_handles[0]); i++)
        if ((hulk_u32)(hulk_uptr)&g_handles[i] == h)
            return g_handles[i].open ? &g_handles[i] : 0;
    return 0;
}

extern "C" void HULK_CDECL hulk_native_log(const char* line);

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInitDevices(hulk_u32 count, hulk_u32 types) {
    (void)count; (void)types;
    HULK_XDK_TRACE("XInitDevices");
    hulk_input_init();
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGetDevices(hulk_u32 type) {
    HULK_XDK_TRACE("XGetDevices");
    return is_gamepad(type) ? hulk_input_devices() : 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGetDeviceChanges(hulk_u32 type, hulk_u32 ins_out, hulk_u32 rem_out) {
    HULK_XDK_TRACE("XGetDeviceChanges");
    unsigned ins = 0, rem = 0;
    int any = is_gamepad(type) ? hulk_input_changes(&ins, &rem) : 0;
    if (ins_out)
        *(hulk_u32*)(hulk_uptr)ins_out = ins;
    if (rem_out)
        *(hulk_u32*)(hulk_uptr)rem_out = rem;
    return any ? 1 : 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputOpen(hulk_u32 type, hulk_u32 port, hulk_u32 slot, hulk_u32 params) {
    (void)slot; (void)params;
    HULK_XDK_TRACE("XInputOpen");
    if (!is_gamepad(type) || port >= HULK_INPUT_PORTS || !(hulk_input_devices() & (1u << port)))
        return 0;
    for (unsigned i = 0; i < sizeof(g_handles) / sizeof(g_handles[0]); i++) {
        PadHandle* h = &g_handles[i];
        if (h->open)
            continue;
        h->open = 1;
        h->port = port;
        h->gen = hulk_input_generation(port);
        h->packet = 0;
        for (int k = 0; k < 18; k++)
            h->last[k] = 0;
        return (hulk_u32)(hulk_uptr)h;
    }
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputClose(hulk_u32 h) {
    HULK_XDK_TRACE("XInputClose");
    PadHandle* p = handle(h);
    if (p)
        p->open = 0;
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputGetState(hulk_u32 h, hulk_u32 out) {
    HULK_XDK_TRACE("XInputGetState");
    PadHandle* p = handle(h);
    HulkPadState s;
    if (!p || !out || hulk_input_generation(p->port) != p->gen || !hulk_input_read(p->port, &s))
        return HULK_ERROR_DEVICE_NOT_CONNECTED;
    unsigned char b[18];
    b[0] = (unsigned char)s.buttons;
    b[1] = (unsigned char)(s.buttons >> 8);
    for (int i = 0; i < 8; i++)
        b[2 + i] = s.analog[i];
    for (int i = 0; i < 4; i++) {
        b[10 + 2 * i] = (unsigned char)s.thumb[i];
        b[11 + 2 * i] = (unsigned char)((unsigned short)s.thumb[i] >> 8);
    }
    bool changed = false;
    for (int i = 0; i < 18; i++) {
        changed = changed || b[i] != p->last[i];
        p->last[i] = b[i];
    }
    if (changed)
        p->packet++;
    unsigned char* o = (unsigned char*)(hulk_uptr)out;
    o[0] = (unsigned char)p->packet;
    o[1] = (unsigned char)(p->packet >> 8);
    o[2] = (unsigned char)(p->packet >> 16);
    o[3] = (unsigned char)(p->packet >> 24);
    for (int i = 0; i < 18; i++)
        o[4 + i] = b[i];
    return HULK_ERROR_SUCCESS;
}

// feedback: +0 status (ERROR_IO_PENDING while the Xbox works on it; we finish at once), +0x42 left motor (the large,
// low-frequency one), +0x44 right motor, 0..65535
extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputSetState(hulk_u32 h, hulk_u32 feedback) {
    HULK_XDK_TRACE("XInputSetState");
    if (!feedback)
        return HULK_ERROR_SUCCESS;
    unsigned char* f = (unsigned char*)(hulk_uptr)feedback;
    PadHandle* p = handle(h);
    if (p && hulk_input_generation(p->port) == p->gen)
        hulk_input_rumble(p->port, (unsigned short)(f[0x42] | (f[0x43] << 8)), (unsigned short)(f[0x44] | (f[0x45] << 8)));
    f[0] = f[1] = f[2] = f[3] = 0;      // status: done
    return p ? HULK_ERROR_SUCCESS : HULK_ERROR_DEVICE_NOT_CONNECTED;
}

#else  // !HULK_NATIVE_SDL

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInitDevices(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1; HULK_XDK_TRACE("XInitDevices");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputOpen(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2, hulk_u32 a3) {
    (void)a0; (void)a1; (void)a2; (void)a3; HULK_XDK_TRACE("XInputOpen");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputClose(hulk_u32 a0) {
    (void)a0; HULK_XDK_TRACE("XInputClose");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputGetState(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1; HULK_XDK_TRACE("XInputGetState");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XInputSetState(hulk_u32 a0, hulk_u32 a1) {
    (void)a0; (void)a1; HULK_XDK_TRACE("XInputSetState");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGetDevices(hulk_u32 a0) {
    (void)a0; HULK_XDK_TRACE("XGetDevices");
    return 0;
}

extern "C" hulk_u32 HULK_STDCALL hulk_xdk_XGetDeviceChanges(hulk_u32 a0, hulk_u32 a1, hulk_u32 a2) {
    (void)a0; (void)a1; (void)a2; HULK_XDK_TRACE("XGetDeviceChanges");
    return 0;
}

#endif
