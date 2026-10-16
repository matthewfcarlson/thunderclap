#include "gen/pure3d.h"

class Ref_3220a0 {
  public:
    virtual void f0();
    virtual void f1();
};
struct Block_3220a0 {
    unsigned int x[16];
};

void pure3d::d3dExtGlobalProjectedTexture::vfunc_1(int index, void* __p1, void* __p2) { Block_3220a0 * data = (Block_3220a0 *)__p1; Ref_3220a0 * ref = (Ref_3220a0 *)__p2;

    Block_3220a0* dest = (Block_3220a0*)((char*)this + index * 0x40 + 0x44);
    *dest = *data;
    if (ref)
        ref->f0();
    Ref_3220a0** p = (Ref_3220a0**)((char*)this + index * 4 + 4);
    if (*p)
        (*p)->f1();
    *p = ref;
}
