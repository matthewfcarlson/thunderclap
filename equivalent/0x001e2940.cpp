// STATUS: equivalent (tools/equiv.py level 3: 3130 inputs, branch coverage 83/88, incomplete)
// FUN_001e2940 @ 0x001e2940
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "decls/data/game/hulkfight.h"

namespace content {
namespace LoadInventory {
class __declspec(novtable) DynamicCasterBase {
public:
    virtual void cast(void *p) = 0;
};

template <class T>
class DynamicCaster : public DynamicCasterBase {
public:
    virtual void cast(void *p);
};
}
}

class CSPHulkProp;

struct V3_1e2940 {
    float x, y, z;
};

struct Quat_1e2940 {
    float x, y, z, w;
    void FUN_0022b650(struct Mat4_1e2940 *m);
};

struct Mat4_1e2940 {
    float m[12];
    V3_1e2940 trans;
    float w;
    void FUN_0022b980();
};

struct Thing;

struct Factory_1e2940 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual Thing *f3(content::LoadInventory::DynamicCaster<CSPHulkProp> *caster, int a, int b);
};
struct Zone_1e2940 {
    Thing *FUN_00046400(int a, int b);
};
struct Holder44_1e2940 { Factory_1e2940 *FUN_00203d70(); Zone_1e2940 *FUN_00204d70(int idx); };
struct Holder28_1e2940 {
    Holder44_1e2940 *FUN_000862a0();
};
struct Manager_1e2940 { char pad0[0x54]; Holder28_1e2940 *holder; };
extern Manager_1e2940 *DAT_004dd700;

struct Camera { V3_1e2940 *FUN_001c39d0(); };
Camera *FUN_001c3d90();

struct Rec_1e2940;
struct Sub8_1e2940 {
    void FUN_0027b040(const char *name);
    void FUN_0027af70(void *other);
};

struct Ptr9c { char pad[0x38]; float f38; };
struct PtrA0 {
    void *FUN_002fc2d0();
    void FUN_002fc670(int v);
};
struct Link_1e2940 { int FUN_001d5c70(int index); Rec_1e2940 *FUN_001d56f0(int a); };
struct Holder11c { void FUN_001c5080(float a, float b); };

struct Event_1e2940;
struct Sub74_1e2940;

struct Prop_1e2940 {
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
    virtual void v16(int a, int b);
    char pad04[4];
    Sub8_1e2940 sub8;
    char pad09[0x40 - 9];
    int f40;
    char pad44[0x9c - 0x44];
    Ptr9c *p9c;
    PtrA0 *pa0;
    char pada4[0xec - 0xa4];
    Link_1e2940 *link;
    char padf0[0x11c - 0xf0];
    Holder11c *holder;
    char pad120[0x144 - 0x120];
    char b144;
    char pad145[0x14c - 0x145];
    char b14c;
    char b14d;
    char pad14e[0x1c4 - 0x14e];
    int f1c4;
    char pad1c8[0x1d8 - 0x1c8];
    char b1d8;
    void FUN_001d6650(void *a);
    void FUN_001d6aa0(int a);
    void FUN_001d7b80(int a, int b);
    void FUN_001d62b0(int a);
    void FUN_001d6c80(int a);
    int FUN_001d6990();
    void FUN_001d6b60(Mat4_1e2940 m, int flag);
    void FUN_001d63b0(int count);
    Event_1e2940 *FUN_001d72e0();
    void FUN_001d7e70();
    void FUN_001d7590();
    void FUN_001d7510();
    void FUN_001d6cc0(float v);
    void FUN_0027cb40(float f);
    void FUN_0027cd10(void *q);
};

struct Item_1e2940 {
    char pad[0x28];
    int a28;
    int a2c;
    char pad30[0x40 - 0x30];
    int lo;
    int hi;
};
struct Rec_1e2940 {
    char pad[0x44];
    int count;
    char *items;
};

