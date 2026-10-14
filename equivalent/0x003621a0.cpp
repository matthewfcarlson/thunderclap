// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003621a0 @ 0x003621a0
struct Entry_3621a0 {
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
extern Entry_3621a0 DAT_004d8198[5];

void FUN_003621a0()
{
    DAT_004d8198[0].fn = FUN_003337f0;
    DAT_004d8198[0].a = 0;
    DAT_004d8198[0].b = 0;
    DAT_004d8198[0].c = 0;
    DAT_004d8198[1].fn = FUN_00333800;
    DAT_004d8198[1].a = 0;
    DAT_004d8198[1].b = 0;
    DAT_004d8198[1].c = 0;
    DAT_004d8198[2].fn = FUN_00333820;
    DAT_004d8198[2].a = 0;
    DAT_004d8198[2].b = 0;
    DAT_004d8198[2].c = 0;
    DAT_004d8198[3].fn = FUN_00333810;
    DAT_004d8198[3].a = 0;
    DAT_004d8198[3].b = 0;
    DAT_004d8198[3].c = 0;
    DAT_004d8198[4].fn = 0;
    DAT_004d8198[4].a = 0;
    DAT_004d8198[4].b = 0;
    DAT_004d8198[4].c = -1;
}
