// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003636e0 @ 0x003636e0
// Static initialiser for a global table of 3 handler slots followed by a terminator.
struct Slot {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct Terminator {
    int a, b, c;
    int last;
};
struct HandlerTable {
    Slot slot[3];
    Terminator end;
};
extern HandlerTable DAT_004d9390;
void FUN_00333410();
void FUN_00333780();
void FUN_00333830();

void FUN_003636e0()
{
    DAT_004d9390.slot[0].fn = FUN_00333410;
    DAT_004d9390.slot[0].a = 0;
    DAT_004d9390.slot[0].b = 0;
    DAT_004d9390.slot[0].c = 0;
    DAT_004d9390.slot[1].fn = FUN_00333780;
    DAT_004d9390.slot[1].a = 0;
    DAT_004d9390.slot[1].b = 0;
    DAT_004d9390.slot[1].c = 0;
    DAT_004d9390.slot[2].fn = FUN_00333830;
    DAT_004d9390.slot[2].a = 0;
    DAT_004d9390.slot[2].b = 0;
    DAT_004d9390.slot[2].c = 0;
    DAT_004d9390.end.a = 0;
    DAT_004d9390.end.b = 0;
    DAT_004d9390.end.c = 0;
    DAT_004d9390.end.last = -1;
}
