// STATUS: equivalent (tools/equiv.py level 3: 35 inputs, branch coverage 28/28)
// FUN_002d63f0 @ 0x002d63f0
#include "compat/ptr.h"
void *__cdecl FUN_0008d6d0(hulk_uintptr size);

class RefCounted_2d63f0 {
public:
    virtual void addRef();
    virtual void release();
};

class __declspec(novtable) EmitterBase_2d63f0 {
public:
    virtual void b0();
    char pad04[0x94 - 4];
    unsigned int count;      // 0x94
    char pad98[0xa8 - 0x98];
    void FUN_002d4a20(const EmitterBase_2d63f0 *other);
    EmitterBase_2d63f0(const EmitterBase_2d63f0 &other) { FUN_002d4a20(&other); }
};

class EmitterState {
public:
    char data[0x1bc - 0xa8];
    void FUN_002d4e80(const EmitterState *other);
    EmitterState(const EmitterState &other) { FUN_002d4e80(&other); }
};

class SpriteParticleEmitter : public EmitterBase_2d63f0 {
public:
    virtual void f1();
    EmitterState state;      // 0xa8
    RefCounted_2d63f0 *ref1bc;
    RefCounted_2d63f0 *ref1c0;
    RefCounted_2d63f0 *ref1c4;
    int *vec1c8;
    int *vec1cc;
    char pad1d0[4];
    RefCounted_2d63f0 **vec1d4;
    RefCounted_2d63f0 **vec1d8;

    static void Assign(RefCounted_2d63f0 **slot, RefCounted_2d63f0 *p) {
        if (p)
            p->addRef();
        RefCounted_2d63f0 *old = *slot;
        if (old)
            old->release();
        *slot = p;
    }

    SpriteParticleEmitter(const SpriteParticleEmitter &other);
};

SpriteParticleEmitter::SpriteParticleEmitter(const SpriteParticleEmitter &other)
    : EmitterBase_2d63f0(other), state(other.state)
{
    ref1bc = 0;
    ref1c0 = 0;
    ref1c4 = 0;

    hulk_uintptr n = other.vec1cc - other.vec1c8;
    if (n != 0) {
        int *p = (int *)FUN_0008d6d0(n * 4);
        vec1c8 = p;
        if (p) {
            vec1cc = (int *)((char *)p + n * 4);
        } else {
            vec1c8 = 0;
            vec1cc = 0;
        }
    } else {
        vec1c8 = 0;
        vec1cc = 0;
    }

    hulk_uintptr m = other.vec1d8 - other.vec1d4;
    if (m != 0) {
        RefCounted_2d63f0 **p = (RefCounted_2d63f0 **)FUN_0008d6d0(m * 4);
        vec1d4 = p;
        if (p) {
            vec1d8 = (RefCounted_2d63f0 **)((char *)p + m * 4);
        } else {
            vec1d4 = 0;
            vec1d8 = 0;
        }
    } else {
        vec1d4 = 0;
        vec1d8 = 0;
    }

    Assign(&ref1bc, other.ref1bc);
    for (unsigned int i = 0; i < count; i++) {
        vec1d4[i] = 0;
        Assign(&vec1d4[i], other.vec1d4[i]);
    }
    Assign(&ref1c0, other.ref1c0);
    Assign(&ref1c4, other.ref1c4);
}
