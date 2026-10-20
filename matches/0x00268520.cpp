#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042b14c[];
extern "C" void __stdcall XInputClose(void*);
struct ControllerXBox {
    char p0[8];
    void* handle;
    char p[0x41c];
    void Shutdown();
};
void ControllerXBox::Shutdown() {
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_0042b14c);
    if (handle)
        XInputClose(handle);
    unsigned long* q = (unsigned long*)((char*)this + 0x448);
    int n = 2;
    do {
        q -= 4;
        n--;
        *q = ((hulk_intptr)DAT_003f6098);
    } while (n);
    q = (unsigned long*)((char*)this + 0x428);
    n = 0x14;
    do {
        q -= 0xd;
        n--;
        *q = ((hulk_intptr)DAT_003f6098);
    } while (n);
    *(hulk_ulongptr*)this = ((hulk_intptr)DAT_003f6098);
}
