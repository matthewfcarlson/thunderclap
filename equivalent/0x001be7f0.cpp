// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 4/4)
// FUN_001be7f0 @ 0x001be7f0
#include "decls/address.h"
struct Vec3_1be7f0 { float x, y, z; };

struct Owner;

struct Slot_1be7f0 {
    float weight;
    int a;
    int b;
    int value;
};

struct Blender_1be7f0 {
    Owner* owner;
    int current;
    Slot_1be7f0 slots[8];
    int index;
    float scale;
    Blender_1be7f0* FUN_000f7fe0(Owner* o);
    void FUN_000f81b0(int v, int font, int flag);
    void FUN_000f87c0(int v, int font, int flag);
    void FUN_000f78e0();
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
    virtual void v30();
    virtual void v31();
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

class Viewport_1be7f0 {
  public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int v6();
    virtual int v7();
};

class Layer_1be7f0 {
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
    Layer_1be7f0* layer;
    void FUN_00293d00(Vec3_1be7f0* v);
    void FUN_00293da0(float x, float y, float z);
};

extern Viewport_1be7f0* DAT_0052c2a4;
extern Canvas* DAT_0052c2ac;
extern float DAT_004c4c18;
extern float DAT_004c4c1c;
extern float DAT_004c4c20;
extern float DAT_004c4c34;
extern float DAT_004c4c38;
extern int DAT_004e22f0;

class Overlay {
  public:
    char pad0[0x18];
    int current;
    int count;
    char pad20[8];
    int* items;
    char pad2c[0x44 - 0x2c];
    Owner* owner;
    char pad48[8];
    int alpha;
    void FUN_001be7f0(int index);
};

void Overlay::FUN_001be7f0(int index)
{
    struct Frame {
        float tmp;
        union {
            char c;
            int i;
        } mode;
        float width;
        Vec3_1be7f0 v;
        Blender_1be7f0 b;
    } f;
    if (owner == 0)
        return;
    int savedMode = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(2);
    int saved55 = DAT_0052c2a8->v55();
    DAT_0052c2a8->v54(0);
    f.mode.c = DAT_0052c2a8->v59();
    DAT_0052c2a8->v58(0);
    f.b.FUN_000f7fe0(owner);
    f.b.slots[f.b.index].weight = DAT_004c4c34 * DAT_004c4c1c;
    f.b.slots[f.b.index].a = 1;
    f.b.slots[f.b.index].b = 3;
    f.b.slots[f.b.index].value = (alpha << 24) | 0xffffff;
    f.b.scale = DAT_004c4c18;
    f.width = (float)DAT_0052c2a4->v7();
    f.tmp = (float)DAT_0052c2a4->v6();
    DAT_0052c2ac->layer->v21(0);
    f.v.x = f.width * 0.5f;
    f.v.z = DAT_004c4c38;
    f.v.y = f.tmp - DAT_004c4c20;
    DAT_0052c2ac->FUN_00293d00(&f.v);
    DAT_0052c2ac->FUN_00293da0(1.0f, -1.0f, 1.0f);
    if (count > 1)
        f.b.FUN_000f81b0(items[current], DAT_004e22f0, 0);
    else
        f.b.FUN_000f87c0(index, DAT_004e22f0, 0);
    DAT_0052c2ac->layer->v16(0);
    DAT_0052c2a8->v24(savedMode);
    DAT_0052c2a8->v54(saved55);
    DAT_0052c2a8->v58(f.mode.i);
    f.b.FUN_000f78e0();
}
