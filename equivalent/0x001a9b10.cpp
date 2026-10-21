// STATUS: equivalent (tools/equiv.py level 3: 19972 inputs, branch coverage 34/34)
// FUN_001a9b10 @ 0x001a9b10
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/address.h"
#include "compat/ptr.h"
inline void *operator new(unsigned int, void *p) throw() { return p; }
void *thunk_FUN_0008d690(unsigned int size);

namespace pure3d { class Animation; }

namespace content {
namespace LoadInventory {
template <class T>
class DynamicCaster {
public:
    virtual void cast(void *p);
};
}
}

namespace pure3d {
class Entity {
public:
    virtual void e0();
    virtual void e1();
    virtual void e2();
    virtual void e3();
};

class DrawableHierarchy {
public:
    virtual void h0();
    virtual void h1();
};

class CompositeDrawable : public Entity {
public:
    virtual Entity *vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void *vf11();
    char pad04[0x4c - 4];
    void *controller;
    void FUN_00298f90(void *ctrl);
};

namespace scenegraph {
class Node {
public:
    virtual void n0();
    virtual void n1();
};

class DrawableNode : public Node {
public:
    DrawableHierarchy *FUN_002960d0();
    void FUN_00296b80(CompositeDrawable *cd);
};
}
}

struct Vec3_1a9b10 {
    float x, y, z;
};

class Controller_1a9b10 {
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
    virtual void v24(pure3d::Animation *anim, unsigned int g, float t);
    char pad[0x150 - 4];
    Controller_1a9b10 *FUN_00287860();
    void FUN_000118c0(void *v);
    void FUN_00284ad0(int a);
};

struct Driver {
    char pad00[0x224];
    char b224;
    char pad225[7];
    float f22c;
    float f230;
    Driver *FUN_00225950(void *rig, pure3d::Animation *anim);
    void FUN_000118c0(void *v);
    void FUN_00225e00(float t, Vec3_1a9b10 v);
    float FUN_00225b30();
    void FUN_00225cf0(float v);
};

struct Context {
    char pad[4];
};

struct LayerSet_1a9b10 {
    char pad00[4];
    LayerSet_1a9b10 *FUN_00222620(void *tag);
    void FUN_000118c0(void *v);
    void *FUN_002226b0();
    void FUN_00222890(Driver *d, float t, int a, float b, float c, float e, float f);
};
LayerSet_1a9b10 *__fastcall FUN_00059a40(Context *ctx);

struct Item_1a9b10 {
    char pad00[0x10];
    Context *ctx;
    void FUN_0003dd00(int a);
    void FUN_00040170();
    void FUN_000354e0(float v);
    void FUN_00035250(Vec3_1a9b10 *v);
};

struct ModeB_1a9b10 {
    Item_1a9b10 *FUN_00024280(unsigned __int64 key);
};

struct World {
    char pad0[0x20];
    ModeB_1a9b10 *modeB;
};

class Inventory_1a9b10 {
public:
    virtual void l0();
    virtual void l1();
    virtual void l2();
    virtual pure3d::Animation *Find(const content::LoadInventory::DynamicCaster<pure3d::Animation> &c, unsigned __int64 id);
    void *FUN_001a9420(const char *name);
};

struct Registry_1a9b10 {
    Inventory_1a9b10 *FUN_00203d60(int index);
};

struct SceneRoot_1a9b10 {
    pure3d::scenegraph::Node *FUN_002961e0(unsigned int lo, unsigned int hi, int a, int b);
};

class Owner_1a9b10 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual float vf7();
    char pad04[0x14 - 4];
    float f14;
    float f18;
    float f1c;
    float f20;
    char pad24[0x2c - 0x24];
    float f2c;
    char pad30[0x54 - 0x30];
    int f54;
};

struct Out_1a9b10 {
    char b0;
    char pad1[2];
    char b3;
    Driver *driver;
    LayerSet_1a9b10 *layers;
    Item_1a9b10 *item;
    pure3d::CompositeDrawable *drawable;
    pure3d::scenegraph::DrawableNode *node;
};

void FUN_0013a790(Driver **slot, Driver *v);
void FUN_00059c50(LayerSet_1a9b10 **slot, LayerSet_1a9b10 *v);
void FUN_00081070(pure3d::CompositeDrawable **slot, pure3d::CompositeDrawable *v);
void FUN_001a5a30(pure3d::scenegraph::DrawableNode **slot, pure3d::scenegraph::DrawableNode *v);
void FUN_00025960(Item_1a9b10 **slot, Item_1a9b10 *v);
float FUN_000964e0();
float __cdecl FUN_00225be0(float a, float b, float c, int d);

class AnimSetup {
public:
    char pad00[0x1c];
    Owner_1a9b10 *owner;
    char pad20[0x20c - 0x20];
    Registry_1a9b10 *registry;
    SceneRoot_1a9b10 *scene;
    unsigned char noOwner;

