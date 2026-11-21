/* XInput (XPP) by address (src/platform/sdl/xdk/imports.h): pad 0 is a gamepad; its state is the sim block's, which
 * the host fills each frame (a replay's input, or none). Memory units: none. */
#include "hulk_host.h"
#include "sim.h"

#define XDEVICE_TYPE_GAMEPAD 0x003ea774u    /* the device type descriptors the game passes (src/platform/sdl/xdk/library.h) */

FFG(003eba7c) { UNUSED; }                                                       /* XInitDevices */
FFG(003eba81) { UNUSED; RET(ARG(0) == XDEVICE_TYPE_GAMEPAD ? SIM->pads_in : 0); }   /* XGetDevices */
FFG(003ebaa3) {         /* XGetDeviceChanges(type, inserted*, removed*): pad changes since the last ask */
    UNUSED;
    uint32_t ins = 0, rem = 0;
    if (ARG(0) == XDEVICE_TYPE_GAMEPAD) {
        ins = SIM->pads_in & ~SIM->pads_reported;
        rem = SIM->pads_reported & ~SIM->pads_in;
        SIM->pads_reported = SIM->pads_in;
    }
    *(uint32_t*)PTR(ARG(1)) = ins;
    *(uint32_t*)PTR(ARG(2)) = rem;
    RET(ins || rem);
}
FFG(003eb6e5) {         /* XInputOpen(type, port, slot, parameters) -> handle */
    UNUSED;
    uint32_t port = ARG(1);
    if (ARG(0) != XDEVICE_TYPE_GAMEPAD || port > 3 || !(SIM->pads_in & (1u << port))) { RET(0); return; }
    RET(0x00007000u + port * 16);
}
FFG(003eb73b) { UNUSED; RET(0); }                                               /* XInputClose */
FFG(003eb91f) {         /* XInputGetState(handle, XINPUT_STATE*) */
    UNUSED;
    uint32_t port = (ARG(0) - 0x7000u) / 16;
    if (port > 3) { RET(1167); return; }                    /* ERROR_DEVICE_NOT_CONNECTED */
    uint8_t* s = PTR(ARG(1));
    *(uint32_t*)s = SIM->frame;                             /* dwPacketNumber */
    memcpy(s + 4, SIM->pads[port], 18);                     /* XINPUT_GAMEPAD */
    RET(0);
}
FFG(003eb992) { UNUSED; RET(0); }                                               /* XInputSetState (rumble) */
FFG(003ebfe2) { UNUSED; RET(1167); }                                            /* XMountMUA: no memory unit */
FFG(003ec280) { UNUSED; RET(0); }                                               /* XUnmountMU */
