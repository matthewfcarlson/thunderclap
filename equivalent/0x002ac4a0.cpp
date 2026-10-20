// STATUS: equivalent (tools/equiv.py level 3: 69 inputs, branch coverage 4/4)
// FUN_002ac4a0 @ 0x002ac4a0
// equiv-map: ??0ParticleAllocator@pure3d@@QAE@XZ = 0x002d3d90
#include "compat/ptr.h"

namespace pure3d {

struct SpriteParticle {
    char data[0x40];
};

class ParticleAllocator {
public:
    ParticleAllocator();
    virtual void v0();
    char pad04[4];
};

struct IndexVec {
    unsigned int *begin;
    unsigned int *end;
    bool FUN_002ab880(unsigned int n, const unsigned int *def);
};

template <class T>
struct ParticleVec {
    T *begin;
    T *end;
    bool FUN_002aba80(unsigned int n, const T *def);
};

template <class T>
class ParticleAllocatorTemplate : public ParticleAllocator {
public:
    unsigned int count;     // 8
    IndexVec free;          // 0xc
    char pad14[4];
    ParticleVec<T> pool;    // 0x18
    ParticleAllocatorTemplate(unsigned int bytes);
    virtual void v0();
};

template <>
ParticleAllocatorTemplate<SpriteParticle>::ParticleAllocatorTemplate(unsigned int bytes)
{
    free.begin = 0;
    free.end = 0;
    pool.begin = 0;
    pool.end = 0;
    count = bytes >> 6;
    bytes = 0;
    free.FUN_002ab880(count, &bytes);
    char proto[0x40];   // callee takes a pointer 0xc bytes into this scratch
    pool.FUN_002aba80(count, (const SpriteParticle *)(proto + 0xc));
    for (unsigned int i = 0; i < count; i++)
        free.begin[i] = (hulk_uintptr)(pool.begin + (count - i - 1));
}

}
