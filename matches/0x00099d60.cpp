#include "gen/owners.h"
typedef unsigned int U_99d60;
typedef unsigned char B;
struct Obj_99d60 {
    int B(U_99d60* p);
};
extern Obj_99d60* __cdecl FUN_001c3d90(void);
extern "C" int __stdcall FUN_00099d60(U_99d60 a, U_99d60 b, U_99d60 c, U_99d60 d, B flag) {
    U_99d60 x[7];
    x[0] = a;
    x[1] = b;
    x[2] = c;
    x[3] = a;
    x[4] = b;
    x[5] = c;
    x[6] = d;
    Obj_99d60* o = FUN_001c3d90();
    if (flag)
        return ((owners::Thing_1c4050 *)o)->FUN_001c4050((hulk_intptr)(&x[3]));
    return o->B(&x[3]);
}
