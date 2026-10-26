#include "decls/data/game/global.h"
// data: gFlag_8ecd0 = DAT_004dd839, gHeight = DAT_0049ca20, gWidth = DAT_0049ca1c

extern "C" void __cdecl Init();

struct Obj_8ecd0 {
    int a, b, c, pad, mode;
    char gap[0x0b];
    char f2;
    char f1;
    char f3;
    int x, y;
};
void __cdecl FUN_0008ecd0(Obj_8ecd0* p) {
    Init();
    if ((*(unsigned char*)&DAT_004dd839)) {
        DAT_0049ca1c = 0x280;
        DAT_0049ca20 = 0x240;
    }
    p->mode = 7;
    *((char*)p + 0x2f) = 1;
    *((char*)p + 0x30) = 1;
    p->a = DAT_0049ca1c;
    p->b = DAT_0049ca20;
    p->c = 0x20;
    *((char*)p + 0x2c) = 0;
    p->x = 0x11;
    p->y = 0;
    *((char*)p + 0x2e) = 1;
}