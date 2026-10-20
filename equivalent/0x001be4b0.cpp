// STATUS: equivalent (tools/equiv.py level 3: 3019 inputs, branch coverage 14/14)
// FUN_001be4b0 @ 0x001be4b0
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
struct Vec3_1be4b0 { float x, y, z; };

struct Owner;

struct Slot_1be4b0 {
    float weight;
    int a;
    int b;
    int value;
};

struct Blender_1be4b0 {
    Owner* owner;
    int current;
    Slot_1be4b0 slots[8];
    int index;
    float scale;
    Blender_1be4b0* FUN_000f7fe0(Owner* o);
    void FUN_000f81b0(int v, int font, int flag);
    void FUN_000f87c0(int v, int font, int flag);
    void FUN_000f78e0();
};

struct Poly {
    char pad00[8];
    Vec3_1be4b0* pos;
    char pad0c[4];
    int* color;
    void FUN_0008ef00();
};

class Gfx {
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
    virtual void v24(int mode);
    virtual int v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual Poly* v30(int a, int b, int c, int d, int e);
    virtual void v31(Poly* p);
    virtual void v32();
    virtual void v33();
    virtual void v34();
    virtual void v35();
    virtual void v36();
    virtual void v37();
    virtual void v38();
    virtual void v39();
    virtual void v40();
    virtual void v41();
    virtual void v42();
    virtual void v43();
    virtual void v44();
    virtual void v45();
    virtual void v46();
    virtual void v47();
    virtual void v48();
    virtual void v49();
    virtual void v50();
    virtual void v51();
    virtual void v52();
    virtual void v53();
    virtual void v54(int a);
    virtual int v55();
    virtual void v56();
    virtual void v57();
    virtual void v58(int a);
    virtual char v59();
};
class Viewport_1be4b0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual void v13();
    virtual void v14();
    virtual void v15();
    virtual float v16();
};
class Layer_1be4b0 {
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
    virtual void v16(int a);
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int a);
};

struct Canvas {
    Layer_1be4b0* layer;
    void FUN_00293d00(Vec3_1be4b0* v);
    void FUN_00293da0(float x, float y, float z);
};

struct Panel_1be4b0 {
    char pad00[0x10];
    int f10;
};


class Overlay {
  public:
    char pad0[0x18];
    int current;
    int count;
    char pad20[8];
    int* items;
    char pad2c[0x38 - 0x2c];
    Owner* ref;
    char pad3c[0x44 - 0x3c];
    Owner* owner;
    char pad48[8];
    int alpha;
    char b54;
    char b55;
    char pad56[2];
    Panel_1be4b0* panel;
    void FUN_001be4b0(int index);
};

void Overlay::FUN_001be4b0(int index)
{
    struct Frame {
        float width;
        float tmp;
        Vec3_1be4b0 v;
        int saved55;
        union {
            char c;
            int i;
        } mode;
        int savedMode;
        float rightA;
        char pad_ac[0xc];
        float rightB;
        char pad_a0[8];
        Blender_1be4b0 b;
    } f;
    if (owner == 0)
        return;
    f.b.FUN_000f7fe0(owner);
    char wide;
    if (b54 && owner == ref)
        wide = 1;
    else
        wide = (*(Viewport_1be4b0**)&DAT_0052c2a4)->v16() > 1.5f;
    f.savedMode = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(2);
    f.saved55 = DAT_0052c2a8->v55();
    DAT_0052c2a8->v54(0);
    f.mode.c = DAT_0052c2a8->v59();
    DAT_0052c2a8->v58(0);
    f.width = (float)(*(Viewport_1be4b0**)&DAT_0052c2a4)->v7();
    f.tmp = (float)(*(Viewport_1be4b0**)&DAT_0052c2a4)->v6();
    f.b.slots[f.b.index].weight = DAT_004c4c28 * DAT_004c4c1c;
    f.b.slots[f.b.index].a = 1;
    f.b.slots[f.b.index].b = 3;
    f.b.slots[f.b.index].value = (alpha << 24) | 0xffffff;
    f.b.scale = (*(float*)&DAT_004c4c18);
    (*(Canvas**)&DAT_0052c2ac)->layer->v21(0);
    f.width = f.width * 0.5f;
    f.v.x = f.width;
    if (b55) {
        f.v.z = (*(float*)&DAT_004c4c2c);
        f.v.y = f.tmp - DAT_004c4c24;
    } else {
        f.v.z = (*(float*)&DAT_004c4c2c);
        f.v.y = f.tmp - DAT_004c4c20;
    }
    (*(Canvas**)&DAT_0052c2ac)->FUN_00293d00(&f.v);
    (*(Canvas**)&DAT_0052c2ac)->FUN_00293da0(1.0f, -1.0f, 1.0f);
    if (wide) {
        Poly* p = DAT_0052c2a8->v30(panel->f10, 1, 0x2020, 4, 0);
        float left = f.width * -0.8f;
        float right = f.width * 0.8f;
        Vec3_1be4b0* pv = p->pos;
        pv->y = -4.0f;
        pv->z = 0.0f;
        f.rightA = right;
        f.v.x = left;
        f.rightB = right;
        pv->x = left;
        p->color[0] = 0x7f000000;
        p->FUN_0008ef00();
        pv = p->pos;
        pv->x = f.v.x;
        pv->y = 29.0f;
        pv->z = 0.0f;
        p->color[0] = 0x7f000000;
        p->FUN_0008ef00();
        pv = p->pos;
        pv->x = f.rightA;
        pv->y = -4.0f;
        pv->z = 0.0f;
        p->color[0] = 0x7f000000;
        p->FUN_0008ef00();
        pv = p->pos;
        pv->x = f.rightB;
        pv->y = 29.0f;
        pv->z = 0.0f;
        p->color[0] = 0x7f000000;
        p->FUN_0008ef00();
        DAT_0052c2a8->v31(p);
    }
    if (count > 1)
        f.b.FUN_000f81b0(items[current], (*(int*)&DAT_004e22f0), 0);
    else
        f.b.FUN_000f87c0(index, (*(int*)&DAT_004e22f0), 0);
    (*(Canvas**)&DAT_0052c2ac)->layer->v16(0);
    DAT_0052c2a8->v24(f.savedMode);
    DAT_0052c2a8->v54(f.saved55);
    DAT_0052c2a8->v58(f.mode.i);
    f.b.FUN_000f78e0();
}
