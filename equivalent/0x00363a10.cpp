// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00363a10 @ 0x00363a10
struct Entry_363a10 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_003337f0();
void FUN_00333800();
void FUN_00333820();
void FUN_00333810();
extern Entry_363a10 DAT_004d94f8[5];

void FUN_00363a10()
{
    DAT_004d94f8[0].fn = FUN_003337f0;
    DAT_004d94f8[0].a = 0;
    DAT_004d94f8[0].b = 0;
    DAT_004d94f8[0].c = 0;
    DAT_004d94f8[1].fn = FUN_00333800;
    DAT_004d94f8[1].a = 0;
    DAT_004d94f8[1].b = 0;
    DAT_004d94f8[1].c = 0;
    DAT_004d94f8[2].fn = FUN_00333820;
    DAT_004d94f8[2].a = 0;
    DAT_004d94f8[2].b = 0;
    DAT_004d94f8[2].c = 0;
    DAT_004d94f8[3].fn = FUN_00333810;
    DAT_004d94f8[3].a = 0;
    DAT_004d94f8[3].b = 0;
    DAT_004d94f8[3].c = 0;
    DAT_004d94f8[4].fn = 0;
    DAT_004d94f8[4].a = 0;
    DAT_004d94f8[4].b = 0;
    DAT_004d94f8[4].c = -1;
}
