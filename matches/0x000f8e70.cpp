#include "gen/global.h"
#include "gen/owners.h"
class Mgr_f8e70 {
  public:
    int Check(int x);
};

class Inner_f8e70 {
  public:
    int pad;
    Mgr_f8e70* mMgr;
};

struct NamedValueInt_nv_f8e70 {
    NamedValueInt* Init(Inner_f8e70* a, int b, int c, int d);
};

void* operator new(unsigned int n);

class Owner_f8e70 {
  public:
    Inner_f8e70* mInner;
    NamedValueInt* Create(int a, int b, int c);
};

NamedValueInt* Owner_f8e70::Create(int a, int b, int c) {
    if (((owners::Table_f8cc0 *)this)->FUN_000f8cc0((const char *)(hulk_uintptr)(int)a))
        return 0;
    NamedValueInt* r = 0;
    if (c && mInner->mMgr->Check(c)) {
        NamedValueInt* p = (NamedValueInt*)operator new(0x4c);
        if (p) {
            r = ((NamedValueInt_nv_f8e70*)(((NamedValueInt*)(p))))->Init(mInner, a, b, c);
        } else {
            r = 0;
        }
        ((owners::C_f8c00 *)this)->FUN_000f8c00((hulk_intptr)(NamedValueInt *)r);
    }
    return r;
}
