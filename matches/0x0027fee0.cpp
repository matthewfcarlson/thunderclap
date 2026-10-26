#include "decls/data/engine/pure3d/prop.h"
// data: gValue_27fee0 = DAT_0052c29c

class Ref_27fee0 {
  public:
    virtual void A();
    virtual void Release();
};
class Owner_27fee0 {
  public:
    Ref_27fee0* a;
    char pad[8];
    Ref_27fee0* b;
    Ref_27fee0* c;
    Ref_27fee0* d;
    Ref_27fee0* e;
    void Clear();
};
void Owner_27fee0::Clear() {
    if (a) {
        a->Release();
        a = 0;
    }
    if (b) {
        b->Release();
        b = 0;
    }
    if (c) {
        c->Release();
        c = 0;
    }
    if (d) {
        d->Release();
        d = 0;
    }
    if (e) {
        e->Release();
        e = 0;
    }
    (*(int*)&DAT_0052c29c) = 0;
}