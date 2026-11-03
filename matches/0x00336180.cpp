#include "compat/ptr.h"
class Owner_336180 {
  public:
    int Get();
    void Advance();
};
extern float __cdecl FUN_003458c1(int);
extern "C" char __stdcall FUN_00336180(float* out, Owner_336180* owner, int c, char inPlace) {
    int v = owner->Get();
    if (!v)
        return 0;
    float* p;
    if (inPlace)
        p = out;
    else
        p = (float*)*(hulk_intptr*)out;
    *p = FUN_003458c1(v);
    owner->Advance();
    v = owner->Get();
    if (!v)
        return 0;
    p[1] = FUN_003458c1(v);
    return 1;
}