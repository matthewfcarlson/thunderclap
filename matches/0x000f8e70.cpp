#include "gen/global.h"
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
    int Find(int a);
    void Add(NamedValueInt* it);
    NamedValueInt* Create(int a, int b, int c);
};

NamedValueInt* Owner_f8e70::Create(int a, int b, int c) {
    if (Find(a))
        return 0;
    NamedValueInt* r = 0;
    if (c && mInner->mMgr->Check(c)) {
        NamedValueInt* p = (NamedValueInt*)operator new(0x4c);
        if (p) {
            r = ((NamedValueInt_nv_f8e70*)(p))->Init(mInner, a, b, c);
        } else {
            r = 0;
        }
        Add(r);
    }
    return r;
}
