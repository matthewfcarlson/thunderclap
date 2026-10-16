// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362c40 @ 0x00362c40
#include "decls/data/platform/xbox/pure3d.h"

struct Entry_362c40 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_00333410();
void FUN_00333780();
void FUN_00333830();
void FUN_0032eee0();
void FUN_0032eef0();

void FUN_00362c40()
{
    ((Entry_362c40*)&DAT_004d8848)[0].fn = FUN_00333410;
    ((Entry_362c40*)&DAT_004d8848)[0].a = 0;
    ((Entry_362c40*)&DAT_004d8848)[0].b = 0;
    ((Entry_362c40*)&DAT_004d8848)[0].c = 0;
    ((Entry_362c40*)&DAT_004d8848)[1].fn = FUN_00333780;
    ((Entry_362c40*)&DAT_004d8848)[1].a = 0;
    ((Entry_362c40*)&DAT_004d8848)[1].b = 0;
    ((Entry_362c40*)&DAT_004d8848)[1].c = 0;
    ((Entry_362c40*)&DAT_004d8848)[2].fn = FUN_00333830;
    ((Entry_362c40*)&DAT_004d8848)[2].a = 0;
    ((Entry_362c40*)&DAT_004d8848)[2].b = 0;
    ((Entry_362c40*)&DAT_004d8848)[2].c = 0;
    ((Entry_362c40*)&DAT_004d8848)[3].fn = FUN_0032eee0;
    ((Entry_362c40*)&DAT_004d8848)[3].a = 0;
    ((Entry_362c40*)&DAT_004d8848)[3].b = 0;
    ((Entry_362c40*)&DAT_004d8848)[3].c = 0;
    ((Entry_362c40*)&DAT_004d8848)[4].fn = FUN_0032eef0;
    ((Entry_362c40*)&DAT_004d8848)[4].a = 0;
    ((Entry_362c40*)&DAT_004d8848)[4].b = 0;
    ((Entry_362c40*)&DAT_004d8848)[4].c = 0;
}
