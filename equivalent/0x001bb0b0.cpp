// STATUS: equivalent (tools/equiv.py level 3: 3138 inputs, branch coverage 44/44)
// FUN_001bb0b0 @ 0x001bb0b0
// cl-flags: /GS
// FUN_001bb0b0 @ 0x001bb0b0: draw an error / status message on the screen
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/core.h"

extern "C" int __cdecl sprintf(char *, const char *, ...);
extern "C" unsigned int __cdecl strlen(const char *);
void *thunk_FUN_0008d690(unsigned int size);
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
int __cdecl FUN_001b8970(unsigned short *s, int n);
void __cdecl FUN_00294c70(const char *src, unsigned short *dst, int n);
const char *__cdecl FUN_001b8b60(const char *text);
void __cdecl FUN_002684c0();

namespace pure3d { class TextureFont; }
namespace content {
namespace LoadInventory {
template <class T>
struct DynamicCaster {
    virtual void v0();
};
}
}

struct Font {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual void f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual float Width(const unsigned short *s);
};

struct Loader_1bb0b0 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual Font *v3(content::LoadInventory::DynamicCaster<pure3d::TextureFont> *caster, unsigned __int64 hash);
};

struct TextObj {
    virtual void AddRef();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void Draw();
    TextObj *FUN_0029b120(Font *font, const unsigned short *s, float f, int n);
    void FUN_0029b330(const unsigned short *s, int n);
    void FUN_0029b380(unsigned int color);
};

class Cam_1bb0b0 {
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

struct Renderer_1bb0b0 {
    Cam_1bb0b0 *cam;
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293d40(float a, float b, float c);
};

class Clock_1bb0b0 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual int Height();
    virtual int Width();
};

class Device_1bb0b0 {
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
    virtual void v12(int a);
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
    virtual void v33(const char *s, int x, int y, unsigned int color);
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
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58(int a);
};

struct Banner {
    void FUN_0028f9a0();
    void FUN_0028faf0(int a);
};

struct Res;
struct Obj1_1bb0b0 {
    unsigned short *FUN_000f7d30(const char *name);
    unsigned short *FUN_000f7220(unsigned short *p);
};
Obj1_1bb0b0 *__fastcall thunk_FUN_000fc1b0(Res *r);

struct Ctl_1bb0b0 {
    void FUN_000afe80();
};

struct Replay_1bb0b0 {
    Res *FUN_00086280();
    Ctl_1bb0b0 *FUN_00086330();
};

struct Globals_1bb0b0 {
    char pad0[0x54];
    Replay_1bb0b0 *replay;
};

extern Globals_1bb0b0 *DAT_004dd700;
extern Device_1bb0b0 *DAT_0052c2a8;

struct Frame_1bb0b0 {
    union {
        float height;              // 0x00
        float x;
    } u0;
    float y;                       // 0x04
    float width;                   // 0x08
    content::LoadInventory::DynamicCaster<pure3d::TextureFont> caster;  // 0x0c
    int saved;                     // 0x10
    char msg[0x100];               // 0x14
    unsigned short text[0x200];    // 0x114
    unsigned short line[0x200];    // 0x514
};

inline void *operator new(unsigned int, void *p) throw() { return p; }

