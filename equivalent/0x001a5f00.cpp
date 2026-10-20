// STATUS: equivalent (tools/equiv.py level 3: 3045 inputs, branch coverage 40/41, incomplete)
// hulkfight::scenario::EffectAction::vfunc_3 @ 0x001a5f00
#include "decls/address.h"
#include "decls/data/game/hulkfight/scenario.h"
extern "C" void *__cdecl memcpy(void *, const void *, unsigned int);

struct V3_1a5f00 {
    float x, y, z;
};

struct Matrix {
    float m[16];
    void FUN_0022b980();
    void FUN_0022be40(const V3_1a5f00 *t);
    void FUN_0022bc20(float x, float y, float z);
    void FUN_0022ca90(const Matrix *a, const Matrix *b);
    void FUN_0022c120();
};

class RefObj_1a5f00 {
public:
    virtual void AddRef();
    virtual void Release();
};

class Anim_1a5f00 : public RefObj_1a5f00 {
public:
    virtual void v2(); virtual void v3(); virtual void v4(); virtual void v5();
    virtual void v6(); virtual void v7(); virtual void v8(); virtual void v9();
    virtual void v10();
    virtual Anim_1a5f00 *v11();
    Anim_1a5f00 *FUN_002960d0();
};

struct Ctrl_1a5f00 {
    char pad0[8];
    unsigned int keylo;
    unsigned int keyhi;
    char padc[0x120 - 0x10];
    Ctrl_1a5f00 *f120;
    char pad124[0x1a4c - 0x124];
    float f1a4c;
    bool FUN_00035160(Matrix *out);
};

struct List_1a5f00 {
    char pad0[0xc];
    int count;
    Ctrl_1a5f00 *FUN_00024190(int i);
};

struct World {
    char pad0[0x20];
    List_1a5f00 *list;
};

class Cfg_1a5f00 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual float v6();
    char pad04[0xc - 4 + 0x0];
    char padc[0x10 - 0x1c + 0x10];
    float f10;
    char pad14[4];
    unsigned int key18lo;
    unsigned int key18hi;
    char sub20[8];
    int mode1;
    char pad2c[4];
    unsigned int key30lo;
    unsigned int key30hi;
    V3_1a5f00 v38;
    V3_1a5f00 v44;
    int mode2;
    char pad54[4];
    int f58;
    int f5c;
    float f60;
};

struct Mgr_1a5f00 {
    void *FUN_00283a40(void *a, Matrix *m, float t, float f60);
    void *FUN_00283b10(void *a, Ctrl_1a5f00 *c, void *b, Matrix *m, float t, float f60);
    void *FUN_00283be0(void *a, Ctrl_1a5f00 *c, float t, float f60);
};

struct Registry_1a5f00 {
    Anim_1a5f00 *FUN_001a57d0(unsigned int lo, unsigned int hi);
};
Mgr_1a5f00 *FUN_0027f250();

