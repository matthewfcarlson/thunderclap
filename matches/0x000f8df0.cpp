#include "gen/global.h"
#include "gen/owners.h"
class Mgr_f8df0 {
  public:
    int Check_000dfa60(int x);
};

class Inner_f8df0 {
  public:
    int pad;
    Mgr_f8df0* mMgr;
};

struct NamedValueFloat_nv_f8df0 {
    NamedValueFloat* Init_000f8a90(Inner_f8df0* a, int b, int c, int d);
};

void* operator new(unsigned int n);

class Owner_f8df0 {
  public:
    Inner_f8df0* mInner;
    NamedValueFloat* Create(int a, int b, int c);
};

NamedValueFloat* Owner_f8df0::Create(int a, int b, int c) {
    if (((owners::Table_f8cc0 *)this)->FUN_000f8cc0((const char *)(hulk_uintptr)(int)a))
        return 0;
    NamedValueFloat* r = 0;
    if (c && mInner->mMgr->Check_000dfa60(c)) {
        NamedValueFloat* p = (NamedValueFloat*)operator new(sizeof(NamedValueFloat));
        if (p) {
            r = ((NamedValueFloat_nv_f8df0*)(((NamedValueFloat*)(p))))->Init_000f8a90(mInner, a, b, c);
        } else {
            r = 0;
        }
        ((owners::C_f8c00 *)this)->FUN_000f8c00((hulk_intptr)(NamedValueFloat *)r);
    }
    return r;
}
