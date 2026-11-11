// cl-flags: /GS
// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b8690..0x001bc0c0 (kind game, layer game, confidence high), dominant class CRenderManager
#include "tree_prelude.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "decls/data/game/unknown.h"
#include "decls/data/platform/xbox/core.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_faf7c40e {
#define TREE_TU_END }
#define TREE_LOCAL_CCollisionTrack
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_faf7c40e {} using namespace fn_faf7c40e;
#include "game/global.h"

// ---- declarations shared by the functions below
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char*, const char*, ...);
#endif
namespace fn_faf7c40e {
struct Controller_1bc040 {
    int FUN_000ae960();
};
struct Profile_1bc040 {
    Controller_1bc040* FUN_000862c0();
};
} // namespace fn_faf7c40e
struct World {
    char pad[0x54];
    Profile_1bc040* profile;
};


// 0x001baab0 FUN_001baab0 (1531 B): equivalent/0x001baab0.cpp [wrapped: conflict: DAT_004dd700; DAT_0052c2a8]
// sym: ?FUN_001baab0@Credits_1baab0@fn_001baab0@@QAEX_N@Z @3f2dbe2eb394 @wa83fe2097d39
inline void *operator new(size_t, void *p) throw() { return p; }
namespace fn_001baab0 {
// STATUS: equivalent (tools/equiv.py level 3: 130 inputs, branch coverage 45/46, incomplete)
// FUN_001baab0 @ 0x001baab0
// cl-flags: /GS
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char *);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" char *__cdecl strstr(const char *, const char *);
#endif

void *thunk_FUN_0008d690(unsigned int size);
extern "C++" __declspec(nothrow) unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
extern "C" unsigned int __cdecl FUN_00267f80();
extern "C" int __cdecl FUN_001b8970(unsigned short *s, int n);
extern "C" void __cdecl FUN_00294c70(const char *src, unsigned short *dst, int n);

namespace pure3d { class TextureFont_1baab0; }
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
    virtual Font *v3(content::LoadInventory::DynamicCaster<pure3d::TextureFont_1baab0> *caster, unsigned __int64 hash);
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


#define DAT_004dd700 (*(Globals_1baab0 * *)&::DAT_004dd700)


#define DAT_0052c2a8 (*(Device_1baab0 * *)&::DAT_0052c2a8)


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
                unsigned short *wn = ((unsigned short *)((owners::A_f7d30 *)(thunk_FUN_000fc1b0(DAT_004dd700->replay->FUN_00086280())))->FUN_000f7d30((hulk_intptr)s));   // the argument is evaluated before the receiver
                w = ((unsigned short *)((owners::C_f7220 *)(thunk_FUN_000fc1b0(DAT_004dd700->replay->FUN_00086280())))->FUN_000f7220((hulk_intptr)wn));
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
                content::LoadInventory::DynamicCaster<pure3d::TextureFont_1baab0> *caster =
                    new (&f.casterSlot) content::LoadInventory::DynamicCaster<pure3d::TextureFont_1baab0>();
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
                        ((owners::Obj_29b380 *)((*(TextObj**)&DAT_004e226c)))->FUN_0029b380(0xff000000);
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
                        ((owners::Obj_29b380 *)((*(TextObj**)&DAT_004e226c)))->FUN_0029b380((int)(f.color));
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
} // namespace fn_001baab0
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001bb0b0 FUN_001bb0b0 (1150 B): equivalent/0x001bb0b0.cpp [wrapped: conflict: DAT_004dd700; DAT_0052c2a8; thunk_FUN_000fc1b0]
// sym: _FUN_001bb0b0 @6f85bf21b3f2 @w085d4246fe29
namespace fn_001bb0b0 {
// STATUS: equivalent (tools/equiv.py level 3: 3138 inputs, branch coverage 44/44)
// FUN_001bb0b0 @ 0x001bb0b0
// cl-flags: /GS
// FUN_001bb0b0 @ 0x001bb0b0: draw an error / status message on the screen
// equiv-map: ?thunk_FUN_0008d690@@YAPAXI@Z = 0x00263ea0


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl sprintf(char *, const char *, ...);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" unsigned int __cdecl strlen(const char *);
#endif

void *thunk_FUN_0008d690(unsigned int size);
extern "C++" __declspec(nothrow) unsigned __int64 __cdecl FUN_002672f0(const char *s, unsigned __int64 seed);
extern "C" int __cdecl FUN_001b8970(unsigned short *s, int n);
extern "C" void __cdecl FUN_00294c70(const char *src, unsigned short *dst, int n);
extern "C" const char *__cdecl FUN_001b8b60(const char *text);
extern "C" void __cdecl FUN_002684c0();

namespace pure3d { class TextureFont_1bb0b0; }
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
    virtual Font *v3(content::LoadInventory::DynamicCaster<pure3d::TextureFont_1bb0b0> *caster, unsigned __int64 hash);
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
    void FUN_0028faf0(int a);
};

