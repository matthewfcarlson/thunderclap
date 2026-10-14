// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_00362120 @ 0x00362120
struct Entry_362120 {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_00333410();
void FUN_00333780();
void FUN_00333830();
extern Entry_362120 DAT_004d7e68[4];

void FUN_00362120()
{
    DAT_004d7e68[0].fn = FUN_00333410;
    DAT_004d7e68[0].a = 0;
    DAT_004d7e68[0].b = 0;
    DAT_004d7e68[0].c = 0;
    DAT_004d7e68[1].fn = FUN_00333780;
    DAT_004d7e68[1].a = 0;
    DAT_004d7e68[1].b = 0;
    DAT_004d7e68[1].c = 0;
    DAT_004d7e68[2].fn = FUN_00333830;
    DAT_004d7e68[2].a = 0;
    DAT_004d7e68[2].b = 0;
    DAT_004d7e68[2].c = 0;
    DAT_004d7e68[3].fn = 0;
    DAT_004d7e68[3].a = 0;
    DAT_004d7e68[3].b = 0;
    DAT_004d7e68[3].c = -1;
}
