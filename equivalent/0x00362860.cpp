// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362860 @ 0x00362860
struct Entry_362860 {
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
extern Entry_362860 DAT_004d86e0[5];

void FUN_00362860()
{
    DAT_004d86e0[0].fn = FUN_003337f0;
    DAT_004d86e0[0].a = 0;
    DAT_004d86e0[0].b = 0;
    DAT_004d86e0[0].c = 0;
    DAT_004d86e0[1].fn = FUN_00333800;
    DAT_004d86e0[1].a = 0;
    DAT_004d86e0[1].b = 0;
    DAT_004d86e0[1].c = 0;
    DAT_004d86e0[2].fn = FUN_00333820;
    DAT_004d86e0[2].a = 0;
    DAT_004d86e0[2].b = 0;
    DAT_004d86e0[2].c = 0;
    DAT_004d86e0[3].fn = FUN_00333810;
    DAT_004d86e0[3].a = 0;
    DAT_004d86e0[3].b = 0;
    DAT_004d86e0[3].c = 0;
    DAT_004d86e0[4].fn = 0;
    DAT_004d86e0[4].a = 0;
    DAT_004d86e0[4].b = 0;
    DAT_004d86e0[4].c = -1;
}
