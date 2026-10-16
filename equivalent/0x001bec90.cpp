// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001bec90 @ 0x001bec90
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"

extern "C" int sprintf(char *dst, const char *fmt, ...);

extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

struct Vec3_1bec90 { float x, y, z; };

struct Owner;

struct Slot_1bec90 {
    float weight;
    int a;
    int b;
    int value;
};

struct Blender_1bec90 {
    Owner *owner;
    int current;
    Slot_1bec90 slots[8];
    int index;
    float scale;
    Blender_1bec90 *FUN_000f7fe0(Owner *o);
    void FUN_000f80e0(const char *text, int font, int flag);
    void FUN_000f78e0();
};

class Renderer_1bec90 {
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
    virtual void v15(int a);
    virtual void v16(int a);
};

struct Display_1bec90 {
    Renderer_1bec90 *renderer;
    void FUN_00293d00(Vec3_1bec90 *v);
    void FUN_00293da0(float a, float b, float c);
};


struct Frame_1bec90 {
    Vec3_1bec90 v;
    Blender_1bec90 b;
    char buf[32];
    unsigned int cookie;
};

class Overlay {
public:
    float time;
    char pad4[0x40];
    Owner *owner;
    void FUN_001bec90();
};

void Overlay::FUN_001bec90()
{
    Frame_1bec90 f;
    f.cookie = DAT_004d9968;
    if (owner == 0) {
        __security_check_cookie(f.cookie);
        return;
    }
    f.b.FUN_000f7fe0(owner);
    f.b.slots[f.b.index].weight = DAT_004c4c1c;
    f.b.slots[f.b.index].a = 1;
    f.b.slots[f.b.index].b = 3;
    f.b.slots[f.b.index].value = -1;
    f.b.scale = (*(float*)&DAT_004c4c18);
    (*(Display_1bec90**)&DAT_0052c2ac)->renderer->v15(0);
    f.v.x = DAT_004e2308;
    f.v.y = DAT_004e230c;
    f.v.z = (*(float*)&DAT_004c4c38);
    (*(Display_1bec90**)&DAT_0052c2ac)->FUN_00293d00(&f.v);
    (*(Display_1bec90**)&DAT_0052c2ac)->FUN_00293da0(1.0f, -1.0f, 1.0f);
    (*(Display_1bec90**)&DAT_0052c2ac)->renderer->v15(0);
    f.v.x = 0.0f;
    f.v.y = -30.0f;
    f.v.z = 0.0f;
    (*(Display_1bec90**)&DAT_0052c2ac)->FUN_00293d00(&f.v);
    sprintf(f.buf, "time %f", (double)time);
    f.b.FUN_000f80e0(f.buf, (*(int*)&DAT_004e22f0), 0);
    (*(Display_1bec90**)&DAT_0052c2ac)->renderer->v16(0);
    (*(Display_1bec90**)&DAT_0052c2ac)->renderer->v16(0);
    f.b.FUN_000f78e0();
    __security_check_cookie(f.cookie);
}
