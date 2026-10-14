// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362570 @ 0x00362570
// Static initialiser for a global table of 7 handler slots followed by a terminator.
struct Slot_362570 {
    void (*fn)();
    int a, b, c;
    int unused[2];
};
struct Terminator {
    int a, b, c;
    int last;
};
struct HandlerTable_362570 {
    Slot_362570 slot[7];
    Terminator end;
};
extern HandlerTable_362570 DAT_004d83d8;
void FUN_0032d2b0();
void FUN_0032d2c0();
void FUN_0032d2d0();
void FUN_0032d2e0();
void FUN_0032d2f0();
void FUN_0032d300();
void FUN_0032d310();

void FUN_00362570()
{
    DAT_004d83d8.slot[0].fn = FUN_0032d2b0;
    DAT_004d83d8.slot[0].a = 0;
    DAT_004d83d8.slot[0].b = 0;
    DAT_004d83d8.slot[0].c = 0;
    DAT_004d83d8.slot[1].fn = FUN_0032d2c0;
    DAT_004d83d8.slot[1].a = 0;
    DAT_004d83d8.slot[1].b = 0;
    DAT_004d83d8.slot[1].c = 0;
    DAT_004d83d8.slot[2].fn = FUN_0032d2d0;
    DAT_004d83d8.slot[2].a = 0;
    DAT_004d83d8.slot[2].b = 0;
    DAT_004d83d8.slot[2].c = 0;
    DAT_004d83d8.slot[3].fn = FUN_0032d2e0;
    DAT_004d83d8.slot[3].a = 0;
    DAT_004d83d8.slot[3].b = 0;
    DAT_004d83d8.slot[3].c = 0;
    DAT_004d83d8.slot[4].fn = FUN_0032d2f0;
    DAT_004d83d8.slot[4].a = 0;
    DAT_004d83d8.slot[4].b = 0;
    DAT_004d83d8.slot[4].c = 0;
    DAT_004d83d8.slot[5].fn = FUN_0032d300;
    DAT_004d83d8.slot[5].a = 0;
    DAT_004d83d8.slot[5].b = 0;
    DAT_004d83d8.slot[5].c = 0;
    DAT_004d83d8.slot[6].fn = FUN_0032d310;
    DAT_004d83d8.slot[6].a = 0;
    DAT_004d83d8.slot[6].b = 0;
    DAT_004d83d8.slot[6].c = 0;
    DAT_004d83d8.end.a = 0;
    DAT_004d83d8.end.b = 0;
    DAT_004d83d8.end.c = 0;
    DAT_004d83d8.end.last = -1;
}
