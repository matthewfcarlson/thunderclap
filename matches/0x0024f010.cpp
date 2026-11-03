#include "gen/owners.h"
struct Temp_24f010 {
    char pad[12];
    void Init();
    int Value();
    int Finish();
};
extern "C" unsigned char __cdecl FUN_0025bce0(int, Temp_24f010*);
extern int __cdecl Convert(int, int);
unsigned char Target(int a, int* out) {
    Temp_24f010 t;
    t.Init();
    unsigned char r = FUN_0025bce0(a, &t);
    if (out) {
        int x = t.Finish();
        *out = Convert(x, 0);
    }
    ((owners::Str_240060 *)&t)->FUN_00240060();
    return r;
}