// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 0/0)
// FUN_003618a0 @ 0x003618a0
struct Entry {
    void (*fn)();
    int a;
    int b;
    int c;
    int pad[2];
};
void FUN_00328580();
void FUN_00328590();
void FUN_003285a0();
void FUN_003285b0();
extern Entry DAT_004d4d08[5];

void FUN_003618a0()
{
    DAT_004d4d08[0].fn = FUN_00328580;
    DAT_004d4d08[0].a = 0;
    DAT_004d4d08[0].b = 0;
    DAT_004d4d08[0].c = 0;
    DAT_004d4d08[1].fn = FUN_00328590;
    DAT_004d4d08[1].a = 0;
    DAT_004d4d08[1].b = 0;
    DAT_004d4d08[1].c = 0;
    DAT_004d4d08[2].fn = FUN_003285a0;
    DAT_004d4d08[2].a = 0;
    DAT_004d4d08[2].b = 0;
    DAT_004d4d08[2].c = 0;
    DAT_004d4d08[3].fn = FUN_003285b0;
    DAT_004d4d08[3].a = 0;
    DAT_004d4d08[3].b = 0;
    DAT_004d4d08[3].c = 0;
    DAT_004d4d08[4].fn = 0;
    DAT_004d4d08[4].a = 0;
    DAT_004d4d08[4].b = 0;
    DAT_004d4d08[4].c = -1;
}
