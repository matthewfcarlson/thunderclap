// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003624d0 @ 0x003624d0
// Static initialiser for a global table of 4 handler slots followed by a terminator.
struct Slot_3624d0 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct Terminator {
    int a, b, c;
    int last;
};
struct HandlerTable_3624d0 {
    Slot_3624d0 slot[4];
    Terminator end;
};
extern HandlerTable_3624d0 DAT_004d8330;
void FUN_0032d290();
void FUN_00333770();
void FUN_003333a0();
void FUN_003333b0();

void FUN_003624d0()
{
    DAT_004d8330.slot[0].fn = FUN_0032d290;
    DAT_004d8330.slot[0].a = 0;
    DAT_004d8330.slot[0].b = 0;
    DAT_004d8330.slot[0].c = 0;
    DAT_004d8330.slot[1].fn = FUN_00333770;
    DAT_004d8330.slot[1].a = 0;
    DAT_004d8330.slot[1].b = 0;
    DAT_004d8330.slot[1].c = 0;
    DAT_004d8330.slot[2].fn = FUN_003333a0;
    DAT_004d8330.slot[2].a = 0;
    DAT_004d8330.slot[2].b = 0;
    DAT_004d8330.slot[2].c = 0;
    DAT_004d8330.slot[3].fn = FUN_003333b0;
    DAT_004d8330.slot[3].a = 0;
    DAT_004d8330.slot[3].b = 0;
    DAT_004d8330.slot[3].c = 0;
    DAT_004d8330.end.a = 0;
    DAT_004d8330.end.b = 0;
    DAT_004d8330.end.c = 0;
    DAT_004d8330.end.last = -1;
}
