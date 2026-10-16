#include "gen/hulkfight.h"

struct Tgt_14e630 {
    char pad[0x4c];
    struct Q {
        char p[0xc];
        int d;
    }* q;
};
class Params_14e630 {
  public:
    virtual void a0();
    virtual void a1();
    virtual void a2();
    virtual Tgt_14e630* Get();
};
extern char typeA_14e630;
extern char typeB_14e630;
extern "C" int __cdecl FUN_00344e74(void*, int, void*, void*, int);

bool hulkfight::motion::CollisionSourceTypeCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { Params_14e630 * p = (Params_14e630 *)__p1;

    if (!FUN_00344e74(p, 0, &typeA_14e630, &typeB_14e630, 0))
        return false;
    Tgt_14e630* t = p->Get();
    if (!t)
        return false;
    if (!t->q)
        return false;
    int d = t->q->d;
    int c = 0;
    switch (this->f_10) {
    case 0:
        c = 1;
        break;
    case 1:
        c = 5;
        break;
    }
    switch (this->f_0c) {
    case 0:
        return c == d;
    case 1:
        return c != d;
    }
    return false;
}
