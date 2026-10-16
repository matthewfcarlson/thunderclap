// STATUS: equivalent (tools/equiv.py level 3: 566 inputs, branch coverage 29/30, incomplete)
// FUN_000ca3a0 @ 0x000ca3a0
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"
#include "decls/data/game/global.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
extern "C" double sin(double);

namespace pure3d { class DrawableHierarchy; class Geometry; }
namespace content { namespace LoadInventory { template<class T> struct DynamicCaster { virtual void cast(); }; } }

struct V3_ca3a0 {
    float x, y, z;
};

struct NameHolder_ca3a0 {
    char pad[8];
    void FUN_0027b040(const char *name);
};

namespace pure3d {
class __declspec(novtable) Entity {
public:
    virtual void v0();
    char pad04[4];
    NameHolder_ca3a0 nameHolder;
    void FUN_0027b070();
    Entity() { FUN_0027b070(); }
};
}

struct Id64_ca3a0 {
    unsigned int lo;
    unsigned int hi;
    void FUN_0027af00();
};

struct Obj_ca3a0 {
    virtual void init();
    virtual void release();
};

struct Inner_ca3a0 {
    virtual void a0(); virtual void a1(); virtual void a2(); virtual void a3(); virtual void a4();
    virtual void set(unsigned int, unsigned int);
    virtual void enable(unsigned int, unsigned int);
};

struct Resource_ca3a0 : Obj_ca3a0 {
    char pad[12];
    Inner_ca3a0 *inner;           // 0x10
    int f14;
    int f18;
    Resource_ca3a0 *FUN_0028edb0();
};

struct Loaded_ca3a0 : Obj_ca3a0 {
};

struct Inventory_ca3a0 {
    virtual void i0();
    virtual void i1();
    virtual void i2();
    virtual Loaded_ca3a0 *find(void *caster, unsigned __int64 key);
};

struct Level_ca3a0;
struct Window_ca3a0 { Level_ca3a0 *FUN_00086310(); };
struct World {
    char pad0[0x54];
    Window_ca3a0 *window;
};
struct Level_ca3a0 {
    char *FUN_000897e0();
};

struct MapIcon {
    int id;                 // 0x00
    int f04, f08, f0c, f10, f14, f18, f1c, f20;
    char pad24[4];
    Id64_ca3a0 name;              // 0x28
    int f30, f34, f38;
    char b3c, b3d;
    char pad3e[2];
};

struct Marker_ca3a0 {
    int f00, f04, f08, f0c;
    Id64_ca3a0 name;              // 0x10
    int f18, f1c, f20, f24, f28, f2c, f30, f34;
};

void *thunk_FUN_0008d690(unsigned int size);

struct Frame_ca3a0 {
    union {
        char buf[4];
        Loaded_ca3a0 **p;
    } u10;                      // 0x10
    char buf14[4];              // 0x14
    int pad18;
    const char *names[11];      // 0x1c
};

class CHudMap : public pure3d::Entity {
public:
    int f10;
    Resource_ca3a0 *res;          // 0x14
    Loaded_ca3a0 *radar;          // 0x18
    Loaded_ca3a0 *arrow;          // 0x1c
    char b20;
    char pad21[3];
    int f24, f28, f2c, f30;
    char pad34[4];
    int f38, f3c, f40, f44, f48, f4c;
    float wave[28];         // 0x50
    V3_ca3a0 ring[28];            // 0xc0
    int f210;
    float scale;            // 0x214
    int f218;
    int f21c, f220;
    char b224;
    char pad225[3];
    int f228;
    Loaded_ca3a0 *icons[10];      // 0x22c
    int f254;
    MapIcon marks[128];     // 0x258
    Marker_ca3a0 pins[32];        // 0x2258
    char b2958, b2959;
    CHudMap();
    void FUN_000c9bd0(char *name);
    int FUN_000c7d10(int a, const char *name);
};

