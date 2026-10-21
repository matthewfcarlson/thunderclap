#include "compat/ptr.h"
extern "C" double __cdecl sqrt(double);
struct V {
    char pad[0x80];
    float a;
    char pad2[4];
    float b;
};
hulk_freg __fastcall FUN_00035700(V* p) {
    return (float)sqrt((double)p->b * p->b + (double)p->a * p->a);
}