// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003635b0 @ 0x003635b0
// Static initialiser for a global table of 9 handler slots followed by a terminator.
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
    Slot slot[9];
    Terminator end;
};
extern HandlerTable DAT_004d9240;
void FUN_003333c0();
void FUN_003333e0();
void FUN_003333f0();
void FUN_003337d0();
void FUN_00333770();
void FUN_003333a0();
void FUN_003333b0();
void FUN_00333400();
void FUN_003327e0();

void FUN_003635b0()
{
    DAT_004d9240.slot[0].fn = FUN_003333c0;
    DAT_004d9240.slot[0].a = 0;
    DAT_004d9240.slot[0].b = 0;
    DAT_004d9240.slot[0].c = 0;
    DAT_004d9240.slot[1].fn = FUN_003333e0;
    DAT_004d9240.slot[1].a = 0;
    DAT_004d9240.slot[1].b = 0;
    DAT_004d9240.slot[1].c = 0;
    DAT_004d9240.slot[2].fn = FUN_003333f0;
    DAT_004d9240.slot[2].a = 0;
    DAT_004d9240.slot[2].b = 0;
    DAT_004d9240.slot[2].c = 0;
    DAT_004d9240.slot[3].fn = FUN_003337d0;
    DAT_004d9240.slot[3].a = 0;
    DAT_004d9240.slot[3].b = 0;
    DAT_004d9240.slot[3].c = 0;
    DAT_004d9240.slot[4].fn = FUN_00333770;
    DAT_004d9240.slot[4].a = 0;
    DAT_004d9240.slot[4].b = 0;
    DAT_004d9240.slot[4].c = 0;
    DAT_004d9240.slot[5].fn = FUN_003333a0;
    DAT_004d9240.slot[5].a = 0;
    DAT_004d9240.slot[5].b = 0;
    DAT_004d9240.slot[5].c = 0;
    DAT_004d9240.slot[6].fn = FUN_003333b0;
    DAT_004d9240.slot[6].a = 0;
    DAT_004d9240.slot[6].b = 0;
    DAT_004d9240.slot[6].c = 0;
    DAT_004d9240.slot[7].fn = FUN_00333400;
    DAT_004d9240.slot[7].a = 0;
    DAT_004d9240.slot[7].b = 0;
    DAT_004d9240.slot[7].c = 0;
    DAT_004d9240.slot[8].fn = FUN_003327e0;
    DAT_004d9240.slot[8].a = 0;
    DAT_004d9240.slot[8].b = 0;
    DAT_004d9240.slot[8].c = 0;
    DAT_004d9240.end.a = 0;
    DAT_004d9240.end.b = 0;
    DAT_004d9240.end.c = 0;
    DAT_004d9240.end.last = -1;
}
