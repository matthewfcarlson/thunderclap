// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_0003f650 @ 0x0003f650
extern "C" int FUN_00267760(char *buf, int size, const char *fmt, int n);
extern "C" void __fastcall __security_check_cookie(unsigned int);
extern "C" unsigned int DAT_004d9968;

class Src {
public:
    char pad0[0x168 - 0x0];
    int s12;
    int s13;
    char pad3[0x37d - 0x170];
    char s11;
    char pad5[0x438 - 0x37e];
    int s0;
    int s1;
    int s2;
    int s3;
    int s4;
    int s5;
    int s17;
    char s18;
    char pad14[0x458 - 0x455];
    int s6;
    int s7;
    int s8;
    int s9;
    int s10;
    char pad20[0x470 - 0x46c];
    int s14;
    char s15;
    char s16;
    float FUN_00045f90(char *name);
};

class Entity {
public:
    char pad0[0x11c - 0x0];
    Src * src;
    char pad2[0x394 - 0x120];
    int d13;
    char pad4[0x1cf8 - 0x398];
    int d0;
    int d2;
    int d1;
    char pad8[0x1d08 - 0x1d04];
    int d17;
    char pad10[0x1d14 - 0x1d0c];
    int d3;
    int d4;
    int d5;
    int d6;
    int d7;
    char pad16[0x1d30 - 0x1d28];
    int d8;
    int d9;
    int d10;
    char pad20[0x1d40 - 0x1d3c];
    char d11;
    char pad22[0x1d48 - 0x1d41];
    int d14;
    char d15;
    char d16;
    char pad26[0x1f50 - 0x1d4e];
    char d18;
    char pad28[0x213c - 0x1f51];
    int d12;
    void FUN_0003ed40(char *name, float value);
    void FUN_0003f650();
};

void Entity::FUN_0003f650()
{
    unsigned int cookie = DAT_004d9968;
    Src *s = src;
    if (s == 0) {
        __security_check_cookie(cookie);
        return;
    }
    d0 = s->s0;
    d1 = s->s1;
    d2 = s->s2;
    d3 = s->s3;
    d4 = s->s4;
    d5 = s->s5;
    d6 = s->s6;
    d7 = s->s7;
    d8 = s->s8;
    d9 = s->s9;
    d10 = s->s10;
    d11 = s->s11;
    d12 = s->s12;
    d13 = s->s13;
    d14 = s->s14;
    d15 = s->s15;
    d16 = s->s16;
    d17 = s->s17;
    d18 = s->s18;
    for (int i = 1; i <= 14; i++) {
        char name[32];
        FUN_00267760(name, 32, "Attack%d", i);
        float v = s->FUN_00045f90(name);
        FUN_0003ed40(name, v);
    }
    __security_check_cookie(cookie);
}
