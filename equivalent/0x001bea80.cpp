// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 2/2)
// FUN_001bea80 @ 0x001bea80
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
extern "C" int sprintf(char *dst, const char *fmt, ...);

extern "C" void __fastcall __security_check_cookie(unsigned int);
extern unsigned int DAT_004d9968;

struct Vec3_1bea80 { float x, y, z; };

struct Owner;

struct Slot_1bea80 {
    float weight;
    int a;
    int b;
    int value;
};

struct Blender_1bea80 {
    Owner *owner;
    int current;
    Slot_1bea80 slots[8];
    int index;
    float scale;
    Blender_1bea80 *FUN_000f7fe0(Owner *o);
    void FUN_000f80e0(const char *text, int font, int flag);
    void FUN_000f78e0();
};

class Renderer_1bea80 {
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
    virtual void v17();
    virtual void v18();
    virtual void v19();
    virtual void v20();
    virtual void v21(int a);
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
    virtual void v24(int a);
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
    virtual bool v59();
};

struct Display_1bea80 {
    Renderer_1bea80 *renderer;
    void FUN_00293d00(Vec3_1bea80 *v);
    void FUN_00293da0(float a, float b, float c);
};


struct Frame_1bea80 {
    Vec3_1bea80 v;
    union {
        bool flag;
        int word;
    } saved;
    Blender_1bea80 b;
    char buf[32];
    unsigned int cookie;
};

class Overlay {
public:
    float time;
    char pad4[0x40];
    Owner *owner;
    void FUN_001bea80();
};

void Overlay::FUN_001bea80()
{
    Frame_1bea80 f;
    f.cookie = DAT_004d9968;
    if (owner == 0) {
        __security_check_cookie(f.cookie);
        return;
    }
    f.b.FUN_000f7fe0(owner);
    int oldMode = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(2);
    int oldA = DAT_0052c2a8->v55();
    DAT_0052c2a8->v54(0);
    f.saved.flag = DAT_0052c2a8->v59();
    DAT_0052c2a8->v58(0);
    f.b.slots[f.b.index].weight = DAT_004c4c1c;
    f.b.slots[f.b.index].b = 3;
    f.b.slots[f.b.index].a = 1;
    f.b.scale = (*(float*)&DAT_004c4c18);
    f.b.slots[f.b.index].value = -1;
    (*(Display_1bea80**)&DAT_0052c2ac)->renderer->v21(0);
    f.v.x = DAT_004e2308;
    f.v.y = DAT_004e230c;
    f.v.z = (*(float*)&DAT_004c4c2c);
    (*(Display_1bea80**)&DAT_0052c2ac)->FUN_00293d00(&f.v);
    (*(Display_1bea80**)&DAT_0052c2ac)->FUN_00293da0(1.0f, -1.0f, 1.0f);
    (*(Display_1bea80**)&DAT_0052c2ac)->renderer->v15(0);
    f.v.x = 0.0f;
    f.v.y = -30.0f;
    f.v.z = 0.0f;
    (*(Display_1bea80**)&DAT_0052c2ac)->FUN_00293d00(&f.v);
    sprintf(f.buf, "time %f", (double)time);
    f.b.FUN_000f80e0(f.buf, (*(int*)&DAT_004e22f0), 0);
    (*(Display_1bea80**)&DAT_0052c2ac)->renderer->v16(0);
    (*(Display_1bea80**)&DAT_0052c2ac)->renderer->v16(0);
    DAT_0052c2a8->v24(oldMode);
    DAT_0052c2a8->v54(oldA);
    DAT_0052c2a8->v58(f.saved.word);
    f.b.FUN_000f78e0();
    __security_check_cookie(f.cookie);
}
