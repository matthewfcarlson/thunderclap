#include "gen/fight.h"

extern "C" char DAT_00428d24[];
class Ref_23e330 {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Action_23e330 {
  public:
    virtual void v0();
    void Init();
};
extern void* Alloc(unsigned int);

int fight::WaitTrack::vfunc_10(int __p0, int __p1, int __p2) { void * p2 = (void *)__p0; void * p3 = (void *)__p1; Ref_23e330 * p4 = (Ref_23e330 *)__p2;

    Action_23e330* r = (Action_23e330*)Alloc(0x28);
    if (r) {
        r->Init();
        *(void**)((char*)r + 0x1c) = this;
        *(unsigned long*)r = ((int)DAT_00428d24);
        *(unsigned long*)((char*)r + 0x20) = 0;
        if (p4)
            p4->AddRef();
        Ref_23e330* old = *(Ref_23e330**)((char*)r + 0x20);
        if (old)
            old->Release();
        *(Ref_23e330**)((char*)r + 0x20) = p4;
        return (int)(r);
    }
    return (int)(0);
}