    void FUN_001a54a0(Vec3_1a9b10 *pos, float *angle);
    bool FUN_001a9b10(Out_1a9b10 *out, const char *animName, const char *name2, bool a, bool isCustom, int c, bool d);
};

bool AnimSetup::FUN_001a9b10(Out_1a9b10 *out, const char *animName, const char *name2, bool a, bool isCustom, int c, bool d)
{
    if (out == 0)
        return false;

    int idx;
    if (noOwner)
        idx = 0;
    else
        idx = owner->f54;
    Inventory_1a9b10 *inv = registry->FUN_00203d60(idx);

    content::LoadInventory::DynamicCaster<pure3d::Animation> caster;
    pure3d::Animation *anim = inv->Find(caster, FUN_002672f0(animName, 0, 0));
    if (anim == 0)
        return false;

    void *rig;
    void *tag;
    LayerSet_1a9b10 *layers;
    Item_1a9b10 *item = 0;

    if (isCustom) {
        rig = inv->FUN_001a9420(name2);
        if (rig == 0)
            return false;

        unsigned __int64 h = FUN_002672f0(name2, 0, 0);
        pure3d::scenegraph::DrawableNode *dn = dynamic_cast<pure3d::scenegraph::DrawableNode *>(
            scene->FUN_002961e0((unsigned int)h, (unsigned int)(h >> 32), 0x10, c));
        if (dn == 0)
            return false;
        pure3d::CompositeDrawable *cd1 = dynamic_cast<pure3d::CompositeDrawable *>(dn->FUN_002960d0());
        if (cd1 == 0)
            return false;
        pure3d::CompositeDrawable *cd = dynamic_cast<pure3d::CompositeDrawable *>(cd1->vf4());
        dn->FUN_00296b80(cd);
        tag = cd->vf11();
        if (cd->controller == 0) {
            void *mem = thunk_FUN_0008d690(0x150);
            Controller_1a9b10 *ctrl = 0;
            if (mem != 0)
                ctrl = ((Controller_1a9b10 *)mem)->FUN_00287860();
            cd->FUN_00298f90(ctrl);
            ctrl->v24(anim, 0, 0.0f);
            ctrl->FUN_000118c0(cd);
            ctrl->v23();
            ctrl->FUN_00284ad0(1);
            out->b3 = 1;
        }
        FUN_00081070(&out->drawable, cd);
        FUN_001a5a30(&out->node, dn);
        void *mem2 = thunk_FUN_0008d690(0x2f0);
        layers = 0;
        if (mem2 != 0)
            layers = ((LayerSet_1a9b10 *)mem2)->FUN_00222620(tag);
        layers->FUN_000118c0(rig);
        FUN_00059c50(&out->layers, layers);
    } else {
        ModeB_1a9b10 *mb = DAT_004dd700->modeB;
        unsigned __int64 key = FUN_002672f0(name2, 0, 0);
        item = mb->FUN_00024280(key);
        if (item == 0)
            return false;
        item->FUN_0003dd00(1);
        if (a)
            item->FUN_00040170();
        FUN_00025960(&out->item, item);
        layers = FUN_00059a40(item->ctx);
        if (layers == 0)
            return false;
        FUN_00059c50(&out->layers, layers);
        rig = layers->FUN_002226b0();
    }

    void *mem3 = thunk_FUN_0008d690(0x240);
    Driver *nd = 0;
    if (mem3 != 0)
        nd = ((Driver *)mem3)->FUN_00225950(rig, anim);
    FUN_0013a790(&out->driver, nd);
    out->driver->FUN_000118c0(anim);
    Driver *drv = out->driver;
    drv->b224 = 0;

    Vec3_1a9b10 v;
    v.z = owner->f20;
    v.y = owner->f1c;
    v.x = owner->f14;
    drv->FUN_00225e00(owner->vf7(), v);
    layers->FUN_00222890(drv, drv->FUN_00225b30(), 1, 1.0f, 0.0f, 0.0f, -1.0f);

    hulk_freg f18 = owner->f18;
    hulk_freg val;
    if (f18 < 0.0f) {
        hulk_freg lo = drv->f22c;
        hulk_freg span = drv->f230 - lo;
        val = FUN_000964e0() * span + lo;
    } else {
        val = FUN_00225be0(f18, drv->f22c, drv->f230, 0);
    }
    drv->FUN_00225cf0(val);

    out->b0 = 1;
    if (!isCustom) {
        Vec3_1a9b10 pos;
        float angle;
        hulk_freg r = owner->f2c;
        FUN_001a54a0(&pos, &angle);
        if (d) {
            r += 3.55338573f;
            pos.x = pos.x + 0.01f;
        }
        item->FUN_000354e0(angle + r);
        item->FUN_00035250(&pos);
    }
    return true;
}