struct Sub20_1e2940 {
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
};
struct Sub74_1e2940 {
    char pad[8];
    char sub8[1];
    char pad9[0x20 - 9];
    Sub20_1e2940 *s20;
    char pad24[0x68 - 0x24];
    char b68;
    char b69;
};
struct Sub70_1e2940 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6(int a);
};
struct Event_1e2940 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    char pad04[0x70 - 4];
    Sub70_1e2940 *p70;
    Sub74_1e2940 *p74;
};

struct Obj1b {
    void FUN_001b4450(Prop_1e2940 *p, int z);
};
Obj1b *FUN_001b6580();

struct Node {
    int value;
    char pad[0xc];
    Node *next;
};

struct SrcPart {
    char pad0[6];
    short s16;
    void FUN_001db820(Quat_1e2940 *out);
};

struct Entry_1e2940 {
    char pad0[8];
    int a8;
    int ac;
    SrcPart src;
    Prop_1e2940 *obj;
    Node *list;
    unsigned short w20;
    short s22;
    short s24;
    char c26;
    char c27;
    const char *FUN_0027b010();
};

struct Slot_1e2940 {
    V3_1e2940 pos;
    char pad0c[4];
    unsigned short flags;
    short entry;
};

unsigned __int64 FUN_0027b020(const char *name) throw();

class Mgr_1e2940 {
public:
    char pad0[0x608];
    Entry_1e2940 entries[2048];
    Slot_1e2940 slots[2048];
    char pad1e608[0x18];
    Prop_1e2940 *objs[128];
    int objCount;
    Prop_1e2940 *FUN_001de4f0(Thing *t, Entry_1e2940 *e, int c, Mat4_1e2940 *m);
    char FUN_001dbec0(int a, int b);
    Prop_1e2940 *F(int idx);
};

