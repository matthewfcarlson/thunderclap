#include "compat/ptr.h"
extern "C" char DAT_00417cb8[];
extern "C" void* __cdecl FUN_0008d690(unsigned int);
class IntentionClearTrack {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    int pad;
    int a;
    int b;
    int c;
    void Init();
};
void* __cdecl TrackFactoryTemplate_vfunc_5() {
    IntentionClearTrack* p = (IntentionClearTrack*)FUN_0008d690(0x14);
    if (p) {
        p->Init();
        *(hulk_intptr*)p = ((hulk_intptr)DAT_00417cb8);
        p->b = 0;
        p->c = 0xbf800000;
        p->a = 1;
        return p;
    }
    return 0;
}