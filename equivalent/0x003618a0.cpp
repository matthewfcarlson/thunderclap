// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003618a0 @ 0x003618a0
#include "decls/data/platform/xbox/pure3d.h"

struct Entry_3618a0 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_00328580();
void FUN_00328590();
void FUN_003285a0();
void FUN_003285b0();

void FUN_003618a0()
{
    ((Entry_3618a0*)&DAT_004d4d08)[0].fn = FUN_00328580;
    ((Entry_3618a0*)&DAT_004d4d08)[0].a = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[0].b = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[0].c = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[1].fn = FUN_00328590;
    ((Entry_3618a0*)&DAT_004d4d08)[1].a = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[1].b = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[1].c = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[2].fn = FUN_003285a0;
    ((Entry_3618a0*)&DAT_004d4d08)[2].a = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[2].b = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[2].c = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[3].fn = FUN_003285b0;
    ((Entry_3618a0*)&DAT_004d4d08)[3].a = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[3].b = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[3].c = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[4].fn = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[4].a = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[4].b = 0;
    ((Entry_3618a0*)&DAT_004d4d08)[4].c = -1;
}
