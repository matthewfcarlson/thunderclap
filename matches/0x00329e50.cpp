#include "gen/owners.h"
extern unsigned int gDirty;
struct E_329e50 {
    int x;
    int p[3];
    int y;
    char pad[0x80 - 0x14];
};
extern E_329e50 gTab[];


void owners::Obj_329e50::FUN_00329e50(int i, int x, int y, int v) {
    F1(i, x, y);
    if (a[i] != v) {
        a[i] = v;
        gDirty |= 0x800;
        gTab[i].x = v;
    }
    F2(i, x, y);
    if (b[i] != v) {
        b[i] = v;
        gDirty |= 0x800;
        gTab[i].y = v;
    }
}
