// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 16/16)
// FUN_002691f0 @ 0x002691f0
#include "decls/data/platform/xbox/core.h"

struct Device_2691f0 {
    virtual void slot0(); virtual void slot1(); virtual void slot2(); virtual void slot3();
    virtual void slot4(); virtual void slot5(); virtual void slot6(); virtual void slot7();
    virtual void slot8(); virtual void slot9(); virtual void slot10(); virtual void slot11();
    virtual void slot12(); virtual void slot13(); virtual void slot14(); virtual void slot15();
    virtual void slot16(); virtual void slot17(); virtual void slot18(); virtual void slot19();
    virtual void slot20(); virtual void slot21(void*);
    char padding[0x49a];
    unsigned char active;
    char endpad;
    void FUN_002692c0(void*, unsigned, unsigned, unsigned, unsigned, unsigned, unsigned);
};
struct Observer_2691f0 { virtual void slot0(Device_2691f0*); };
struct Manager_2691f0 {
    char pad[0x14];
    unsigned base;
    unsigned param;
    Observer_2691f0* observer;
    Device_2691f0 devices[4];
    unsigned extra;
    void FUN_002691f0();
};
extern int DAT_003ea774;
namespace XAPILIB {
    int __stdcall XGetDeviceChanges(int*, unsigned*, unsigned*);
    void* __stdcall XInputOpen(int*, unsigned, unsigned, unsigned);
}
extern unsigned FUN_00267f80();
void Manager_2691f0::FUN_002691f0() {
    unsigned inserted = 0, removed = 0;
    if (!XAPILIB::XGetDeviceChanges(&DAT_003ea774, &inserted, &removed)) return;
    for (unsigned i = 0; i < 4; ++i) {
        if (((inserted | removed) & (1u << i)) == 0) continue;
        Device_2691f0& device = devices[i];
        void* handle = XAPILIB::XInputOpen(&DAT_003ea774, i, 0, 0);
        if (handle) {
            if (device.active) device.slot21(handle);
            else {
                unsigned time = FUN_00267f80();
                device.FUN_002692c0(handle, i, 0, time + base, param, extra, ((unsigned*)&DAT_00528388)[i]);
            }
        } else if (device.active) {
            device.slot21(0);
        }
        if (observer) observer->slot0(&device);
    }
}