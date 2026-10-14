// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00361e50 @ 0x00361e50
// Static initialiser for a global table of 4 handler slots followed by a terminator.
struct Slot_361e50 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct Terminator {
    int a, b, c;
    int last;
};
struct HandlerTable_361e50 {
    Slot_361e50 slot[4];
    Terminator end;
};
extern HandlerTable_361e50 DAT_004d7db0;
void FUN_00333410();
void FUN_00333780();
void FUN_00333830();
void FUN_0032bac0();

void FUN_00361e50()
{
    DAT_004d7db0.slot[0].fn = FUN_00333410;
    DAT_004d7db0.slot[0].a = 0;
    DAT_004d7db0.slot[0].b = 0;
    DAT_004d7db0.slot[0].c = 0;
    DAT_004d7db0.slot[1].fn = FUN_00333780;
    DAT_004d7db0.slot[1].a = 0;
    DAT_004d7db0.slot[1].b = 0;
    DAT_004d7db0.slot[1].c = 0;
    DAT_004d7db0.slot[2].fn = FUN_00333830;
    DAT_004d7db0.slot[2].a = 0;
    DAT_004d7db0.slot[2].b = 0;
    DAT_004d7db0.slot[2].c = 0;
    DAT_004d7db0.slot[3].fn = FUN_0032bac0;
    DAT_004d7db0.slot[3].a = 0;
    DAT_004d7db0.slot[3].b = 0;
    DAT_004d7db0.slot[3].c = 0;
    DAT_004d7db0.end.a = 0;
    DAT_004d7db0.end.b = 0;
    DAT_004d7db0.end.c = 0;
    DAT_004d7db0.end.last = -1;
}
