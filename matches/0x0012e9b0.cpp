#include "compat/ptr.h"
extern "C" char DAT_00411314[];
typedef unsigned int u32_12e9b0;
struct NISSoundTrack {
    hulk_uintptr vptr;
    char pad[12];
    u32_12e9b0 a, b, c;
    void BaseDestroy();
    void Destroy();
};
extern void __cdecl ReleaseThing(u32_12e9b0);
void NISSoundTrack::Destroy() {
    vptr = ((hulk_intptr)DAT_00411314);
    ReleaseThing(a);
    ReleaseThing(b);
    ReleaseThing(c);
    BaseDestroy();
}