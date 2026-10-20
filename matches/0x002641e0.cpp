#include "compat/ptr.h"
extern "C" char DAT_003f6098[];
extern "C" char DAT_0042ae9c[];
class Obj_2641e0 {
  public:
    virtual void X();
    virtual void Release();
};
class LoadStream {
  public:
    hulk_uintptr vt;
    unsigned int p4;
    Obj_2641e0* mObj;
    unsigned int pC[5];
    void* m20;
    void* m24;
    void Init();
    void Destroy();
};
void Cleanup(void*);
void LoadStream::Destroy() {
    vt = ((hulk_intptr)DAT_0042ae9c);
    Init();
    if (mObj)
        mObj->Release();
    if (m20)
        Cleanup(m20);
    if (m24)
        Cleanup(m24);
    vt = ((hulk_intptr)DAT_003f6098);
}
