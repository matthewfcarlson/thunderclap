#include "decls/data/engine/fight.h"

extern "C" void _ReadWriteBarrier();
extern void* vAction[];
extern void* vIRef[];
extern void FUN_00267090(void*);
class Ref_232700 {
  public:
    virtual void F0();
    virtual void Release();
};
struct Action_232700 {
    void* vf;
    int p4;
    Ref_232700* p8;
    Action_232700* Dtor(unsigned char flag) throw();
};
Action_232700* Action_232700::Dtor(unsigned char flag) throw() {
    vf = vAction;
    _ReadWriteBarrier();
    if (p8) {
        p8->Release();
        p8 = 0;
    }
    DAT_004e5af0 = DAT_004e5af0 - 1;
    vf = vIRef;
    if (flag & 1)
        FUN_00267090(this);
    return this;
}
