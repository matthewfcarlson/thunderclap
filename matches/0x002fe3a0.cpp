#include "compat/ptr.h"
extern "C" char DAT_004319a4[];
class Ref_2fe3a0 {
  public:
    virtual void First();
    virtual void Release();
};
class SimState_2fe3a0 {
  public:
    SimState_2fe3a0(void*);
};
class SimStateHairclub : public SimState_2fe3a0 {
  public:
    char pad0[0x85];
    unsigned char flag;
    char pad1[2];
    Ref_2fe3a0* mRef;
    SimStateHairclub(Ref_2fe3a0* r, void* p);
};
SimStateHairclub::SimStateHairclub(Ref_2fe3a0* r, void* p) : SimState_2fe3a0(p) {
    *(void**)this = (void*)((hulk_intptr)DAT_004319a4);
    mRef = 0;
    if (r)
        r->First();
    if (mRef)
        mRef->Release();
    mRef = r;
    flag = 1;
}