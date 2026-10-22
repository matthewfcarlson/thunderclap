#include "compat/ptr.h"
extern "C" char DAT_00433424[];
extern "C" char DAT_004334b4[];
void Cleanup(void*);
void __stdcall Release(void*);
class d3dPrimBuffer_327050 {
  public:
    virtual void V0();
    char pad[0x28];
    void* a;
    void* b;
    void BaseDestroy();
    void Destroy();
};
void d3dPrimBuffer_327050::Destroy() {
    *(hulk_intptr*)this = ((hulk_intptr)DAT_004334b4);
    if (a) {
        Cleanup(a);
        Release(a);
    }
    if (b) {
        Cleanup(b);
        Release(b);
    }
    *(hulk_intptr*)this = ((hulk_intptr)DAT_00433424);
    BaseDestroy();
}