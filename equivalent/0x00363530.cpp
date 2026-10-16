// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363530 @ 0x00363530
#include "decls/data/platform/xbox/pure3d.h"

struct Entry_363530 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_00332750();
void FUN_003327b0();
void FUN_00332780();

void FUN_00363530()
{
    ((Entry_363530*)&DAT_004d9330)[0].fn = FUN_00332750;
    ((Entry_363530*)&DAT_004d9330)[0].a = 0;
    ((Entry_363530*)&DAT_004d9330)[0].b = 0;
    ((Entry_363530*)&DAT_004d9330)[0].c = 0;
    ((Entry_363530*)&DAT_004d9330)[1].fn = FUN_003327b0;
    ((Entry_363530*)&DAT_004d9330)[1].a = 0;
    ((Entry_363530*)&DAT_004d9330)[1].b = 0;
    ((Entry_363530*)&DAT_004d9330)[1].c = 0;
    ((Entry_363530*)&DAT_004d9330)[2].fn = FUN_00332780;
    ((Entry_363530*)&DAT_004d9330)[2].a = 0;
    ((Entry_363530*)&DAT_004d9330)[2].b = 0;
    ((Entry_363530*)&DAT_004d9330)[2].c = 0;
    ((Entry_363530*)&DAT_004d9330)[3].fn = 0;
    ((Entry_363530*)&DAT_004d9330)[3].a = 0;
    ((Entry_363530*)&DAT_004d9330)[3].b = 0;
    ((Entry_363530*)&DAT_004d9330)[3].c = -1;
}
