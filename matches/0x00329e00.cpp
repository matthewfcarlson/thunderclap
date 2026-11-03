#include "gen/owners.h"
extern int gFlags_329e00;
extern int gCache_329e00[32];
void owners::Obj_329e00::FUN_00329e00(int a, int b, int c, int d) {
    Helper(a, b, c);
    if (values[a] != d) {
        values[a] = d;
        gFlags_329e00 |= 0x800;
        gCache_329e00[a * 32] = d;
    }
}
