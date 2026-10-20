#include "compat/ptr.h"
#include "gen/hulkfight.h"

extern const char kRttiA[];
extern const char kRttiB[];
int CheckFn(int a, int b, const void* c, const void* d, int e);

class Obj2_12b780 {
  public:
    unsigned char Test(void* a, unsigned char b);
};
class Obj_12b780 {
  public:
    Obj_12b780* Get();
    Obj2_12b780* Next();
};

bool hulkfight::ai::ThreatCondition::vfunc_6(void* __p0, void* __p1, void* __p2) { hulk_intptr a = (hulk_intptr)__p0; hulk_intptr c = (hulk_intptr)__p1; hulk_intptr d = (hulk_intptr)__p2;

    if (!CheckFn(c, 0, kRttiA, kRttiB, 0))
        return false;
    Obj_12b780* o = ((Obj_12b780*)c)->Get();
    Obj2_12b780* x = o->Next();
    unsigned char r = x->Test((*(char (*)[8])&this->f_10), this->f_18);
    unsigned char m = this->f_0c;
    return r == m;
}
