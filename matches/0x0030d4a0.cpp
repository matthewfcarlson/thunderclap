// Same code shape as 0x0030d320 (propagated; names are from that function)
#include "compat/ptr.h"
struct Sub_30d4a0 {
    void Destruct();
};

extern "C" void __cdecl FreeBuf(void*);
extern "C" void __cdecl DeleteObj(void*);
extern "C" char DAT_00431de4[];

class PhysicsJoint3D_30d4a0 {
  public:
    void* vptr;
    char pad1[0x20 - 4];
    int m20;
    hulk_intptr m24;
    char pad2[0x48 - 0x28];
    Sub_30d4a0 m48;
    char pad3[0x64 - 0x49];
    Sub_30d4a0 m64;

    void* vfunc_0(int flags);
};

void* PhysicsJoint3D_30d4a0::vfunc_0(int flags) {
    Sub_30d4a0* p = &m64;
    vptr = (void*)DAT_00431de4;
    p->Destruct();
    m48.Destruct();
    hulk_intptr v = m20;
    m24 = v;
    if (v)
        FreeBuf((void*)v);
    if (flags & 1)
        DeleteObj(this);
    return this;
}
