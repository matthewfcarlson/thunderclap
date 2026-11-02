#include "compat/ptr.h"
class Thing_212de0 {
  public:
    char pad[8];
    hulk_intptr end;
};
int* __fastcall Find(int, Thing_212de0*);
extern "C" void __cdecl FUN_00212de0(Thing_212de0* a, int b) {
    int* p = Find(b, a);
    p += 2;
    while (p < (int*)a->end) {
        int* q = p - 2;
        *q = p[0];
        q[1] = p[1];
        p += 2;
    }
    a->end -= 8;
}
