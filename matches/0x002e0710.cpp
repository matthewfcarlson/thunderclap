#include "compat/ptr.h"
#include "gen/pure3d.h"

extern "C" char DAT_0042fc74[];
class Ref_2e0710 {
  public:
    virtual void f0();
    virtual void f1();
};
struct PrimGroupSkinnedPC_nv_2e0710 {
    void init(pure3d::PrimGroupSkinnedPC*);
};
extern void* alloc(hulk_uintptr);

void* pure3d::PrimGroupSkinnedPC::vfunc_4() {
    pure3d::PrimGroupSkinnedPC* p = (pure3d::PrimGroupSkinnedPC*)alloc(0x70);
    if (p) {
        ((PrimGroupSkinnedPC_nv_2e0710*)(p))->init(this);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042fc74);
        *(unsigned int*)((char*)p + 0x68) = 0;
        Ref_2e0710* r = (*(Ref_2e0710 * *)&this->f_68);
        if (r)
            r->f0();
        Ref_2e0710* q = *(Ref_2e0710**)((char*)p + 0x68);
        if (q)
            q->f1();
        *(Ref_2e0710**)((char*)p + 0x68) = r;
        return (void*)(p);
    }
    return (void*)(0);
}
