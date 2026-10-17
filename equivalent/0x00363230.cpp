// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363230 @ 0x00363230
#include "decls/data/platform/xbox/pure3d.h"

typedef void (*Callback)();
void FUN_00331b90();
void FUN_00331bc0();
struct StateEntry {
    Callback callback;
    int a;
    int b;
    int c;
    int unused1;
    int unused2;
};
struct StateBlock {
    StateEntry entries[3];
    int endValue;
};
void FUN_00363230() {
    (*(StateBlock*)&DAT_004d9060).entries[0].callback = FUN_00331b90;
    (*(StateBlock*)&DAT_004d9060).entries[0].a = 0;
    (*(StateBlock*)&DAT_004d9060).entries[0].b = 0;
    (*(StateBlock*)&DAT_004d9060).entries[0].c = 0;
    (*(StateBlock*)&DAT_004d9060).entries[1].callback = FUN_00331bc0;
    (*(StateBlock*)&DAT_004d9060).entries[1].a = 0;
    (*(StateBlock*)&DAT_004d9060).entries[1].b = 0;
    (*(StateBlock*)&DAT_004d9060).entries[1].c = 0;
    (*(StateBlock*)&DAT_004d9060).entries[2].callback = 0;
    (*(StateBlock*)&DAT_004d9060).entries[2].a = 0;
    (*(StateBlock*)&DAT_004d9060).entries[2].b = 0;
    (*(StateBlock*)&DAT_004d9060).entries[2].c = -1;
}