void __cdecl FUN_001bb0b0(const char *code)
{
    Frame_1bb0b0 f;
    if (DAT_004dd700 && DAT_004dd700->replay && DAT_004dd700->replay->FUN_00086330()) {
        DAT_004dd700->replay->FUN_00086330()->FUN_000afe80();
        FUN_002684c0();
    }
    f.width = (float)(*(Clock_1bb0b0**)&DAT_0052c2a4)->Width();
    f.u0.height = (float)(*(Clock_1bb0b0**)&DAT_0052c2a4)->Height();
    f.saved = DAT_0052c2a8->v25();
    (*(Banner**)&DAT_0052c2b4)->FUN_0028f9a0();
    DAT_0052c2a8->v12(-1);
    DAT_0052c2a8->v24(2);

    unsigned short *w = 0;
    if (DAT_004dd700 && DAT_004dd700->replay && DAT_004dd700->replay->FUN_00086280()
        && thunk_FUN_000fc1b0(DAT_004dd700->replay->FUN_00086280())) {
        unsigned short *wn = thunk_FUN_000fc1b0(DAT_004dd700->replay->FUN_00086280())->FUN_000f7d30(code);   // the argument is evaluated before the receiver
        w = thunk_FUN_000fc1b0(DAT_004dd700->replay->FUN_00086280())->FUN_000f7220(wn);
    }
    Loader_1bb0b0 *inv = (*(Loader_1bb0b0**)&DAT_004dd9c8);
    content::LoadInventory::DynamicCaster<pure3d::TextureFont> *caster =
        new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::TextureFont>();
    Font *font = inv->v3(caster, FUN_002672f0("font_serpentine_lt_med", 0));
    if (w != 0) {
        unsigned short *d = f.text;
        while (*w != 0)
            *d++ = *w++;
        *d = 0;
    } else {
        const char *s = FUN_001b8b60(code);
        FUN_00294c70(s, f.text, (int)strlen(s) + 1);
    }
    FUN_001b8970(f.text, 0x14);
    if (font != 0) {
        if ((*(TextObj**)&DAT_004e2268) == 0) {
            void *mem = thunk_FUN_0008d690(0x58);
            TextObj *t = 0;
            if (mem != 0)
                t = ((TextObj *)mem)->FUN_0029b120(font, f.text, 1.0f, 0);
            (*(TextObj**)&DAT_004e2268) = t;
            t->AddRef();
        }
        f.y = f.u0.height * 0.5f - 50.0f;
        if (f.text[0] != 0) {
            const unsigned short *q = f.text;
            do {
                unsigned short *d = f.line;
                while (*q != 0xa && *q != 0)
                    *d++ = *q++;
                *d = 0;
                if (*q != 0)
                    q++;
                (*(TextObj**)&DAT_004e2268)->FUN_0029b330(f.line, 0);
                f.u0.x = (f.width - font->Width(f.line) * 1.5f) * 0.5f;
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->cam->v21(0);
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->FUN_00293d40(f.u0.x - 2.0f, f.y + 2.0f, 2.0f);
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->FUN_00293da0(1.5f, -1.5f, 1.0f);
                (*(TextObj**)&DAT_004e2268)->FUN_0029b380(0xff000000);
                (*(TextObj**)&DAT_004e2268)->Draw();
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->cam->v16(0);
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->cam->v21(0);
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->FUN_00293d40(f.u0.x, f.y, 2.0f);
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->FUN_00293da0(1.5f, -1.5f, 1.0f);
                (*(TextObj**)&DAT_004e2268)->FUN_0029b380(0xffffffff);
                (*(TextObj**)&DAT_004e2268)->Draw();
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->cam->v16(0);
                f.y = f.y + 25.0f;
            } while (*q != 0);
        }
    } else {
        Device_1bb0b0 *dev = DAT_0052c2a8;
        dev->v33(FUN_001b8b60(code), 100, 100, 0xffffffff);
    }
    if (DAT_004dd8e7) {
        if (DAT_00528404) {
            sprintf(f.msg, "UNKNOWN ERROR CODE %d", DAT_00528404);
            DAT_0052c2a8->v33(f.msg, 100, 300, 0xffff0000);
        } else {
            DAT_0052c2a8->v33("KNOWN ERROR CODE - VALID ERROR", 100, 300, 0xffff0000);
        }
    }
    DAT_0052c2a8->v24(f.saved);
    DAT_0052c2a8->v54(1);
    DAT_0052c2a8->v58(1);
    (*(Banner**)&DAT_0052c2b4)->FUN_0028faf0(1);
}
