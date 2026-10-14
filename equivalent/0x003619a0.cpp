// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003619a0 @ 0x003619a0
// Static initialiser for a global table of 4 handler slots followed by a terminator.
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
    Slot slot[4];
    Terminator end;
};
extern HandlerTable DAT_004d7a38;
void FUN_003337f0();
void FUN_00333800();
void FUN_00333820();
void FUN_00333810();

void FUN_003619a0()
{
    DAT_004d7a38.slot[0].fn = FUN_003337f0;
    DAT_004d7a38.slot[0].a = 0;
    DAT_004d7a38.slot[0].b = 0;
    DAT_004d7a38.slot[0].c = 0;
    DAT_004d7a38.slot[1].fn = FUN_00333800;
    DAT_004d7a38.slot[1].a = 0;
    DAT_004d7a38.slot[1].b = 0;
    DAT_004d7a38.slot[1].c = 0;
    DAT_004d7a38.slot[2].fn = FUN_00333820;
    DAT_004d7a38.slot[2].a = 0;
    DAT_004d7a38.slot[2].b = 0;
    DAT_004d7a38.slot[2].c = 0;
    DAT_004d7a38.slot[3].fn = FUN_00333810;
    DAT_004d7a38.slot[3].a = 0;
    DAT_004d7a38.slot[3].b = 0;
    DAT_004d7a38.slot[3].c = 0;
    DAT_004d7a38.end.a = 0;
    DAT_004d7a38.end.b = 0;
    DAT_004d7a38.end.c = 0;
    DAT_004d7a38.end.last = -1;
}
