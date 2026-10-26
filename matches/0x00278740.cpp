#include "decls/data/platform/xbox/core.h"

#include "compat/ptr.h"
class Obj_278740 {
  public:
    virtual void V0();
    virtual void V1();
};
class GlobalObj_278740 {
  public:
    virtual void V0();
    virtual void V1();
};
class XboxSaveDrive {
  public:
    void Run();
    void Init();
    void Finish();
    char pad0[0xb8];
    Obj_278740* mObj;
    char padbc[4];
    int vbc;
    int vc0;
};
extern int vt0_278740, vt4, vtc, vtbc, vtc0;
extern void Cleanup(int*);
void XboxSaveDrive::Run() {
    *(hulk_intptr*)this = (hulk_intptr)&vt0_278740;
    *(hulk_intptr*)((char*)this + 4) = (hulk_intptr)&vt4;
    *(hulk_intptr*)((char*)this + 0xc) = (hulk_intptr)&vtc;
    *(hulk_intptr*)((char*)this + 0xbc) = (hulk_intptr)&vtbc;
    *(hulk_intptr*)((char*)this + 0xc0) = (hulk_intptr)&vtc0;
    Init();
    if (*(int*)((char*)mObj + 0x10) == 1) {
        (*(GlobalObj_278740**)&DAT_0052c26c)->V1();
        (*(GlobalObj_278740**)&DAT_0052c26c) = 0;
        Cleanup(((int*)&DAT_0052c250));
        return Finish();
    }
    mObj->V1();
    return Finish();
}