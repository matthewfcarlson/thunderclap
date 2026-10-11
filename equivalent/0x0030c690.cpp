// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_0030c690 @ 0x0030c690
struct IntVec {
    char data[0x10];
    void FUN_0030c580(const IntVec *other);
};

struct State {
    int word00;              // 0x00 (not copied)
    char byte04;
    char byte05;             // not copied
    short word06;

    int f08;  // 0x8
    int f0c;  // 0xc
    int f10;  // 0x10
    int f14;  // 0x14
    int f18;  // 0x18
    int f1c;  // 0x1c
    IntVec vec20;            // 0x20
    int f30;  // 0x30
    int f34;  // 0x34
    int f38;  // 0x38
    int f3c;  // 0x3c
    int f40;  // 0x40
    int f44;  // 0x44
    char skip48[0x4];
    int f4c;  // 0x4c
    int f50;  // 0x50
    int f54;  // 0x54
    int f58;  // 0x58
    int f5c;  // 0x5c
    int f60;  // 0x60
    char skip64[0x4];
    int f68;  // 0x68
    int f6c;  // 0x6c
    int f70;  // 0x70
    int f74;  // 0x74
    int f78;  // 0x78
    int f7c;  // 0x7c
    int f80;  // 0x80
    int f84;  // 0x84
    int f88;  // 0x88
    int f8c;  // 0x8c
    int f90;  // 0x90
    int f94;  // 0x94
    int f98;  // 0x98
    int f9c;  // 0x9c
    int fa0;  // 0xa0
    int block[16];           // 0xa4
    int fe4;  // 0xe4
    int fe8;  // 0xe8
    char bec;  // 0xec
    char bed;  // 0xed
    char bee;  // 0xee
    char bef;  // 0xef
    int ff0;  // 0xf0
    int ff4;  // 0xf4
    State *FUN_0030c690(const State *other);
};
State *State::FUN_0030c690(const State *other)
{
    byte04 = other->byte04;
    word06 = other->word06;
    f08 = other->f08;
    f0c = other->f0c;
    f10 = other->f10;
    f14 = other->f14;
    f18 = other->f18;
    f1c = other->f1c;
    vec20.FUN_0030c580(&other->vec20);
    f30 = other->f30;
    f34 = other->f34;
    f38 = other->f38;
    f3c = other->f3c;
    f40 = other->f40;
    f44 = other->f44;
    f4c = other->f4c;
    f50 = other->f50;
    f54 = other->f54;
    f58 = other->f58;
    f5c = other->f5c;
    f60 = other->f60;
    f68 = other->f68;
    f6c = other->f6c;
    f70 = other->f70;
    f74 = other->f74;
    f78 = other->f78;
    f7c = other->f7c;
    f80 = other->f80;
    f84 = other->f84;
    f88 = other->f88;
    f8c = other->f8c;
    f90 = other->f90;
    f94 = other->f94;
    f98 = other->f98;
    f9c = other->f9c;
    fa0 = other->fa0;
    for (int i = 0; i < 16; i++)
        block[i] = other->block[i];
    fe4 = other->fe4;
    fe8 = other->fe8;
    bec = other->bec;
    bed = other->bed;
    bee = other->bee;
    bef = other->bef;
    ff0 = other->ff0;
    ff4 = other->ff4;
    return this;
}
