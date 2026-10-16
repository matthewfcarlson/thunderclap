// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362b30 @ 0x00362b30
// Static initialiser for a global table of 8 handler slots followed by a terminator.
#include "decls/data/platform/xbox/pure3d.h"

struct Slot_362b30 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct Terminator {
    int a, b, c;
    int last;
};
struct HandlerTable_362b30 {
    Slot_362b30 slot[8];
    Terminator end;
};
void FUN_003333c0();
void FUN_003333e0();
void FUN_003333f0();
void FUN_003337d0();
void FUN_00333770();
void FUN_003333a0();
void FUN_003333b0();
void FUN_00333400();

void FUN_00362b30()
{
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[0].fn = FUN_003333c0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[0].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[0].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[0].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[1].fn = FUN_003333e0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[1].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[1].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[1].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[2].fn = FUN_003333f0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[2].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[2].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[2].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[3].fn = FUN_003337d0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[3].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[3].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[3].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[4].fn = FUN_00333770;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[4].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[4].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[4].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[5].fn = FUN_003333a0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[5].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[5].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[5].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[6].fn = FUN_003333b0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[6].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[6].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[6].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[7].fn = FUN_00333400;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[7].a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[7].b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).slot[7].c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).end.a = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).end.b = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).end.c = 0;
    (*(HandlerTable_362b30*)&DAT_004d8980).end.last = -1;
}
