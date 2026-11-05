#include "compat/ptr.h"
#include "gen/owners.h"
class Obj;
struct Sub {
    void reset(Obj*);
};
class Obj {
    char pad[0x40];
    Sub sub;
    char gap[0xf];
    int state;

  public:
    void dispatch(hulk_intptr a, hulk_intptr b);
};
void Obj::dispatch(hulk_intptr a, hulk_intptr b) {
    switch (state) {
    case 0:
    case 2:
        ((owners::Mat_22c2b0 *)this)->FUN_0022c2b0((float *)(hulk_uintptr)(int)a, (float *)(hulk_uintptr)(int)b);
        break;
    case 1:
        sub.reset(this);
        state = 0;
        ((owners::Mat_22c2b0 *)this)->FUN_0022c2b0((float *)(hulk_uintptr)(int)a, (float *)(hulk_uintptr)(int)b);
        break;
    }
}