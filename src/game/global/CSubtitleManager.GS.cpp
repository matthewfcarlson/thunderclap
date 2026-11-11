// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001be0e0..0x001c1200 (kind game, layer game, confidence high), dominant class CSubtitleManager
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f03fc358 {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_f03fc358 {} using namespace fn_f03fc358;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int sprintf(char *dst, const char *fmt, ...);
#endif
namespace fn_f03fc358 {
struct Vec3_1bea80 { float x, y, z; };
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
} // namespace fn_f03fc358
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
namespace fn_f03fc358 {
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
};
class Overlay {
  public:
    float time;
    char _m_pad_4[0x40];
    Owner *owner;
    void FUN_001bea80();
    void FUN_001bec90();
};
struct Vec3_1bec90 { float x, y, z; };
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
};
extern "C" int __cdecl FUN_00266da0(int id);
int __cdecl FUN_000f7120(int handle);
int __cdecl FUN_000964a0(char *buf, int size, const char *fmt, ...);
struct Label_1c0ab0 {
    void FUN_000f7110();
    void FUN_000f7a80(const char *text);
};
struct Printer_1c0ab0 {
};
extern "C" Printer_1c0ab0 *__cdecl FUN_001d4c90();
struct Slot_1c0ab0 {
    int pad0[2];
    int f8;
    char fc;
    char padd[3];
    int f10;
    int f14;
    char pad18[4];
    short f1c;
};
class Menu_1c0ab0 {
public:
    char pad00[0x2c];
    Slot_1c0ab0 *slot;              // 0x2c
    char pad30[4];
    Label_1c0ab0 *labelA;           // 0x34
    Label_1c0ab0 *labelB;           // 0x38
    int hasPrinter;          // 0x3c
    int f40;
    char pad44[4];
    int handle;              // 0x48
    char pad4c[0x54 - 0x4c];
    char flag54;

    void FUN_001c0360(int a, int b);
    void FUN_001c0ab0(const char *name);
};


// 0x001bea80 FUN_001bea80 (524 B): equivalent/0x001bea80.cpp
// sym: ?FUN_001bea80@Overlay@fn_f03fc358@@QAEXXZ @f05fc200663c @wb6c22651e172
// STATUS: equivalent (tools/equiv.py level 3: 7413 inputs, branch coverage 2/2)
// FUN_001bea80 @ 0x001bea80
void Overlay::FUN_001bea80()
{
    Frame_1bea80 f;
    if (owner == 0) {
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
}


// 0x001bec90 FUN_001bec90 (382 B): equivalent/0x001bec90.cpp
// sym: ?FUN_001bec90@Overlay@fn_f03fc358@@QAEXXZ @294aca72c6c0 @w3fa7fcd13052
// STATUS: equivalent (tools/equiv.py level 3: 12891 inputs, branch coverage 2/2)
// FUN_001bec90 @ 0x001bec90
void Overlay::FUN_001bec90()
{
    Frame_1bec90 f;
    if (owner == 0) {
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
}


// 0x001c0ab0 FUN_001c0ab0 (491 B): matches/0x001c0ab0.cpp
// sym: ?FUN_001c0ab0@Menu_1c0ab0@fn_f03fc358@@QAEXPBD@Z
// STATUS: equivalent (tools/equiv.py level 3: 2986 inputs, branch coverage 16/16)
// FUN_001c0ab0 @ 0x001c0ab0
void Menu_1c0ab0::FUN_001c0ab0(const char *name)
{
    char buf[0x40];
    int tok = FUN_00266da0(0xe);
    FUN_001c0360(2, 0);
    int h = FUN_000f7120(handle);
    if (h == 0) {
        FUN_00266da0(tok);
        return;
    }

    if (strcmp(name, "fe") == 0) {
        flag54 = 1;
        if (labelA != 0) {
            labelA->FUN_000f7110();
            FUN_000964a0(buf, 0x40, (*(const char**)&DAT_004c4c64), h);
            labelA->FUN_000f7a80(buf);
        }
        if (hasPrinter != 0) {
            f40 = 0;
            Printer_1c0ab0 *p = FUN_001d4c90();
            int t2 = FUN_00266da0(1);
            ((owners::Object_1d3600 *)p)->FUN_001d3600((*(const char**)&DAT_004c4c70), 0);
            FUN_00266da0(t2);
        }
    } else {
        flag54 = 0;
        if (labelA != 0) {
            labelA->FUN_000f7110();
            FUN_000964a0(buf, 0x40, (*(const char**)&DAT_004c4c5c), h);
            labelA->FUN_000f7a80(buf);
        }
        if (labelB != 0) {
            labelB->FUN_000f7110();
            FUN_000964a0(buf, 0x40, (*(const char**)&DAT_004c4c74), name, name, h);
            labelB->FUN_000f7a80(buf);
        }
        if (hasPrinter != 0) {
            f40 = 0;
            Printer_1c0ab0 *p = FUN_001d4c90();
            int t2 = FUN_00266da0(1);
            ((owners::Object_1d3600 *)p)->FUN_001d3600((*(const char**)&DAT_004c4c60), 0);
            FUN_000964a0(buf, 0x40, (*(const char**)&DAT_004c4c78), name, name);
            ((owners::Object_1d3600 *)p)->FUN_001d3600(buf, 0);
            FUN_00266da0(t2);
        }
    }

    Slot_1c0ab0 *s = slot;
    if (s != 0) {
        s->fc = 0;
        s->f10 = 0;
        s->f8 = 0;
        s->f14 = 0;
        s->f1c = 0;
    }
    FUN_00266da0(tok);
}

} // namespace fn_f03fc358
