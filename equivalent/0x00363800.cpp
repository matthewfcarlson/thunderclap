// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363800 @ 0x00363800
#include "decls/data/platform/xbox/pure3d.h"

void FUN_00332e60();
void FUN_00332e90();
struct Entry { void (*callback)(); int a,b,c; };
void FUN_00363800()
{
    (*(Entry*)&DAT_004d9660).callback = FUN_00332e60;
    (*(Entry*)&DAT_004d9660).a = 0;
    (*(Entry*)&DAT_004d9660).b = 0;
    (*(Entry*)&DAT_004d9660).c = 0;
    (*(Entry*)&DAT_004d9678).callback = FUN_00332e90;
    (*(Entry*)&DAT_004d9678).a = 0;
    (*(Entry*)&DAT_004d9678).b = 0;
    (*(Entry*)&DAT_004d9678).c = 0;
    (*(Entry*)&DAT_004d9690).callback = 0;
    (*(Entry*)&DAT_004d9690).a = 0;
    (*(Entry*)&DAT_004d9690).b = 0;
    (*(Entry*)&DAT_004d9690).c = -1;
}