#include "compat/ptr.h"
extern "C" char DAT_00428824[];
struct ThisCall_00232e90 {
    void AllocRef(int);
};
void __fastcall InitSub(void* p);

class Reference_23c2c0 {
  public:
    virtual void f();
    char pad[0x24];
    Reference_23c2c0* init();
};

Reference_23c2c0* Reference_23c2c0::init() {
    ((ThisCall_00232e90*)(this))->AllocRef(4);
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00428824);
    InitSub((char*)this + 0x28);
    return this;
}
