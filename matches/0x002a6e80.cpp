#include "compat/ptr.h"
#include "gen/pure3d.h"

extern "C" char DAT_0042da6c[];
void* __cdecl alloc(hulk_uintptr);

class Base_2a6e80 {
  public:
    void init(pure3d::VertexAnimController*);
};
class Helper_2a6e80 {
  public:
    virtual void release();
    virtual void destroy();
};

void* pure3d::VertexAnimController::vfunc_4() {
    pure3d::VertexAnimController* p = (pure3d::VertexAnimController*)alloc(0x48);
    if (p) {
        ((Base_2a6e80*)p)->init(this);
        *(hulk_uintptr*)p = ((hulk_intptr)DAT_0042da6c);
        (*(Helper_2a6e80 * *)&p->f_40) = 0;
        Helper_2a6e80* old = (*(Helper_2a6e80 * *)&this->f_40);
        if (old)
            old->release();
        Helper_2a6e80* cur = (*(Helper_2a6e80 * *)&p->f_40);
        if (cur)
            cur->destroy();
        (*(Helper_2a6e80 * *)&p->f_40) = old;
        return (void*)(p);
    }
    return (void*)(0);
}
