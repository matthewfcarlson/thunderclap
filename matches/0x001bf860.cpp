typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

struct Sub {
    u32 f0;
    u32 f4;
    u32 f8;
    u8 fC;
    u8 pad[3];
    u32 f10;
    u32 f14;
    u8 pad2[4];
    u16 f1c;
};

struct Obj {
    u32 f0;
    u32 f4;
    char pad8[5];
    u8 fD;
    char padE[0x12];
    u32 f20;
    u8 f24;
    char pad25[7];
    Sub* f2C;
    char pad30[0x20];
    u32 f50;
    char pad54;
    u8 f55;

    void Reset(char b);
};

void Obj::Reset(char b) {
    f4 = 0;
    f0 = 0xbf800000;
    fD = 0;
    f24 = 0;
    f55 = 0;
    if (f20 == 2) f2C->fC = 0;
    if (b) {
        f50 = 0;
        Sub* s = f2C;
        s->fC = 0;
        s->f10 = 0;
        s->f8 = 0;
        s->f14 = 0;
        s->f1c = 0;
    }
}
