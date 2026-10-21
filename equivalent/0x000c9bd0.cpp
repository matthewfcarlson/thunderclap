// STATUS: equivalent (tools/equiv.py level 3: 20027 inputs, branch coverage 28/28)
// FUN_000c9bd0 @ 0x000c9bd0
// cl-flags: /GS
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/game/global.h"
extern "C" void *memset(void *, int, unsigned int);
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" int strcmp(const char*, const char*);
extern "C" int __cdecl FUN_000964a0(char *buf, unsigned int size, const char *fmt, const char *arg);
void *__cdecl FUN_00263ed0(unsigned int a, unsigned int b);

namespace pure3d { class Texture; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct TexImpl {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual int width();
    virtual int height();
};

struct Loaded_c9bd0 {
    virtual void init();
    virtual void release();
    char pad04[4];
    unsigned int idLo;      // 0x08
    unsigned int idHi;      // 0x0c
    TexImpl *impl;          // 0x10
    void FUN_00263e90();
};

struct Inventory_c9bd0 {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded_c9bd0 *find(void *caster, unsigned __int64 key);
    Inventory_c9bd0 *FUN_00266480(int n);
};

struct Inner_c9bd0 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void set(unsigned int, unsigned int);
};
struct Resource_c9bd0 {
    virtual void init();
    virtual void release();
    char pad[12];
    Inner_c9bd0 *inner;           // 0x10
};

struct Gfx {
virtual void s0(); virtual void s1(); virtual void s2(); virtual void s3(); virtual void s4(); virtual void s5(); virtual void s6(); virtual void s7(); virtual void s8(); virtual void s9(); virtual void s10(); virtual void s11(); virtual void s12(); virtual void s13(); virtual void s14(); virtual void s15(); virtual void s16(); virtual void s17(); virtual void s18(); virtual void s19(); virtual void s20(); virtual void s21(); virtual void s22(); virtual void s23(); virtual void s24(); virtual void s25(); virtual void s26(); virtual void s27(); virtual void s28(); virtual void s29(); virtual void s30(); virtual void s31(); virtual void s32(); virtual void s33(); virtual void s34(); virtual void s35(); virtual void s36(); virtual void s37(); virtual void s38(); virtual void s39(); virtual void s40(); virtual void s41(); virtual void s42(); virtual void s43(); virtual void s44(); virtual void s45(); virtual void s46(); virtual void s47(); virtual void s48(); virtual void s49(); virtual void s50(); virtual void s51(); virtual void s52(); virtual void s53(); virtual void s54(); virtual void s55(); virtual void s56(); virtual void s57(); virtual void s58(); virtual void s59(); virtual void s60(); virtual void s61(); virtual void s62(); virtual void s63(); virtual void s64(); virtual void s65(); virtual void s66(); virtual void s67(); virtual void s68(); virtual void s69(); virtual void s70(); virtual void s71(); virtual void s72(); virtual void s73(); virtual void s74(); virtual void s75(); virtual void s76(); virtual void s77(); virtual void s78(); virtual void s79(); virtual void s80(); virtual void s81(); virtual void s82(); virtual void s83(); virtual void s84(); virtual void s85(); virtual void s86(); virtual void s87(); virtual void s88(); virtual void s89(); virtual void s90(); 
    virtual void v91();
};


struct Entry_c9bd0 {
    const char *name;
    float v[5];
};

struct Frame_c9bd0 {
    int caster;             // 0x00 (vptr of the stack DynamicCaster / fild spill)
    int pad04;
    Entry_c9bd0 t[16];            // 0x08
    char png[0x40];         // 0x188
    char path[0x100];       // 0x1c8
};

class CHudMap {
public:
    char pad0[0x10];
    Loaded_c9bd0 *tex;            // 0x10
    Resource_c9bd0 *res;          // 0x14
    char pad18[0xc];
    float f24, f28, f2c, f30, f34;
    char pad38[8];
    float f40, f44, f48, f4c;
    char pad50[0x210 - 0x50];
    float f210;
    char pad214[4];
    float f218;
    void FUN_000c9550(const char *path, Inventory_c9bd0 *inv, int n);
    void FUN_000c9bd0(char *name);
};

