// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362900 @ 0x00362900
// Static initialiser for a global table of 4 handler slots followed by a terminator.
#include "decls/data/platform/xbox/pure3d.h"

struct Slot_362900 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct Terminator {
    int a, b, c;
    int last;
};
struct HandlerTable_362900 {
    Slot_362900 slot[4];
    Terminator end;
};
void FUN_00333410();
void FUN_00333780();
void FUN_00333830();
void FUN_0032e090();

void FUN_00362900()
{
    (*(HandlerTable_362900*)&DAT_004d8620).slot[0].fn = FUN_00333410;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[0].a = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[0].b = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[0].c = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[1].fn = FUN_00333780;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[1].a = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[1].b = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[1].c = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[2].fn = FUN_00333830;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[2].a = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[2].b = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[2].c = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[3].fn = FUN_0032e090;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[3].a = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[3].b = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).slot[3].c = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).end.a = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).end.b = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).end.c = 0;
    (*(HandlerTable_362900*)&DAT_004d8620).end.last = -1;
}