struct Res;
struct Obj1_1bb0b0 {
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


#define DAT_004dd700 (*(Globals_1bb0b0 * *)&::DAT_004dd700)


#define DAT_0052c2a8 (*(Device_1bb0b0 * *)&::DAT_0052c2a8)


struct Frame_1bb0b0 {
    union {
        float height;              // 0x00
        float x;
    } u0;
    float y;                       // 0x04
    float width;                   // 0x08
    content::LoadInventory::DynamicCaster<pure3d::TextureFont_1bb0b0> caster;  // 0x0c
    int saved;                     // 0x10
    char msg[0x100];               // 0x14
    unsigned short text[0x200];    // 0x114
    unsigned short line[0x200];    // 0x514
};



extern "C" void __cdecl FUN_001bb0b0(const char *code)
{
    Frame_1bb0b0 f;
    if (DAT_004dd700 && DAT_004dd700->replay && DAT_004dd700->replay->FUN_00086330()) {
        DAT_004dd700->replay->FUN_00086330()->FUN_000afe80();
        FUN_002684c0();
    }
    f.width = (float)(*(Clock_1bb0b0**)&DAT_0052c2a4)->Width();
    f.u0.height = (float)(*(Clock_1bb0b0**)&DAT_0052c2a4)->Height();
    f.saved = DAT_0052c2a8->v25();
    ((owners::X_28f9a0 *)((*(Banner**)&DAT_0052c2b4)))->FUN_0028f9a0();
    DAT_0052c2a8->v12(-1);
    DAT_0052c2a8->v24(2);

    unsigned short *w = 0;
    if (DAT_004dd700 && DAT_004dd700->replay && DAT_004dd700->replay->FUN_00086280()
        && thunk_FUN_000fc1b0(DAT_004dd700->replay->FUN_00086280())) {
        unsigned short *wn = ((unsigned short *)((owners::A_f7d30 *)(thunk_FUN_000fc1b0(DAT_004dd700->replay->FUN_00086280())))->FUN_000f7d30((hulk_intptr)code));   // the argument is evaluated before the receiver
        w = ((unsigned short *)((owners::C_f7220 *)(thunk_FUN_000fc1b0(DAT_004dd700->replay->FUN_00086280())))->FUN_000f7220((hulk_intptr)wn));
    }
    Loader_1bb0b0 *inv = (*(Loader_1bb0b0**)&DAT_004dd9c8);
    content::LoadInventory::DynamicCaster<pure3d::TextureFont_1bb0b0> *caster =
        new (&f.caster) content::LoadInventory::DynamicCaster<pure3d::TextureFont_1bb0b0>();
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
                ((owners::Obj_29b380 *)((*(TextObj**)&DAT_004e2268)))->FUN_0029b380(0xff000000);
                (*(TextObj**)&DAT_004e2268)->Draw();
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->cam->v16(0);
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->cam->v21(0);
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->FUN_00293d40(f.u0.x, f.y, 2.0f);
                (*(Renderer_1bb0b0**)&DAT_0052c2ac)->FUN_00293da0(1.5f, -1.5f, 1.0f);
                ((owners::Obj_29b380 *)((*(TextObj**)&DAT_004e2268)))->FUN_0029b380(0xffffffff);
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
} // namespace fn_001bb0b0
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_faf7c40e {

// 0x001bc040 FUN_001bc040 (113 B): matches/0x001bc040.cpp
// sym: ?FUN_001bc040@fn_faf7c40e@@YAXXZ
// STATUS: equivalent (tools/equiv.py level 3: 3002 inputs, branch coverage 2/2)
// FUN_001bc040 @ 0x001bc040
// Shows the "controller lost" message for the active port (or for all ports).
void FUN_001bc040()
{
    struct Frame {
        char key[0x100];
    } f;
    int port = DAT_004dd700->profile->FUN_000862c0()->FUN_000ae960();
    if (port >= 0)
        sprintf(f.key, "TBS_LOST_CONTROLLER_XBOX_PORT_%d", port + 1);
    else
        strcpy(f.key, "TBS_LOST_CONTROLLER_XBOX_ALL");
    FUN_001bb0b0(f.key);
}

} // namespace fn_faf7c40e