void CHudMap::FUN_000c9bd0(char *name)
{
    Frame_c9bd0 f;
    memset(f.t, 0, sizeof f.t);
    f.pad04 = (int)0xc5064000;
    f.t[0].name = "downtown_night";
    f.t[0].v[0] = -2364.0f;
    f.t[0].v[1] = -342.0f;
    f.t[0].v[2] = -4.0f;
    f.t[0].v[3] = -2148.0f;
    f.t[0].v[4] = 1.2254999876022339f;
    f.t[1].name = "downtown_dusk";
    f.t[1].v[0] = -2364.0f;
    f.t[1].v[1] = -342.0f;
    f.t[1].v[2] = -4.0f;
    f.t[1].v[3] = -2148.0f;
    f.t[1].v[4] = 1.2254999876022339f;
    f.t[2].name = "outskirts_day";
    f.t[2].v[0] = -2600.0f;
    f.t[2].v[1] = 54.0f;
    f.t[2].v[2] = -188.0f;
    f.t[2].v[3] = -3302.0f;
    f.t[2].v[4] = 0.7188000082969666f;
    f.t[3].name = "outskirts_dusk";
    f.t[3].v[0] = -2600.0f;
    f.t[3].v[1] = 54.0f;
    f.t[3].v[2] = -188.0f;
    f.t[3].v[3] = -3302.0f;
    f.t[3].v[4] = 0.7188000082969666f;
    f.t[4].name = "banners_cabin_day";
    f.t[4].v[0] = -2348.0f;
    f.t[4].v[1] = -1612.0f;
    f.t[4].v[2] = -1332.0f;
    f.t[4].v[3] = -2628.0f;
    f.t[4].v[4] = 1.0f;
    f.t[5].name = "church_night";
    f.t[5].v[0] = -2971.0f;
    f.t[5].v[1] = 104.0f;
    f.t[5].v[2] = -2674.0f;
    f.t[5].v[3] = -193.0f;
    f.t[5].v[4] = 1.0f;
    f.t[6].name = "crossroads_night";
    f.t[6].v[0] = -1389.0f;
    f.t[6].v[1] = -579.0f;
    f.t[6].v[2] = -1083.0f;
    f.t[6].v[3] = -906.0f;
    f.t[6].v[4] = 1.0f;
    f.t[7].name = "division_bio_facility_night";
    f.t[7].v[0] = -656.0139770507812f;
    f.t[7].v[1] = -206.01400756835938f;
    f.t[7].v[2] = -279.2929992675781f;
    f.t[7].v[3] = -582.7360229492188f;
    f.t[7].v[4] = 1.0f;
    f.t[8].name = "nuclear_power_plant_night";
    f.t[8].v[0] = -811.8989868164062f;
    f.t[8].v[1] = -206.01400756835938f;
    f.t[8].v[2] = -435.1780090332031f;
    f.t[8].v[3] = -582.7360229492188f;
    f.t[8].v[4] = 1.0f;
    f.t[9].name = "proving_ground_night";
    f.t[9].v[0] = -448.0f;
    f.t[9].v[1] = -131.0f;
    f.t[9].v[2] = -16.0f;
    f.t[9].v[3] = -563.0f;
    f.t[9].v[4] = 1.0f;
    f.t[10].name = "the_dam_night";
    f.t[10].v[0] = -1050.0f;
    f.t[10].v[1] = -206.0f;
    f.t[10].v[2] = -503.0f;
    f.t[10].v[3] = -754.0f;
    f.t[10].v[4] = 1.0f;
    f.t[11].name = "turning_point_night";
    f.t[11].v[0] = -533.0f;
    f.t[11].v[1] = 19.0f;
    f.t[11].v[2] = -90.0f;
    f.t[11].v[3] = -423.0f;
    f.t[11].v[4] = 1.0f;
    f.t[12].name = "vault_interior_night";
    f.t[12].v[0] = -110.0f;
    f.t[12].v[1] = 144.0f;
    f.t[12].v[2] = 178.0f;
    f.t[12].v[3] = -144.0f;
    f.t[12].v[4] = 1.0f;
    f.t[13].name = "desert_tutorial_dusk";
    f.t[13].v[0] = -1412.0f;
    f.t[13].v[1] = -2100.0f;
    f.t[13].v[2] = -604.0f;
    f.t[13].v[3] = -2908.0f;
    f.t[13].v[4] = 1.0f;
    f.t[14].name = "downtown_day";
    f.t[14].v[0] = -2364.0f;
    f.t[14].v[1] = -342.0f;
    f.t[14].v[2] = -4.0f;
    f.t[14].v[3] = -2148.0f;
    f.t[14].v[4] = 1.2254999876022339f;    int i;
    FUN_000964a0(f.png, 0x40, "%s.png", name);
    if (tex != 0) {
        unsigned __int64 k = FUN_0027b020(f.png);
        Loaded_c9bd0 *t = tex;
        if ((unsigned int)k == t->idLo && (unsigned int)(k >> 32) == t->idHi) {
            return;
        }
        DAT_0052c2a8->v91();
        res->inner->set(0x584554, 0);
        tex->FUN_00263e90();
        tex = 0;
    }
    for (i = 0; i < 16; i++) {
        if (strcmp(name, f.t[i].name) == 0) {
            f24 = f.t[i].v[0];
            f28 = f.t[i].v[1];
            f2c = f.t[i].v[2];
            f30 = f.t[i].v[3];
            f34 = f.t[i].v[4];
            break;
        }
    }
    FUN_000964a0(f.path, 0x100, "frontend/art/hud_maps/%s.p3d", name);
    Inventory_c9bd0 *inv = (Inventory_c9bd0 *)FUN_00263ed0(0x14, 1);
    if (inv != 0)
        inv = inv->FUN_00266480(0x400);
    else
        inv = 0;
    inv->i0();
    FUN_000c9550(f.path, inv, 0xe);
    unsigned __int64 key = FUN_0027b020(f.png);
    Loaded_c9bd0 *l = inv->find(new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::Texture>, key);
    if (l != 0)
        l->init();
    if (tex != 0)
        tex->release();
    tex = l;
    res->inner->set(0x584554, l != 0 ? (hulk_uintptr)l->impl : 0);
    inv->i1();
    if (tex != 0) {
        hulk_freg w = (float)tex->impl->width();
        f40 = w / (f2c - f24);
        hulk_freg h = (float)tex->impl->height();
        hulk_freg sy = h / (f30 - f28);
        f44 = sy;
        f48 = -(f40 * f24);
        f4c = -(sy * f28);
    }
    f218 = DAT_0049fbb8;
    f210 = DAT_0049fbc0 * DAT_0049fbb8;
}
