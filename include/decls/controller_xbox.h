// core::ControllerXBox's records (x64t11; were in decls/data/records.h, which includes this): a pad of the controller
// system and its inputs and motors, as the constructor 0x00268fa0 and the open 0x002692c0 write them
// (src/platform/xbox/core/ControllerXBox.cpp). gen/core.h's core::ControllerXBox and core::ControllerSystemXBox hold
// them as members, so the classes' methods and these records place every word alike on every target (natively the
// pad is 0x710 bytes, not 0x4a0: the inputs' names and callbacks, the handle and the buffer are pointers).
#ifndef HULK_DECLS_CONTROLLER_XBOX_H
#define HULK_DECLS_CONTROLLER_XBOX_H

#include "compat/ptr.h"

// core::ControllerInputPointXBox (vftable 0x0042b24c; 0x00268fa0 constructs 20 per pad, 0x002692c0 binds them
// to the XInput state table 0x004cd6a8): one button or axis of a pad.
struct CoreControllerInputPointXBox {
    const void* vftable;                    // +0x00
    int refs;                               // +0x04 (0x00268cd0 / 0x00268ce0)
    float value;                            // +0x08 (0x00268d10 / 0x00268f00 store 0x00268d30's reading)
    float minimum;                          // +0x0c (0x00268ec0 sets, 0x00268ea0 / 0x00268ee0 read)
    float maximum;                          // +0x10 (1.0 at construction)
    float threshold;                        // +0x14 the change threshold (0x00268e10 clamps it to 0..1)
    int heldTime;                           // +0x18 (0x00268f00, 0x00268ea0)
    int changeTime;                         // +0x1c (0x00268cf0, 0x00268f00)
    const char* type;                       // +0x20 the state table's type name (0x00268d30 compares it with
                                            //       DAT_004cd698..DAT_004cd6a4; vfunc 0x00268e00 returns it)
    const char* name;                       // +0x24 (vfunc 0x00268df0 returns it; 0x00268a10 compares names)
    unsigned int field;                     // +0x28 the button mask or the byte offset into the state (0x00268d30)
    void* callback;                         // +0x2c the change callback (0x00268e60 sets, 0x00268e80 clears,
                                            //       0x00268f00 calls its slot 0)
    hulk_uintptr callbackArgument;          // +0x30 0x00268e60's 2nd argument, passed back by 0x00268f00
};

// core::ControllerOutputPointXBox (vftable 0x0042b228): a pad's motor (2 per pad).
struct CoreControllerOutputPointXBox {
    const void* vftable;                    // +0x00
    int refs;                               // +0x04 (0x00268be0 / 0x00268bf0)
    const char* name;                       // +0x08 "LeftMotor" / "RightMotor" (0x002692c0; vfunc 0x00268c00 returns it)
    float value;                            // +0x0c 0..1 (0x00268c30 clamps, 0x00268c20 returns; 0x002685a0 reads)
};

// core::ControllerXBox (vftable 0x0042b14c; 0x00268fa0 constructs it, 0x002692c0 opens it on a port, 0x00268520
// destroys it): one pad of the controller system (4 of them inline, 0x4a0 bytes apart).
struct CoreControllerXBox {
    const void* vftable;                    // +0x000
    int refs;                               // +0x004 (0x00268580 / 0x00268590; 0x002685a0 polls only while > 0)
    hulk_uintptr handle;                    // +0x008 the XInput handle (0x002692c0; 0x002685a0, 0x00268780, 0x00268520)
    int port;                               // +0x00c (0x002692c0)
    int slot;                               // +0x010 (0x002692c0)
    unsigned int inputCount;                // +0x014 20 (0x002692c0; 0x00268b10 returns it)
    CoreControllerInputPointXBox inputs[20];   // +0x018 (0x00268b20)
    CoreControllerOutputPointXBox outputs[2];  // +0x428 (0x00268b50)
    char name[12];                          // +0x448 "Portx\Slotx" with the digits (0x002692c0; 0x00268b00 returns it)
    void* buffer;                           // +0x454 the core::ControllerBuffer (0x002692c0's last argument;
                                            //        0x00268690 / 0x002686d0 / 0x00268760 call it)
    // +0x458 the XInputSetState feedback (0x002692c0 clears 0x46 bytes; 0x002685a0): inline, the next byte is at
    // +0x49e (a nested struct would round to 0x48)
    unsigned int feedbackStatus;            // +0x458 ERROR_IO_PENDING (0x3e5) while a rumble is in flight
    hulk_uintptr feedbackEvent;             // +0x45c the header's event handle (0x002685a0 clears it)
    unsigned char feedbackReserved[0x3a];   // +0x460
    unsigned short leftMotor;               // +0x49a 0..65535 (0x002685a0)
    unsigned short rightMotor;              // +0x49c
    unsigned char connected;                // +0x49e (0x002692c0 sets 1; the system's loops test it)
    unsigned char pad49f;                   // +0x49f
};

#endif
