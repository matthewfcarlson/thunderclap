typedef unsigned int u32;
extern void* __cdecl alloc(unsigned int, unsigned int);
struct SoundMix { u32* vptr; u32 a; u32 b; };
class Manager { public: char pad[0x4c0]; SoundMix* slots[20]; int count; SoundMix* Add(); };
SoundMix* Manager::Add() {
    if (count >= 20) return 0;
    SoundMix* p = (SoundMix*)alloc(0x10, 6);
    if (p != 0) {
        p->vptr = (u32*)0x423f28;
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
