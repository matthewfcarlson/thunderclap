// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363760 @ 0x00363760
// Static initialiser for a global table of 4 handler slots followed by a terminator.
#include "decls/data/platform/xbox/pure3d.h"

struct Slot_363760 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct Terminator {
    int a, b, c;
    int last;
};
struct HandlerTable_363760 {
    Slot_363760 slot[4];
    Terminator end;
};
void FUN_003337f0();
void FUN_00333800();
void FUN_00333820();
void FUN_00333810();

void FUN_00363760()
{
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[0].fn = FUN_003337f0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[0].a = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[0].b = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[0].c = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[1].fn = FUN_00333800;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[1].a = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[1].b = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[1].c = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[2].fn = FUN_00333820;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[2].a = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[2].b = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[2].c = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[3].fn = FUN_00333810;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[3].a = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[3].b = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).slot[3].c = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).end.a = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).end.b = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).end.c = 0;
    (*(HandlerTable_363760*)&DAT_004d91c8).end.last = -1;
}
