// STATUS: equivalent (tools/equiv.py level 3: 124 inputs, branch coverage 45/46, incomplete)
// FUN_001baab0 @ 0x001baab0
// cl-flags: /GS
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"

extern "C" unsigned int __cdecl strlen(const char *);
extern "C" char *__cdecl strstr(const char *, const char *);
void *thunk_FUN_0008d690(unsigned int size);
unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
unsigned int __cdecl FUN_00267f80();
int __cdecl FUN_001b8970(unsigned short *s, int n);
void __cdecl FUN_00294c70(const char *src, unsigned short *dst, int n);

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

struct Loader_1baab0 {
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

class Cam_1baab0 {
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

struct Renderer_1baab0 {
    Cam_1baab0 *cam;
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293d40(float a, float b, float c);
};

class Clock_1baab0 {
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

class Device_1baab0 {
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
struct Obj1_1baab0 {
    char pad000[0x10c];
    int f10c;
    unsigned short *FUN_000f7d30(const char *name);
    unsigned short *FUN_000f7220(unsigned short *p);
};
Obj1_1baab0 *__fastcall thunk_FUN_000fc1b0(Res *r);

struct Replay_1baab0 {
    Res *FUN_00086280();
    void *FUN_000862c0();
};

struct Globals_1baab0 {
    char pad0[0x54];
    Replay_1baab0 *replay;
};

extern Globals_1baab0 *DAT_004dd700;
extern Device_1baab0 *DAT_0052c2a8;

class Credits_1baab0 {
public:
    char pad00[0x1c];
    float scroll;
    float limit;
    char pad24[4];
    unsigned int lastTick;
    void FUN_001baab0(bool flag);
};

struct Frame_1baab0 {
    float y;                       // 0x10
    union {                        // 0x14
        int n;
        float negScale;
        float x;
    } u14;
    const char **p;                // 0x18
    float scale;                   // 0x1c
    const unsigned short *q;       // 0x20
    unsigned int color;            // 0x24
    int saved;                     // 0x28
    float height;                  // 0x2c
    Credits_1baab0 *self;                 // 0x30
    unsigned int casterSlot;       // 0x34
    float width;                   // 0x38
    Font *font;                    // 0x3c
    unsigned short line[0x100];    // 0x40
    unsigned short lineBuf[0x200]; // 0x240
};

inline void *operator new(unsigned int, void *p) throw() { return p; }

void Credits_1baab0::FUN_001baab0(bool flag)
{
    Frame_1baab0 f;
    f.self = this;
    if (flag)
        (*(Banner**)&DAT_0052c2b4)->FUN_0028f9a0();
    f.width = (float)(*(Clock_1baab0**)&DAT_0052c2a4)->Width();
    f.height = (float)(*(Clock_1baab0**)&DAT_0052c2a4)->Height();
    f.saved = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(1);
    DAT_0052c2a8->v54(0);
    DAT_0052c2a8->v58(0);
    if (flag)
        DAT_0052c2a8->v12(7);
    DAT_0052c2a8->v24(2);

    f.y = scroll;
    f.color = 0xffc8c8c8;
    f.scale = 1.0f;
    f.p = ((const char**)&DAT_004c3c18);
    do {
        const char *s = *f.p;
        if (*s == 0) {
            f.y = f.y + 23.0f;
            f.scale = 1.25f;
            f.color = 0xff65b742;
        } else {
            unsigned short *w = 0;
            if (strstr("TBS_CREDIT", s) == 0) {
                w = thunk_FUN_000fc1b0(DAT_004dd700->replay->FUN_00086280())
                        ->FUN_000f7220(thunk_FUN_000fc1b0(DAT_004dd700->replay->FUN_00086280())->FUN_000f7d30(s));
            }
            if (w != 0) {
                unsigned short *d = f.line;
                while (*w != 0)
                    *d++ = *w++;
                *d = 0;
            } else {
                FUN_00294c70(s, f.line, (int)strlen(s) + 1);
            }
            f.u14.n = FUN_001b8970(f.line, 0x14);
            if (f.y < -120.0f) {
                f.y = (float)f.u14.n * 23.0f + f.y;
            } else {
                if (f.height + 30.0f < f.y)
                    break;
                Loader_1baab0 *inv = (*(Loader_1baab0**)&DAT_004dd9c8);
                content::LoadInventory::DynamicCaster<pure3d::TextureFont> *caster =
                    new (&f.casterSlot) content::LoadInventory::DynamicCaster<pure3d::TextureFont>();
                f.font = inv->v3(caster, FUN_002672f0("font_serpentine_lt_med", 0));
                if (f.line[0] != 0) {
                    float negScale = -f.scale;
                    f.u14.negScale = negScale;
                    f.q = f.line;
                    do {
                        unsigned short *d = f.lineBuf;
                        while (*f.q != 0xa && *f.q != 0)
                            *d++ = *f.q++;
                        *d = 0;
                        if (*f.q != 0)
                            f.q++;
                        if ((*(TextObj**)&DAT_004e226c) == 0) {
                            void *mem = thunk_FUN_0008d690(0x58);
                            TextObj *t = 0;
                            if (mem != 0)
                                t = ((TextObj *)mem)->FUN_0029b120(f.font, f.lineBuf, 1.0f, 0);
                            (*(TextObj**)&DAT_004e226c) = t;
                            t->AddRef();
                        } else {
                            (*(TextObj**)&DAT_004e226c)->FUN_0029b330(f.lineBuf, 0);
                        }
                        f.u14.x = (f.width - f.font->Width(f.lineBuf) * f.scale) * 0.5f;
                        (*(TextObj**)&DAT_004e226c)->FUN_0029b380(0xff000000);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->cam->v21(0);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->FUN_00293d40(f.u14.x - 2.0f, f.y, 2.0f);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->FUN_00293da0(f.scale, negScale, 1.0f);
                        (*(TextObj**)&DAT_004e226c)->Draw();
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->cam->v16(0);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->cam->v21(0);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->FUN_00293d40(f.u14.x, f.y - 2.0f, 2.0f);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->FUN_00293da0(f.scale, negScale, 1.0f);
                        (*(TextObj**)&DAT_004e226c)->Draw();
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->cam->v16(0);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->cam->v21(0);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->FUN_00293d40(f.u14.x + 2.0f, f.y, 2.0f);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->FUN_00293da0(f.scale, negScale, 1.0f);
                        (*(TextObj**)&DAT_004e226c)->Draw();
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->cam->v16(0);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->cam->v21(0);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->FUN_00293d40(f.u14.x, f.y + 2.0f, 2.0f);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->FUN_00293da0(f.scale, negScale, 1.0f);
                        (*(TextObj**)&DAT_004e226c)->Draw();
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->cam->v16(0);
                        (*(TextObj**)&DAT_004e226c)->FUN_0029b380(f.color);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->cam->v21(0);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->FUN_00293d40(f.u14.x, f.y, 2.0f);
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->FUN_00293da0(f.scale, negScale, 1.0f);
                        (*(TextObj**)&DAT_004e226c)->Draw();
                        (*(Renderer_1baab0**)&DAT_0052c2ac)->cam->v16(0);
                        f.y = f.y + 23.0f;
                    } while (*f.q != 0);
                }
                f.color = 0xffc8c8c8;
                f.scale = 1.0f;
            }
        }
        f.p++;
    } while (f.p < ((const char**)&DAT_004c466c));

    DAT_0052c2a8->v24(f.saved);
    DAT_0052c2a8->v54(1);
    DAT_0052c2a8->v58(1);
    if (flag)
        (*(Banner**)&DAT_0052c2b4)->FUN_0028faf0(1);
    unsigned int now = FUN_00267f80();
    if (lastTick != 0) {
        DAT_004dd700->replay->FUN_000862c0();
        unsigned int d = now - lastTick;
        lastTick = now;
        scroll = scroll - (float)d * 0.025f;
        if (scroll > limit)
            scroll = limit;
    } else {
        lastTick = now;
    }
}
