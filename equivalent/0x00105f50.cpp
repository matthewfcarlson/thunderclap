// STATUS: equivalent (tools/equiv.py level 3: 91 inputs, branch coverage 14/14)
// FUN_00105f50 @ 0x00105f50
extern float DAT_004a1c80;
extern __int64 DAT_004dc0c0;

struct Stats {
    char pad0[0x380];
    int value;
    __int64 FUN_000443c0();
};

struct Body {
    char pad0[0x11c];
    Stats *stats;
};

class Owner {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual Body *v6();
};

struct Ring {
    void **head;
    void **cur;
    void **base;
    void **end;
};

struct Registry {
    char pad0[0x18];
    Ring ring;
};

struct Manager {
    char pad0[0x1c];
    Registry *registry;
};

extern Manager *DAT_004dd700;

class __declspec(novtable) CCharacterAgent {
public:
    virtual void v0();
    char pad04[0x58 - 4];
    Owner *owner;
    void FUN_000fc760(Owner *o);
    CCharacterAgent(Owner *o) { FUN_000fc760(o); }
};

class CPathGraphAgent : public CCharacterAgent {
public:
    CPathGraphAgent(Owner *o);
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

    char flag5c;
    char pad5d[3];
    int f60, f64, f68, f6c, f70, f74;
    float f78, f7c, f80, f84;
    int f88;
    char pad8c[4];
    int f90, f94, f98;
    char pad9c[4];
    int fa0, fa4, fa8, fac, fb0;
    char padb4[4];
    int fb8, fbc;
    char padc0[4];
    int fc4, fc8, fcc;
    char padd0[4];
    int fd4, fd8, fdc, fe0, fe4, fe8, fec, ff0;
};

CPathGraphAgent::CPathGraphAgent(Owner *o) : CCharacterAgent(o)
{
    f90 = 0;
    f94 = 0;
    f98 = 0;
    fa0 = 0;
    fc4 = 0;
    fc8 = 0;
    fcc = 0;
    fd4 = 0;
    fbc = 0;
    fdc = 0;
    fe0 = 0;
    fe4 = 0;
    fe8 = 0;
    fec = 0;
    ff0 = 0;
    fd8 = 0;
    flag5c = 0;
    f60 = 0;
    f64 = 0;
    f68 = 0;
    f6c = 0;
    f70 = 0;
    f74 = 0;

    Body *body = o->v6();
    if (body->stats)
        fb8 = body->stats->value;
    __int64 id = body->stats->FUN_000443c0();
    float scale;
    if (id == DAT_004dc0c0)
        scale = DAT_004a1c80;
    else
        scale = 1.0f;
    f78 = scale;
    f7c = 0.2f;
    f80 = scale;
    f84 = 0.3f;
    f88 = 0;
    fa4 = 0;
    fa8 = 0;
    fac = 0;
    fb0 = 0;

    Ring *r = &DAT_004dd700->registry->ring;
    if (r->cur < r->end) {
        if (r->cur)
            *r->cur = &flag5c;
        void **next = r->cur + 1;
        r->cur = next;
        if (next == r->end)
            r->cur = r->base;
        if (r->head == r->cur)
            r->cur = r->cur + (r->end - r->base);
    }
}
