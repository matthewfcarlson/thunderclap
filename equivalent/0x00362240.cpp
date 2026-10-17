// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362240 @ 0x00362240
#include "decls/data/platform/xbox/pure3d.h"

void FUN_0032cb40();
void FUN_0032cb70();
struct StateA { void (*callback)(); unsigned int first; unsigned int second; unsigned int third; char pad[8]; };
struct StateB { void (*callback)(); unsigned int first; unsigned int second; unsigned int third; char pad[8]; };
struct StateC { unsigned int first; unsigned int second; unsigned int third; int fourth; };
void FUN_00362240() {
    (*(StateA*)&DAT_004d8150).callback = FUN_0032cb40;
    (*(StateA*)&DAT_004d8150).first = 0;
    (*(StateA*)&DAT_004d8150).second = 0;
    (*(StateA*)&DAT_004d8150).third = 0;
    (*(StateB*)&DAT_004d8168).callback = FUN_0032cb70;
    (*(StateB*)&DAT_004d8168).first = 0;
    (*(StateB*)&DAT_004d8168).second = 0;
    (*(StateB*)&DAT_004d8168).third = 0;
    (*(StateC*)&DAT_004d8180).first = 0;
    (*(StateC*)&DAT_004d8180).second = 0;
    (*(StateC*)&DAT_004d8180).third = 0;
    (*(StateC*)&DAT_004d8180).fourth = -1;
}