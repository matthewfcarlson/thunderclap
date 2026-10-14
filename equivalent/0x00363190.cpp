// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363190 @ 0x00363190
struct Entry {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_00333410();
void FUN_00333780();
void FUN_00333830();
void FUN_00330d30();
extern Entry DAT_004d8cc8[5];

void FUN_00363190()
{
    DAT_004d8cc8[0].fn = FUN_00333410;
    DAT_004d8cc8[0].a = 0;
    DAT_004d8cc8[0].b = 0;
    DAT_004d8cc8[0].c = 0;
    DAT_004d8cc8[1].fn = FUN_00333780;
    DAT_004d8cc8[1].a = 0;
    DAT_004d8cc8[1].b = 0;
    DAT_004d8cc8[1].c = 0;
    DAT_004d8cc8[2].fn = FUN_00333830;
    DAT_004d8cc8[2].a = 0;
    DAT_004d8cc8[2].b = 0;
    DAT_004d8cc8[2].c = 0;
    DAT_004d8cc8[3].fn = FUN_00330d30;
    DAT_004d8cc8[3].a = 0;
    DAT_004d8cc8[3].b = 0;
    DAT_004d8cc8[3].c = 0;
    DAT_004d8cc8[4].fn = 0;
    DAT_004d8cc8[4].a = 0;
    DAT_004d8cc8[4].b = 0;
    DAT_004d8cc8[4].c = -1;
}