CHudMap::CHudMap()
{
    f10 = 0;
    f24 = 0;
    f28 = 0;
    f2c = 0;
    f30 = 0;
    f38 = 0;
    f3c = 0;
    f40 = 0;
    f44 = 0;
    f48 = 0;
    f4c = 0;
    f21c = 0;
    f220 = 0;
    b224 = 1;
    f228 = 0x96;
    int i;
    for (i = 0; i < 0x80; i++) {
        MapIcon *e = &marks[i];
        e->id = -1;
        e->f04 = 0;
        e->f08 = 0;
        e->f0c = 0;
        e->f10 = 0;
        e->f14 = 0;
        e->f18 = 0;
        e->f1c = 0;
        e->f20 = 0;
        e->name.FUN_0027af00();
        e->f30 = -1;
        e->f34 = 0;
        e->f38 = 0;
        e->b3c = 0;
        e->b3d = 0;
    }
    for (i = 0; i < 0x20; i++) {
        Marker_ca3a0 *m = &pins[i];
        m->f00 = 0;
        m->f04 = 0;
        m->f08 = 0;
        m->f0c = 0;
        m->name.FUN_0027af00();
        m->f18 = 0;
        m->f1c = 0;
        m->f20 = 0;
        m->f24 = 0;
        m->f28 = 0;
        m->f2c = 0;
        m->f30 = -1;
        m->f34 = -1;
    }
    b2958 = 1;
    b2959 = 0;
    Resource_ca3a0 *r = (Resource_ca3a0 *)thunk_FUN_0008d690(0x20);
    if (r != 0)
        r = r->FUN_0028edb0();
    else
        r = 0;
    res = r;
    r->init();
    res->inner->set(0x584554, 0);
    Resource_ca3a0 *r2 = res;
    r2->inner->enable(0x444d4c42, 1);
    r2->f18 = 1;
    FUN_000c9bd0(DAT_004dd700->window->FUN_00086310()->FUN_000897e0());
    scale = DAT_004de604 * 0.1f;
    for (i = 0; i < 0x1c; i++)
        wave[i] = (float)sin((double)i * 0.224399477f);
    for (i = 0; i < 0x1c; i++) {
        ring[i].x = wave[(i + 7) % 0x1c] * scale;
        ring[i].z = 0;
        ring[i].y = wave[i] * scale;
    }
    Frame_ca3a0 f;
    {
        Inventory_ca3a0 *inv = (*(Inventory_ca3a0**)&DAT_004dd9cc);
        unsigned __int64 k1 = FUN_0027b020("radarBottomLeft");
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *casterA =
            new (f.u10.buf) content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>;
        Loaded_ca3a0 *l = inv->find(casterA, k1);
        radar = l;
        if (l != 0)
            l->init();
    }
    {
        Inventory_ca3a0 *inv = (*(Inventory_ca3a0**)&DAT_004dd9cc);
        unsigned __int64 k2 = FUN_0027b020("north_arrow");
        content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy> *casterB =
            new (f.buf14) content::LoadInventory::DynamicCaster<pure3d::DrawableHierarchy>;
        Loaded_ca3a0 *l = inv->find(casterB, k2);
        arrow = l;
        if (l != 0)
            l->init();
    }
    f.names[0] = "hulkMapIconShape";
    f.names[1] = "enemyMapIconShape";
    f.names[2] = "smashMapIconShape";
    f.names[3] = "grabMapIconShape";
    f.names[4] = "defendMapIconShape";
    f.names[5] = "gotoMapIconShape";
    f.names[6] = "jumpMapIconShape";
    f.names[7] = "sidemissionMapIconShape";
    f.names[8] = "storymissionMapIconShape";
    f.names[9] = "sidemissionnewMapIconShape";
    f.names[10] = 0;
    f.u10.p = icons;
    for (i = 0; i < 10; i++) {
        Inventory_ca3a0 *inv = (*(Inventory_ca3a0**)&DAT_004dd9cc);
        unsigned __int64 k3 = FUN_0027b020(f.names[i]);
        content::LoadInventory::DynamicCaster<pure3d::Geometry> *caster =
            new (f.buf14) content::LoadInventory::DynamicCaster<pure3d::Geometry>;
        Loaded_ca3a0 *l = inv->find(caster, k3);
        *f.u10.p = l;
        if (l != 0)
            l->init();
        f.u10.p++;
    }
    int idx = FUN_000c7d10(0, "hulk");
    if (idx >= 0 && idx < 0x80) {
        MapIcon *e = &marks[idx];
        if (e->id != -1 && e != 0) {
            int k;
            for (k = 0; k < 0x80; k++) {
                if (marks[k].b3c == 1) {
                    marks[k].b3c = 0;
                    break;
                }
            }
            e->b3c = 1;
        }
    }
    b20 = 1;
}
