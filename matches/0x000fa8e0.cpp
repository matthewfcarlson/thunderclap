#include "compat/ptr.h"
extern void* CRawScript_vftable;

class CRawScript {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual ~CRawScript();
    virtual void vfunc_3();
    virtual void vfunc_4();
    char pad[12];
    hulk_intptr m_0x10;

    void Destroy();
    CRawScript* vfunc_2(unsigned char param);
};

void __cdecl FreeBuffer(void* p);
void __cdecl DeleteSelf(void* p);

CRawScript* CRawScript::vfunc_2(unsigned char param) {
    *(void**)this = &CRawScript_vftable;
    FreeBuffer((void*)m_0x10);
    Destroy();
    if (param & 1) {
        DeleteSelf(this);
    }
    return this;
}
