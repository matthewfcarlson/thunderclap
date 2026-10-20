#include "gen/global.h"
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
    int Find(int a);
    void Add(NamedValueFloat* it);
    NamedValueFloat* Create(int a, int b, int c);
};

NamedValueFloat* Owner_f8df0::Create(int a, int b, int c) {
    if (Find(a))
        return 0;
    NamedValueFloat* r = 0;
    if (c && mInner->mMgr->Check_000dfa60(c)) {
        NamedValueFloat* p = (NamedValueFloat*)operator new(0x4c);
        if (p) {
            r = ((NamedValueFloat_nv_f8df0*)(p))->Init_000f8a90(mInner, a, b, c);
        } else {
            r = 0;
        }
        Add(r);
    }
    return r;
}
