#include "compat/ptr.h"
extern "C" char DAT_00423f28[];
typedef unsigned int u32_1e8960;
extern void* __cdecl alloc(unsigned int, unsigned int);
struct SoundMix {
    u32_1e8960* vptr;
    u32_1e8960 a;
    u32_1e8960 b;
};
class Manager_1e8960 {
  public:
    char pad[0x4c0];
    SoundMix* slots[20];
    int count;
    SoundMix* Add();
};
SoundMix* Manager_1e8960::Add() {
    if (count >= 20)
        return 0;
    SoundMix* p = (SoundMix*)alloc(0x10, 6);
    if (p != 0) {
        p->vptr = (u32_1e8960*)((hulk_intptr)DAT_00423f28);
        p->a = 0;
        p->b = 0;
    } else {
        p = 0;
    }
    slots[count] = p;
    SoundMix* result = slots[count];
    ++count;
    return result;
}
