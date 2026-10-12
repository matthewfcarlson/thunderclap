// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 94/94)
// FUN_000cb870 @ 0x000cb870
class Iface {
public:
    virtual void v0();
    virtual void Release();
};

class Stoppable {
public:
    virtual void v0();
    virtual void Release();
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
    virtual void Stop();
};

struct Sub {
    char data[0x34];
    void FUN_000f7a10(int a, int b);
};

class Owner;

struct Bits {
    void FUN_000d6dd0(void *who);
};

static inline void Drop(Iface *&p)
{
    if (p != 0) {
        p->Release();
        p = 0;
    }
}

class Resources {
public:
    char pad0[0x14];
    Iface *r14;
    Iface *r18;
    char pad1c[0x38];
    Sub sub54;
    Iface *r88;
    Iface *r8c;
    Iface *r90;
    char pad94[0xd0];
    Iface *r164;
    Iface *r168;
    char pad16c[0x2c];
    Iface *r198;
    Iface *r19c;
    char pad1a0[0x4];
    Iface *r1a4;
    Iface *r1a8;
    Iface *r1ac;
    Iface *r1b0;
    Iface *r1b4;
    Iface *r1b8;
    Iface *a1bc[3];
    Iface *a1c8[3];
    Iface *a1d4[3];
    Iface *r1e0;
    Iface *r1e4;
    Iface *r1e8;
    int z1ec[3];
    Iface *r1f8;
    Iface *a1fc[6];
    char pad214[0x4];
    Stoppable *r218;
    Iface *r21c;
    char pad220[0x14];
    Iface *r234;
    char pad238[0xc];
    Iface *r244;
    Iface *r248;
    char pad24c[0x4];
    Iface *r250;
    Iface *r254;
    Iface *r258;
    Iface *r25c;
    Iface *r260;
    char flags264[8][0x40];
    Iface *r464;
    Iface *r468;
    Iface *r46c;
    char pad470[0x30];
    Iface *r4a0;
    Iface *r4a4;
    Iface *r4a8;
    Iface *r4ac;
    Iface *r4b0;
    Iface *r4b4;
    char pad4b8[0x50];
    Iface *r508;

    void FUN_000cb870(Bits *bits);
};

void Resources::FUN_000cb870(Bits *bits)
{
    sub54.FUN_000f7a10(-1, 0);
    Drop(r14);
    Drop(r18);
    Drop(r88);
    Drop(r8c);
    Drop(r90);
    Drop(r164);
    Drop(r168);
    Drop(r198);
    Drop(r19c);
    Drop(r1a4);
    Drop(r1a8);
    Drop(r1ac);
    Drop(r1b0);
    Drop(r1b4);
    Drop(r1b8);
    for (int i = 0; i < 3; i++) {
        Drop(a1bc[i]);
        Drop(a1c8[i]);
        Drop(a1d4[i]);
        z1ec[i] = 0;
    }
    Drop(r1e0);
    Drop(r1e4);
    Drop(r1e8);
    Drop(r1f8);
    for (int i = 0; i < 6; i++) {
        Drop(a1fc[i]);
    }
    if (r218 != 0) {
        r218->Stop();
    }
    if (r218 != 0) {
        r218->Release();
        r218 = 0;
    }
    Drop(r21c);
    Drop(r234);
    Drop(r244);
    Drop(r248);
    Drop(r250);
    Drop(r254);
    Drop(r258);
    Drop(r25c);
    Drop(r260);
    for (int i = 0; i < 8; i++) {
        flags264[i][0] = 0;
    }
    Drop(r464);
    Drop(r468);
    Drop(r46c);
    Drop(r4a0);
    Drop(r4a4);
    Drop(r4a8);
    Drop(r4ac);
    Drop(r4b0);
    Drop(r4b4);
    Drop(r508);
    bits->FUN_000d6dd0(this);
}
