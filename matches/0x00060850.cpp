#include "compat/ptr.h"
#include "gen/global.h"

class Obj_60850 {
  public:
    int run(void*, int, int);
};
struct Thing_60850 {
    char pad[0x104];
    int value;
};
extern void* Alloc(int);
extern Thing_60850* GetThing(int);

hulk_intptr CGrappleEffectTrack::vfunc_10(hulk_intptr a, hulk_intptr b, hulk_intptr c) {
    void* p = Alloc(0x2c);
    if (p) {
        Thing_60850* q = GetThing(c);
        int value = q->value;
        return ((Obj_60850*)p)->run(this, value, a);
    }
    return 0;
}
