// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_002f75d0 @ 0x002f75d0
struct Name_2f75d0 {
    char data[8];
    void FUN_0027af70(Name_2f75d0 *other);
};

struct Block16_2f75d0 {
    int w[16];
};

struct Block4_2f75d0 {
    int w[4];
};

class Obj_2f75d0;

struct Sub_2f75d0 {
    char data[0x64];
    void FUN_002f7530(Sub_2f75d0 *other);
    void FUN_00308a70(Obj_2f75d0 *owner);
};

extern unsigned int DAT_004d2b74;

class Obj_2f75d0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual void v16();
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21();
    virtual void v22();
    virtual void v23();
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual void v30();
    virtual void v31();
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void Reset();
    char pad04[0x2c];
    Name_2f75d0 name;
    int f38;
    int f3c;
    int f40;
    int f44;
    int f48;
    int f4c;
    int f50;
    int f54;
    Block16_2f75d0 blk58;
    int f98;
    int f9c;
    int fa0;
    char b_a4;
    char pada5[0x3];
    int fa8;
    int fac;
    int fb0;
    int fb4;
    int fb8;
    int fbc;
    int fc0;
    int fc4;
    int fc8;
    Block4_2f75d0 blkcc;
    char paddc[0x4];
    int fe0;
    int fe4;
    int fe8;
    int fec;
    int ff0;
    int ff4;
    char padf8[0x4];
    int ffc;
    int f100;
    int f104;
    int f108;
    int f10c;
    int f110;
    char pad114[0x4];
    int f118;
    int f11c;
    int f120;
    int f124;
    int f128;
    int f12c;
    char pad130[0x18];
    char b148;
    char pad149[0x1b];
    int f164;
    Sub_2f75d0 sub;
    int f1cc;
    char b1d0;
    char pad1d1[0x3];
    int f1d4;
    float f1d8;
    int f1dc;
    float f1e0;
    int f1e4;
    int f1e8;
    char pad1ec[0x4];
    union {
        unsigned dw1f0;
        unsigned char b1f0;
    };
    char b1f4;

    void FUN_002fe6f0(Obj_2f75d0 *dst, int arg);
    void FUN_002f75d0(Obj_2f75d0 *dst, int arg);
};

void Obj_2f75d0::FUN_002f75d0(Obj_2f75d0 *dst, int arg)
{
    FUN_002fe6f0(dst, arg);
    dst->name.FUN_0027af70(&name);
    dst->f38 = f38;
    dst->f3c = f3c;
    dst->f40 = f40;
    dst->f44 = f44;
    dst->f4c = f4c;
    dst->f50 = f50;
    dst->f54 = f54;
    dst->f48 = f48;
    dst->blk58 = blk58;
    dst->f98 = f98;
    dst->f9c = f9c;
    dst->fa0 = fa0;
    dst->b_a4 = b_a4;
    dst->fa8 = fa8;
    dst->fac = fac;
    dst->fb0 = fb0;
    dst->fb4 = fb4;
    dst->fb8 = fb8;
    dst->fbc = fbc;
    dst->fc0 = fc0;
    dst->fc4 = fc4;
    dst->fc8 = fc8;
    dst->blkcc = blkcc;
    dst->fe0 = fe0;
    dst->fe4 = fe4;
    dst->fe8 = fe8;
    dst->fec = fec;
    dst->ff0 = ff0;
    dst->ff4 = ff4;
    dst->ffc = ffc;
    dst->f100 = f100;
    dst->f104 = f104;
    dst->f108 = f108;
    dst->f10c = f10c;
    dst->f110 = f110;
    dst->f118 = f118;
    dst->f11c = f11c;
    dst->f120 = f120;
    dst->f124 = f124;
    dst->f128 = f128;
    dst->f12c = f12c;
    dst->b148 = 1;
    dst->sub.FUN_002f7530(&sub);
    dst->sub.FUN_00308a70(dst);
    dst->fc8 = 0;
    dst->fc4 = 0;
    dst->fc0 = 0;
    dst->Reset();
    dst->f1cc = 0;
    dst->b1d0 = b1d0;
    dst->f164 = f164;
    dst->f1e4 = f1e4;
    dst->f1e8 = f1e8;
    f1d4 = 0;
    f1d8 = 1.0f / (float)DAT_004d2b74;
    f1dc = 0;
    f1e0 = 1.0f / (float)DAT_004d2b74;
    char flags = b1f4;
    b1f0 = 0;
    unsigned int bits = dw1f0 | 0xff00;
    flags |= 2;
    b1f4 = flags;
    dw1f0 = bits;
}
