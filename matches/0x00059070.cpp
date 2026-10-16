#include "gen/fight.h"

extern int vft_59070;
class CSmartPropDistanceCondition_59070 {
  public:
    int vptr;
    int pad4[2];
    int one;
    float val;
    char pad14[4];
    class Inner {
      public:
        void init();
    } inner;
    int pad1c;
    int f;
    int g;
    int h;
    void setup(int);
};
void* __cdecl alloc(unsigned int);

template <> void* fight::ConditionFactoryTemplate<CSmartPropDistanceCondition>::vfunc_5() {
    CSmartPropDistanceCondition_59070* p = (CSmartPropDistanceCondition_59070*)alloc(0x30);
    if (p) {
        p->setup(0);
        p->vptr = (int)&vft_59070;
        p->one = 1;
        p->val = 1.0f;
        p->inner.init();
        p->f = 0;
        p->g = 0;
        p->h = 0;
        return (void*)(p);
    }
    return (void*)(0);
}
