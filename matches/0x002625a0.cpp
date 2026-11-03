// FUN_002625a0 @ 0x002625a0
#include "gen/owners.h"
struct Str_2625a0 {
    char data[12];
    bool FUN_00240310(Str_2625a0* other);
};
extern "C" void * __cdecl FUN_00262400(void *, void *);
bool __cdecl FUN_002625a0(Str_2625a0* first, Str_2625a0* second) {
    Str_2625a0 a;
    Str_2625a0 b;
    ((owners::Thing_23fd20 *)&a)->FUN_0023fd20(0x100);
    ((owners::Thing_23fd20 *)&b)->FUN_0023fd20(0x100);
    bool result = ((Str_2625a0 *)FUN_00262400((Str_2625a0 *)first, (Str_2625a0 *)(&a)))->FUN_00240310(((Str_2625a0 *)FUN_00262400((Str_2625a0 *)second, (Str_2625a0 *)(&b))));
    ((owners::Str_240060 *)&b)->FUN_00240060();
    ((owners::Str_240060 *)&a)->FUN_00240060();
    return result;
}
