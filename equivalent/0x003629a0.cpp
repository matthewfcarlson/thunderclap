// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003629a0 @ 0x003629a0
#include "decls/data/platform/xbox/pure3d.h"

struct Entry_3629a0 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_0032d9d0();
void FUN_0032da00();
void FUN_0032eb10();

void FUN_003629a0()
{
    ((Entry_3629a0*)&DAT_004d87a0)[0].fn = FUN_0032d9d0;
    ((Entry_3629a0*)&DAT_004d87a0)[0].a = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[0].b = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[0].c = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[1].fn = FUN_0032da00;
    ((Entry_3629a0*)&DAT_004d87a0)[1].a = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[1].b = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[1].c = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[2].fn = FUN_0032eb10;
    ((Entry_3629a0*)&DAT_004d87a0)[2].a = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[2].b = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[2].c = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[3].fn = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[3].a = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[3].b = 0;
    ((Entry_3629a0*)&DAT_004d87a0)[3].c = -1;
}