Prop_1e2940 *Mgr_1e2940::F(int idx)
{
    Slot_1e2940 *slot = &slots[idx];
    Entry_1e2940 *ent = &entries[slot->entry];
    if (slot->flags & 1)
        return 0;
    slot->flags = slot->flags | 1;
    struct Frame {
        volatile union { char b; int w; } fromLookup;
        int pad[2];
        Quat_1e2940 q;
        Mat4_1e2940 M;
    } fr;
    fr.fromLookup.b = 0;
    Mat4_1e2940 &M = fr.M;
    M.FUN_0022b980();
    ent->src.FUN_001db820(&fr.q);
    fr.q.FUN_0022b650(&M);
    M.trans.x = slot->pos.x;
    M.trans.y = slot->pos.y;
    M.trans.z = slot->pos.z;
    Prop_1e2940 *prop = 0;
    content::LoadInventory::DynamicCaster<CSPHulkProp> caster;
    Thing *found = DAT_004dd700->holder->FUN_000862a0()->FUN_00203d70()->f3(&caster, ent->a8, ent->ac);
    if (!found) {
        Zone_1e2940 *zone = DAT_004dd700->holder->FUN_000862a0()->FUN_00204d70(ent->src.s16);
        if (!zone) {
            slot->flags &= 0xfffe;
            return prop;
        }
        found = zone->FUN_00046400(ent->a8, ent->ac);
        fr.fromLookup.b = 1;
        if (!found) {
            slot->flags &= 0xfffe;
            return prop;
        }
    }
    prop = FUN_001de4f0(found, ent, ent->c26, &M);
    if (!prop) {
        slot->flags &= 0xfffe;
        return prop;
    }
    prop->v0();
    for (Node *n = ent->list; n; n = n->next) {
        if (n->value >= 0) {
            int s = entries[n->value].s22;
            if (!(slots[s].flags & 1))
                F(s);
        }
    }
    if (ent->list)
        prop->FUN_001d6650(ent->list);
    prop->FUN_001d6aa0(1);
    prop->FUN_001d7b80(0, 0);
    prop->FUN_001d62b0(fr.fromLookup.w);
    prop->FUN_001d6c80(slot->entry);
    int kind = prop->FUN_001d6990();
    if (kind == 8 || kind == 7 || kind == 12 || kind == 13)
        prop->f1c4 = DAT_004c6180;
    else
        prop->f1c4 = DAT_004c617c;
    prop->b144 = (slot->flags >> 13) & 1;
    if (!(slot->flags & 2)) {
        Camera *cam = FUN_001c3d90();
        V3_1e2940 *cp = cam->FUN_001c39d0();
        float dx = cp->x - M.trans.x;
        float dy = cp->y - M.trans.y;
        float dz = cp->z - M.trans.z;
        float d = dz * dz + dy * dy + dx * dx;
        if (d < 4900.0f) {
            prop->holder->FUN_001c5080((*(float*)&DAT_00421898), 0.0f);
        } else {
            prop->holder->FUN_001c5080((*(float*)&DAT_00421894), 0.0f);
            prop->holder->FUN_001c5080((*(float*)&DAT_00421898), (*(float*)&DAT_0042189c));
        }
    } else {
        prop->holder->FUN_001c5080((*(float*)&DAT_00421898), 0.0f);
    }
    prop->sub8.FUN_0027b040(ent->FUN_0027b010());
    prop->sub8.FUN_0027af70(ent);
    prop->FUN_001d6b60(M, 0);
    prop->v16(ent->c26, 1);
    prop->b1d8 = 0;
    if (slot->flags & 4)
        prop->FUN_001d63b0(ent->s24);
    else
        prop->FUN_001d63b0(prop->link->FUN_001d5c70(ent->c26));
    prop->b14c = (slot->flags >> 4) & 1;
    prop->b14d = (slot->flags >> 5) & 1;
    unsigned short fl = slot->flags;
    int mode = 0;
    if (fl & 0x40)
        mode = 1;
    if (fl & 0x80)
        mode += 2;
    if (mode == 0) {
        float v = prop->p9c->f38;
        int i;
        for (i = 1; i < 4; i++) {
            if (v <= ((float*)&DAT_00423198)[i])
                break;
        }
        if (i < 4) {
            if (i == 3 || i == 1) {
                fl |= 0x40;
                slot->flags = fl;
            }
            if (i == 3 || i == 2)
                slot->flags |= 0x80;
        }
    }
    if (ent->w20) {
        prop->FUN_0027cb40((float)(int)ent->w20 * 0.01f);
        static unsigned __int64 effectHash = FUN_0027b020("Effect");
        Rec_1e2940 *rec = prop->link->FUN_001d56f0(prop->f40);
        for (int i = 0; i < rec->count; i++) {
            Item_1e2940 *it = (Item_1e2940 *)(rec->items + i * 0x58);
            if ((unsigned __int64)(unsigned int)it->lo == (effectHash & 0xffffffff) &&
                (unsigned int)it->hi == (unsigned int)(effectHash >> 32)) {
                if (FUN_001dbec0(it->a28, it->a2c))
                    prop->FUN_0027cd10(it);
            }
        }
    }
    if (prop->pa0) {
        void *r = prop->pa0->FUN_002fc2d0();
        prop->pa0->FUN_002fc670(2);
        if (prop->FUN_001d72e0()->p70)
            prop->FUN_001d72e0()->p70->v6(1);
        prop->pa0->FUN_002fc670((hulk_intptr)r);
    }
    prop->FUN_001d7e70();
    Event_1e2940 *ev = prop->FUN_001d72e0();
    if (ev && ev->p74) {
        FUN_001b6580()->FUN_001b4450(prop, 0);
        Sub74_1e2940 *e74 = ev->p74;
        ((Sub8_1e2940 *)(e74->sub8 - 0))->FUN_0027af70(ent);
        e74 = ev->p74;
        if (e74->b68 || e74->b69)
            e74->s20->v10();
        ev->v7();
    }
    if (ent->c27) {
        prop->FUN_001d7590();
    } else {
        prop->FUN_001d7510();
        prop->FUN_001d6cc0(0.5f);
    }
    int cnt = objCount;
    if (cnt < 0x80) {
        prop->v0();
        if (objs[cnt])
            objs[cnt]->v1();
        objs[cnt] = prop;
        objCount++;
        prop->v0();
        if (ent->obj)
            ent->obj->v1();
        ent->obj = prop;
    } else {
        slot->flags &= 0xfffe;
    }
    prop->FUN_001d6aa0(0);
    prop->v1();
    return prop;
}
