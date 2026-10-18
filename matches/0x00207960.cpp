// FUN_00207960 @ 0x00207960
// FUN_00207960: (re)start a playing object from the table at +0x578
unsigned int __cdecl FUN_00267f80();

struct Playing_207960 {
    void FUN_00263e90();
};

union Flag_207960 {
    unsigned int word;
    char on;
};

class Player_207960 {
public:
    char pad000[0x578];
    int table[3];
    int selected;
    char pad588[0xaec - 0x588];
    Playing_207960 *current;
    char padaf0[3];
    char started;
    char padaf4[8];
    unsigned int startTime;

    void FUN_00203e30(Playing_207960 *p);
    void FUN_00207410();
    Playing_207960 *FUN_00203e90(int a, Flag_207960 flag, int z0, int z1, int entry, int first, int seven);
    void FUN_00207960(int a, int index, Flag_207960 flag);
};

void Player_207960::FUN_00207960(int a, int index, Flag_207960 flag)
{
    if (!flag.on)
        startTime = FUN_00267f80();
    if (current) {
        FUN_00203e30(current);
        FUN_00207410();
    }
    Playing_207960 *p = FUN_00203e90(a, flag, 0, 0, table[index], table[0], 7);
    current = p;
    if (flag.on) {
        selected = index;
        started = 1;
        startTime = 0;
    } else {
        p->FUN_00263e90();
        current = 0;
        startTime = 0;
    }
}
