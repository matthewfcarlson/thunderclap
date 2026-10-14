// STATUS: equivalent (tools/equiv.py level 3: 73 inputs, branch coverage 7/8, incomplete)
// CDriftAction::vfunc_7 @ 0x0001fe60
extern "C" double sqrt(double);

struct V3_1fe60 {
    float x, y, z;
};

struct Player_1fe60 {
    char pad0[0x2064];
    float f2064;
    float f2068;
    float f206c;
    float f2070;
    bool FUN_00035550(V3_1fe60 *out);
    bool FUN_000356c0(V3_1fe60 *out);
    float FUN_000354c0();
    void FUN_000357a0(const V3_1fe60 *v);
};

struct Mgr_1fe60 {
    Player_1fe60 *FUN_00059a30();
};

struct Holder_1fe60 {
    Mgr_1fe60 *FUN_000592a0();
};

struct Cfg_1fe60 {
    char pad0[0x14];
    float c14;
    float c18;
};

void FUN_00224d70(float angle, V3_1fe60 *v);

class CDriftAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual bool vfunc_7(float arg);
    char pad[0x1c - 4];
    Holder_1fe60 *f1c;
    Cfg_1fe60 *f20;
};

bool CDriftAction::vfunc_7(float arg)
{
    struct Frame {
        float dot;
        float s;
        float L;
        V3_1fe60 h;
        V3_1fe60 g;
        V3_1fe60 k;
    } fr;
    Mgr_1fe60 *mgr = f1c->FUN_000592a0();
    Player_1fe60 *pl = mgr->FUN_00059a30();
    fr.s = pl->f2070;
    if (!(fr.s > 0.0f))
        return true;

    fr.g.x = 0.0f;
    fr.g.y = 0.0f;
    fr.g.z = 0.0f;
    pl->FUN_00035550(&fr.g);
    double d = fr.g.y * pl->f2068 + fr.g.z * pl->f206c + fr.g.x * pl->f2064;
    fr.dot = (float)d;
    if (d > 0.0) {
        Cfg_1fe60 *cfg = f20;
        fr.h.x = 0.0f;
        fr.h.y = 0.0f;
        fr.h.z = -((cfg->c14 + (cfg->c18 - cfg->c14) * fr.s) * fr.dot * arg);
        float g1 = pl->FUN_000354c0();
        FUN_00224d70(g1, &fr.h);
        pl->FUN_000357a0(&fr.h);
    } else {
        fr.h.x = 0.0f;
        fr.h.y = 0.0f;
        fr.h.z = 0.0f;
        pl->FUN_000356c0(&fr.h);
        fr.h.y = 0.0f;
        if (!(fr.h.x * fr.g.x + fr.h.z * fr.g.z + fr.g.y * 0.0f > 0.0f))
            return true;
        Cfg_1fe60 *cfg = f20;
        fr.L = (float)sqrt(fr.h.z * fr.h.z + fr.h.x * fr.h.x);
        float A = cfg->c14 + (cfg->c18 - cfg->c14) * fr.s;
        float B = A;
        if (fr.L - A < 0.0f)
            B = fr.L;
        fr.k.x = 0.0f;
        fr.k.y = 0.0f;
        fr.k.z = -(B * fr.dot * arg);
        float g1 = pl->FUN_000354c0();
        FUN_00224d70(g1, &fr.k);
        pl->FUN_000357a0(&fr.k);
    }
    return true;
}