namespace hulkfight {
namespace scenario {
class EffectAction {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual bool vfunc_3(int a, int b);
    virtual void vfunc_4();
    virtual void vfunc_5();
    char pad04[0x18];
    Cfg_1a5f00 *cfg;
    char pad20[4];
    void *result;
    Anim_1a5f00 *anim;
    Matrix cache;
    void FUN_001a5840(Ctrl_1a5f00 *c, unsigned int lo, unsigned int hi, Matrix *out);
};

bool EffectAction::vfunc_3(int a, int b)
{
    union Word {
        Ctrl_1a5f00 *ctrl;
        float t;
        unsigned int u;
        float f;
    };
    struct Frame {
        Word w10;
        Word w14;
        Word w18;
        Word w1c;
        V3_1a5f00 tmp2;
        V3_1a5f00 tmp4;
        V3_1a5f00 tmp1;
        Matrix mb;
        Matrix mc;
        Matrix ma;
    } f;

    Cfg_1a5f00 *c0 = cfg;
    unsigned int lo = c0->key18lo;
    unsigned int hi = c0->key18hi;
    Ctrl_1a5f00 *esi = 0;
    f.w10.ctrl = 0;
    f.w14.u = lo;
    f.w18.u = hi;
    if ((lo | hi) != 0) {
        List_1a5f00 *list = DAT_004dd700->list;
        bool searched = true;
        if (list->count > 0) {
            int i = 0;
            do {
                Ctrl_1a5f00 *item = list->FUN_00024190(i);
                if (item != 0 && item->keylo == f.w14.u && item->keyhi == f.w18.u) {
                    esi = item->f120;
                    f.w10.ctrl = item;
                    if (esi != 0)
                        searched = false;
                    break;
                }
                i++;
            } while (i < list->count);
        }
        if (searched && (*(Registry_1a5f00**)&DAT_004e1760) != 0) {
            Anim_1a5f00 *an = (*(Registry_1a5f00**)&DAT_004e1760)->FUN_001a57d0(f.w14.u, f.w18.u);
            if (an != 0)
                an->AddRef();
            if (anim != 0)
                anim->Release();
            anim = an;
            if (an != 0)
                esi = (Ctrl_1a5f00 *)an->FUN_002960d0()->v11();
        }
    }

    Mgr_1a5f00 *mgr = FUN_0027f250();
    switch (cfg->mode1) {
    case 0: {
        f.ma.FUN_0022b980();
        V3_1a5f00 *t = (V3_1a5f00 *)&f.w14;
        *t = cfg->v38;
        f.ma.FUN_0022be40(t);
        f.ma.FUN_0022bc20(cfg->v44.x, cfg->v44.y, cfg->v44.z);
        break;
    }
    case 1:
        f.mb.FUN_0022b980();
        f.tmp1 = cfg->v38;
        f.mb.FUN_0022be40(&f.tmp1);
        f.mb.FUN_0022bc20(cfg->v44.x, cfg->v44.y, cfg->v44.z);
        FUN_001a5840(esi, 0, 0, &f.mc);
        f.ma.FUN_0022ca90(&f.mb, &f.mc);
        break;
    case 2:
        f.mb.FUN_0022b980();
        f.tmp2 = cfg->v38;
        f.mb.FUN_0022be40(&f.tmp2);
        f.mb.FUN_0022bc20(cfg->v44.x, cfg->v44.y, cfg->v44.z);
        FUN_001a5840(esi, cfg->key30lo, cfg->key30hi, &f.mc);
        f.ma.FUN_0022ca90(&f.mb, &f.mc);
        break;
    case 4:
        f.mc.FUN_0022b980();
        f.tmp4 = cfg->v38;
        f.mc.FUN_0022be40(&f.tmp4);
        f.mc.FUN_0022bc20(cfg->v44.x, cfg->v44.y, cfg->v44.z);
        if (f.w10.ctrl != 0) {
            f.mb.FUN_0022b980();
            f.w10.ctrl->FUN_00035160(&f.mb);
            f.mb.m[13] = f.w10.ctrl->f1a4c;
        } else {
            FUN_001a5840(esi, 0, 0, &f.mb);
        }
        f.ma.FUN_0022ca90(&f.mc, &f.mb);
        break;
    default:
        break;
    }

    Cfg_1a5f00 *c1 = cfg;
    f.w10.t = c1->f10;
    f.w10.t = f.w10.t - c1->v6();
    f.w14.f = cfg->f60;
    switch (cfg->mode2) {
    case 0:
        result = mgr->FUN_00283a40(&cfg->sub20, &f.ma, f.w10.t, f.w14.f);
        return true;
    case 1:
        FUN_001a5840(esi, 0, 0, &f.mc);
        f.mc.FUN_0022c120();
        f.mb.FUN_0022ca90(&f.ma, &f.mc);
        if (anim == 0) {
            result = mgr->FUN_00283b10(&cfg->sub20, esi, 0, &f.mb, f.w10.t, f.w14.f);
        } else {
            memcpy(&cache, &f.mb, sizeof(Matrix));
            result = mgr->FUN_00283a40(&cfg->sub20, &f.ma, f.w10.t, f.w14.f);
        }
        return true;
    case 2:
        FUN_001a5840(esi, cfg->f58, cfg->f5c, &f.mc);
        f.mc.FUN_0022c120();
        f.mb.FUN_0022ca90(&f.ma, &f.mc);
        if (anim == 0) {
            result = mgr->FUN_00283b10(&cfg->sub20, esi, &cfg->f58, &f.mb, f.w10.t, f.w14.f);
        } else {
            memcpy(&cache, &f.mb, sizeof(Matrix));
            result = mgr->FUN_00283a40(&cfg->sub20, &f.ma, f.w10.t, f.w14.f);
        }
        return true;
    case 3:
        result = mgr->FUN_00283be0(&cfg->sub20, esi, f.w10.t, f.w14.f);
        return true;
    }
    return true;
}
}
}
