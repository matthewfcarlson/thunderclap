// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 94/94)
// FUN_000cb870 @ 0x000cb870
class Iface_cb870 {
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

struct Sub_cb870 {
    char data[0x34];
    void FUN_000f7a10(int a, int b);
};

class Owner;

struct Bits_cb870 {
    void FUN_000d6dd0(void *who);
};

static inline void Drop(Iface_cb870 *&p)
{
    if (p != 0) {
        p->Release();
        p = 0;
    }
}

class Resources_cb870 {
public:
    char pad0[0x14];
    Iface_cb870 *r14;
    Iface_cb870 *r18;
    char pad1c[0x38];
    Sub_cb870 sub54;
    Iface_cb870 *r88;
    Iface_cb870 *r8c;
    Iface_cb870 *r90;
    char pad94[0xd0];
    Iface_cb870 *r164;
    Iface_cb870 *r168;
    char pad16c[0x2c];
    Iface_cb870 *r198;
    Iface_cb870 *r19c;
    char pad1a0[0x4];
    Iface_cb870 *r1a4;
    Iface_cb870 *r1a8;
    Iface_cb870 *r1ac;
    Iface_cb870 *r1b0;
    Iface_cb870 *r1b4;
    Iface_cb870 *r1b8;
    Iface_cb870 *a1bc[3];
    Iface_cb870 *a1c8[3];
    Iface_cb870 *a1d4[3];
    Iface_cb870 *r1e0;
    Iface_cb870 *r1e4;
    Iface_cb870 *r1e8;
    int z1ec[3];
    Iface_cb870 *r1f8;
    Iface_cb870 *a1fc[6];
    char pad214[0x4];
    Stoppable *r218;
    Iface_cb870 *r21c;
    char pad220[0x14];
    Iface_cb870 *r234;
    char pad238[0xc];
    Iface_cb870 *r244;
    Iface_cb870 *r248;
    char pad24c[0x4];
    Iface_cb870 *r250;
    Iface_cb870 *r254;
    Iface_cb870 *r258;
    Iface_cb870 *r25c;
    Iface_cb870 *r260;
    char flags264[8][0x40];
    Iface_cb870 *r464;
    Iface_cb870 *r468;
    Iface_cb870 *r46c;
    char pad470[0x30];
    Iface_cb870 *r4a0;
    Iface_cb870 *r4a4;
    Iface_cb870 *r4a8;
    Iface_cb870 *r4ac;
    Iface_cb870 *r4b0;
    Iface_cb870 *r4b4;
    char pad4b8[0x50];
    Iface_cb870 *r508;

    void FUN_000cb870(Bits_cb870 *bits);
};

void Resources_cb870::FUN_000cb870(Bits_cb870 *bits)
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
