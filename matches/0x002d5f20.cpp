#include "compat/ptr.h"
extern "C" double __cdecl __floor_default(double);
struct SpriteParticleEmitter_2d5f20;
struct Backend_2d5f20 {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void update(int);
    virtual int consume(int, void*, int, int, SpriteParticleEmitter_2d5f20*);
};
struct SpriteParticleEmitter_2d5f20 {
    char pad0[0x88];
    Backend_2d5f20* backend;
    char pad1[0xb0 - 0x8c];
    char data[0x14c - 0xb0];
    int used;
    float credit;
    char pad2[0x1c8 - 0x154];
    int* begin;
    int* end;
    void target(int a, int b, int c);
};
void SpriteParticleEmitter_2d5f20::target(int a, int b, int c) {
    if (!backend)
        return;
    backend->update(a);
    int available = ((int)((hulk_ulongptr)end - (hulk_ulongptr)begin) >> 2) - used;
    if ((float)available < credit)
        credit = (float)available;
    if (credit >= 1.0f) {
        double count = __floor_default(credit);
        Backend_2d5f20* current = backend;
        int taken = current->consume((int)count, data, c, b, this);
        credit -= (float)taken;
    }
}
