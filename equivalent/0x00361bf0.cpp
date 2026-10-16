// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361bf0 @ 0x00361bf0
#include "decls/data/platform/xbox/pure3d.h"

struct Entry_361bf0 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_00333410();
void FUN_00333780();
void FUN_00333830();
void FUN_0032ac50();

void FUN_00361bf0()
{
    ((Entry_361bf0*)&DAT_004d79c0)[0].fn = FUN_00333410;
    ((Entry_361bf0*)&DAT_004d79c0)[0].a = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[0].b = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[0].c = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[1].fn = FUN_00333780;
    ((Entry_361bf0*)&DAT_004d79c0)[1].a = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[1].b = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[1].c = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[2].fn = FUN_00333830;
    ((Entry_361bf0*)&DAT_004d79c0)[2].a = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[2].b = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[2].c = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[3].fn = FUN_0032ac50;
    ((Entry_361bf0*)&DAT_004d79c0)[3].a = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[3].b = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[3].c = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[4].fn = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[4].a = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[4].b = 0;
    ((Entry_361bf0*)&DAT_004d79c0)[4].c = -1;
}
