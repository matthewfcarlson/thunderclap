#include "compat/ptr.h"
extern void* Alloc(hulk_uintptr);
inline void* operator new(unsigned int, void* p) {
    return p;
}
class Params_592c0 {
  public:
    virtual void b0();
    Params_592c0();
};
class CFightParams : public Params_592c0 {
  public:
    CFightParams(int x) : Params_592c0() {
        field8 = x;
        fieldc = 0;
        field10 = 0;
    }
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual CFightParams* vfunc_4();
    int pad4;
    int field8;
    int fieldc;
    int field10;
};
CFightParams* CFightParams::vfunc_4() {
    void* mem = Alloc(0x14);
    if (mem) {
        int x = field8;
        return new (mem) CFightParams(x);
    }
    return 0;
}
