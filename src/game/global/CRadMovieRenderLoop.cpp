// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001b6f90..0x001b7970 (kind game, layer game, confidence high), dominant class CRadMovieRenderLoop
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/address.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_fbeebd58 {
#define TREE_TU_END }
namespace fn_fbeebd58 {} using namespace fn_fbeebd58;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_fbeebd58 {
extern "C" char DAT_0041dc30[];
struct Other_1b6f90 {
    virtual void A();
    virtual void B();
};
struct CRadMovieRenderLoop_1b6f90 {
    void* vptr;
    char pad[8];
    Other_1b6f90* obj;
    void F();
};
struct Vertices {
    void FUN_0008ef00();
    char pad0[8];
    float *pos;
    char pad1[4];
    unsigned int *color;
};
struct Screen_1b6fd0 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual int vfn6();
    virtual int vfn7();
};
} // namespace fn_fbeebd58
struct Gfx {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13();
    virtual void vfn14();
    virtual void vfn15();
    virtual void vfn16();
    virtual void vfn17();
    virtual void vfn18();
    virtual void vfn19();
    virtual void vfn20();
    virtual void vfn21();
    virtual void vfn22();
    virtual void vfn23();
    virtual void vfn24(int v);
    virtual int vfn25();
    virtual void vfn26();
    virtual void vfn27();
    virtual void vfn28();
    virtual void vfn29();
    virtual Vertices *vfn30(Surface *s, int a, int b, int c, int d);
    virtual void vfn31(Vertices *v);
    virtual void vfn32();
    virtual void vfn33();
    virtual void vfn34();
    virtual void vfn35();
    virtual void vfn36();
    virtual void vfn37();
    virtual void vfn38();
    virtual void vfn39();
    virtual void vfn40();
    virtual void vfn41();
    virtual void vfn42();
    virtual void vfn43();
    virtual void vfn44();
    virtual void vfn45();
    virtual void vfn46();
    virtual void vfn47();
    virtual void vfn48();
    virtual void vfn49();
    virtual void vfn50();
    virtual void vfn51();
    virtual void vfn52();
    virtual void vfn53();
    virtual void vfn54(int v);
    virtual void vfn55();
    virtual void vfn56();
    virtual void vfn57();
    virtual void vfn58(int v);
};
namespace fn_fbeebd58 {
struct Stage_1b6fd0 {
    virtual void vfn0();
    virtual void vfn1();
    virtual void vfn2();
    virtual void vfn3();
    virtual void vfn4();
    virtual void vfn5();
    virtual void vfn6();
    virtual void vfn7();
    virtual void vfn8();
    virtual void vfn9();
    virtual void vfn10();
    virtual void vfn11();
    virtual void vfn12();
    virtual void vfn13(int v);
    virtual void vfn14();
    virtual void vfn15(int v);
    virtual void vfn16(int v);
};
struct Holder_1b6fd0 {
    char pad[0x10];
    Surface *surface;
};
struct Ent_1b7290 {
    float w, x, y, z;
};
struct Buf_1b7290 {
    Ent_1b7290 e[1];
    Buf_1b7290* Init_001b6ed0();
};
struct Obj_1b7290 {
    char pad[0x124];
    Buf_1b7290* buf;
    void Add(float, float, float, float);
};
extern void* __cdecl Alloc(hulk_uintptr);
struct State_1b7310 {
    int value;
};
struct Object {
    char pad0[8];
    unsigned char active;
    char pad9[7];
    unsigned int parameter;
    char text[256];
    unsigned char flag;
    char pad115[3];
    State_1b7310* state;
    void update(const char* source, unsigned int parameterValue, unsigned char flagValue);
};
struct Language { const char* FUN_000bb670(); };
struct Manager_1b73c0 { Language* FUN_00086280(); };
} // namespace fn_fbeebd58
struct World { char padding[0x54]; Manager_1b73c0* manager; };
#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" int __cdecl memcmp(const void*, const void*, unsigned int);
#endif
namespace fn_fbeebd58 {
static inline int memcmp_lit(const char *a, const char *b, unsigned n)
{
    for (; n != 0; n--, a++, b++)
        if (*a != *b)
            return (unsigned char)*a - (unsigned char)*b;
    return 0;
}
typedef unsigned int u32_1b7590;
struct Obj_1b7590 {
    char pad[0x124];
    volatile u32_1b7590 field;
};
extern void __cdecl thunk(u32_1b7590);
struct Inner_1b7590 {
    void method_001bf860(int);
};
struct Global_1b7590 {
    char pad[0x50];
    Inner_1b7590* value;
};
extern Global_1b7590* hulk_at_004dd700;
class Ref_1b75d0 {
  public:
    virtual void F();
};
class Owner_1b75d0 {
  public:
    Ref_1b75d0* mRef;
    Owner_1b75d0* Set(Ref_1b75d0* r);
};
class Item_1b7620 {
  public:
    virtual void Add();
    virtual void Release();
};
class Holder_1b7620 {
  public:
    Item_1b7620* mItem;
    Item_1b7620* Set(Item_1b7620* item);
};
class Ref_1b7670 {
  public:
    virtual void F();
};
class Owner_1b7670 {
  public:
    Ref_1b7670* mRef;
    Owner_1b7670* Set(Ref_1b7670* r);
};
class Ref_1b76c0 {
  public:
    virtual void F();
};
class Owner_1b76c0 {
  public:
    Ref_1b76c0* mRef;
    Owner_1b76c0* Set(Ref_1b76c0* r);
};
typedef unsigned int u32_1b7740;
extern "C" int __cdecl alloc(hulk_intptr);
extern int hulk_at_0041dc30;
struct Inner_1b7740 {
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void d();
    virtual void e();
    virtual void f();
    virtual void g(u32_1b7740, u32_1b7740);
};
struct Made_1b7740 {
    char pad[0x10];
    Inner_1b7740* p;
};
struct Shader_nv_1b7740 {
    Made_1b7740* make_0028edb0();
};
struct CRadMovieRenderLoop_1b7740 {
    hulk_uintptr vptr;
    int state;
    int zero;
    Made_1b7740* made;
};
class RC {
  public:
    virtual void AddRef();
    virtual void Release();
};
class Obj3_1b77e0 : public RC {
  public:
    virtual void Fn2();
    virtual void Fn3(RC* a, RC* b);
};
class Res_1b77e0 : public RC {};
struct CRadMovieRenderLoop_nv_1b77e0 {
    CRadMovieRenderLoop* Init_001b7740();
};
class Mgr_1b77e0 {
  public:
    void Fn_002088a0();
};
class Target_1b77e0 {
  public:
    void Run();
    char pad0[0xc];
    Obj3_1b77e0* mObj;
    char pad1[0x120 - 0x10];
    Mgr_1b77e0* mMgr;
    char pad2[4];
    RC* mSub;
};
void* __cdecl Alloc_0008d710(int size, int tag);
extern "C" int __cdecl FUN_00266da0(int a);
extern "C" RC* __cdecl FUN_00334910(int a);
Obj3_1b77e0* __cdecl GetB_00334010(int a);
struct Obj {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void slot3();
    virtual void slot4();
    virtual void slot5();
    virtual void slot6();
    virtual void slot7();
};
struct Owner {
    char pad0[12];
    Obj *object;
    char pad1[0x118];
    int state;
    void FUN_001b78a0();
};
struct ThisWrap_001b7960 {
    void FUN_001b7360(int a, int b);
    void FUN_001b7960(hulk_intptr a, int b);
};


// 0x001b6f90 FUN_001b6f90 (25 B): matches/0x001b6f90.cpp
// sym: ?F@CRadMovieRenderLoop_1b6f90@fn_fbeebd58@@QAEXXZ
void CRadMovieRenderLoop_1b6f90::F() {
    vptr = (void*)((hulk_intptr)DAT_0041dc30);
    obj->B();
    vptr = (void*)((hulk_intptr)DAT_003f6098);
}

} // namespace fn_fbeebd58

// 0x001b6fb0 CRadMovieRenderLoop::vfunc_0 (4 B): matches/0x001b6fb0.cpp
// sym: ?vfunc_0@CRadMovieRenderLoop@@UAEXXZ
void CRadMovieRenderLoop::vfunc_0() {
    this->f_08++;
}


// 0x001b6fc0 CRadMovieRenderLoop::vfunc_1 (13 B): matches/0x001b6fc0.cpp [wrapped: conflict: CRadMovieRenderLoop]
// sym: ?vfunc_1@CRadMovieRenderLoop@fn_001b6fc0@@UAEXXZ
namespace fn_001b6fc0 {
class CRadMovieRenderLoop {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2(bool);
    virtual void vfunc_3();
    int pad;
    int mRefCount;
};
void CRadMovieRenderLoop::vfunc_1() {
    if (--mRefCount == 0)
        vfunc_2(true);
}
} // namespace fn_001b6fc0


// 0x001b6fd0 FUN_001b6fd0 (416 B): equivalent/0x001b6fd0.cpp
// sym: ?FUN_001b6fd0@CRadMovieRenderLoop@@QAEXH@Z @2539ba83e8bd @w51ad486fe8d5
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 0/0)
// FUN_001b6fd0 @ 0x001b6fd0
void CRadMovieRenderLoop::FUN_001b6fd0(int alpha) {
    float w = (float)(*(Screen_1b6fd0**)&DAT_0052c2a4)->vfn7();
    float h = (float)(*(Screen_1b6fd0**)&DAT_0052c2a4)->vfn6();
    int saved = DAT_0052c2a8->vfn25();
    DAT_0052c2a8->vfn24(2);
    DAT_0052c2a8->vfn54(0);
    DAT_0052c2a8->vfn58(0);
    (*(*(Stage_1b6fd0***)&DAT_0052c2ac))->vfn15(0);
    (*(*(Stage_1b6fd0***)&DAT_0052c2ac))->vfn13(0);

    unsigned int color = (unsigned int)alpha << 24;
    Vertices *v = DAT_0052c2a8->vfn30((*(Holder_1b6fd0 * *)&this->f_0c)->surface, 1, 0x2020, 4, 0);
    v->color[0] = color;
    v->pos[0] = 0;
    v->pos[1] = h;
    v->pos[2] = 2.0f;
    v->FUN_0008ef00();

    v->color[0] = color;
    v->pos[0] = 0;
    v->pos[1] = 0;
    v->pos[2] = 2.0f;
    v->FUN_0008ef00();

    v->color[0] = color;
    v->pos[0] = w;
    v->pos[1] = h;
    v->pos[2] = 2.0f;
    v->FUN_0008ef00();

    v->color[0] = color;
    v->pos[0] = w;
    v->pos[1] = 0;
    v->pos[2] = 2.0f;
    v->FUN_0008ef00();

    DAT_0052c2a8->vfn31(v);
    DAT_0052c2a8->vfn24(saved);
    DAT_0052c2a8->vfn54(1);
    DAT_0052c2a8->vfn58(1);
    (*(*(Stage_1b6fd0***)&DAT_0052c2ac))->vfn16(0);
}


// 0x001b7170 CRadMovieRenderLoop::vfunc_3 (234 B): matches/0x001b7170.cpp [wrapped: conflict: CRadMovieRenderLoop; DAT_004dd700; DAT_0052c2a8; Overlay]
// sym: ?vfunc_3@CRadMovieRenderLoop@fn_001b7170@@UAEXPAUFader_1b7170@2@@Z
namespace fn_001b7170 {

struct Fader_1b7170 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10(float);
    virtual float vf11();
};
struct Overlay {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12(int);
    virtual void vf13();
    virtual void vf14();
    virtual void vf15();
    virtual void vf16();
    virtual void vf17();
    virtual void vf18();
    virtual void vf19();
    virtual void vf20();
    virtual void vf21();
    virtual void vf22();
    virtual void vf23();
    virtual void vf24();
    virtual void vf25();
    virtual void vf26();
    virtual void vf27();
    virtual void vf28();
    virtual void vf29();
    virtual void vf30();
    virtual void vf31();
    virtual void vf32();
    virtual void vf33();
    virtual void vf34();
    virtual void vf35();
    virtual void vf36();
    virtual void vf37();
    virtual void vf38();
    virtual void vf39();
    virtual void vf40();
    virtual void vf41();
    virtual void vf42();
    virtual void vf43();
    virtual void vf44();
    virtual void vf45();
    virtual void vf46();
    virtual void vf47();
    virtual void vf48();
    virtual void vf49();
    virtual void vf50();
    virtual void vf51();
    virtual void vf52();
    virtual void vf53();
    virtual void vf54();
    virtual void vf55();
    virtual void vf56();
    virtual void vf57();
    virtual void vf58(int);
};
struct Screen_1b7170 {
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void vf4();
    virtual void vf5();
    virtual void vf6();
    virtual void vf7();
    virtual void vf8();
    virtual void vf9();
    virtual void vf10();
    virtual void vf11();
    virtual void vf12();
    virtual void vf13();
    virtual void vf14();
};
struct Global2b4 {
    char pad[0xd8];
    int field_d8;
    void FUN_0028f9a0();
    void FUN_0028faf0(int);
};
struct Global700 {
    char pad[0x50];
    struct Sub_1b7170* sub;
};
struct Sub_1b7170 {
    void FUN_001bf8b0();
};

#define DAT_0052c2a8 (*(Overlay* *)&::DAT_0052c2a8)


#define DAT_004dd700 (*(Global700* *)&::DAT_004dd700)

class CRadMovieRenderLoop {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3(Fader_1b7170* fader);
    int fade;
    void FUN_001b6fd0(int);
};
void CRadMovieRenderLoop::vfunc_3(Fader_1b7170* fader) {
    (*(Screen_1b7170**)&DAT_0052c2a4)->vf14();
    (*(Global2b4**)&DAT_0052c2b4)->field_d8 = -1;
    DAT_0052c2a8->vf58(0);
    DAT_0052c2a8->vf12(7);
    (*(Global2b4**)&DAT_0052c2b4)->FUN_0028f9a0();
    fader->vf4();
    if (fade == -1)
        FUN_001b6fd0(0xff);
    DAT_004dd700->sub->FUN_001bf8b0();
    if (fade >= 0) {
        hulk_freg frac = (hulk_freg)(10 - fade) * 0.1f;
        FUN_001b6fd0((int)(__int64)(frac * 255.0f));
        fade--;
        hulk_freg level = fader->vf11() - 0.1f;
        if (level < 0.0f)
            level = 0.0f;
        fader->vf10(level);
    }
    (*(Global2b4**)&DAT_0052c2b4)->FUN_0028faf0(0);
}
} // namespace fn_001b7170
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x001b7260 FUN_001b7260 (43 B): matches/0x001b7260.cpp
// sym: ?FUN_001b7260@C_1b7260@owners@@QAEXHHHH@Z
void owners::C_1b7260::FUN_001b7260(hulk_intptr x, hulk_intptr y, hulk_intptr z, hulk_intptr w) {
    a = ((int)x);
    b = ((int)y);
    c = ((int)z);
    d = ((int)w);
}

namespace fn_fbeebd58 {

// 0x001b7290 FUN_001b7290 (114 B): matches/0x001b7290.cpp
// sym: ?Add@Obj_1b7290@fn_fbeebd58@@QAEXMMMM@Z
void Obj_1b7290::Add(float a, float b, float c, float d) {
    if (!buf) {
        void* m = Alloc(0x504);
        buf = m ? ((Buf_1b7290*)m)->Init_001b6ed0() : 0;
    }
    Buf_1b7290* p = buf;
    int* cnt = (int*)p;
    p->e[*cnt].x = a;
    p->e[*cnt].y = b;
    p->e[*cnt].z = c;
    p->e[*cnt + 1].w = d;
    *cnt = *cnt + 1;
}


// 0x001b7310 FUN_001b7310 (79 B): equivalent/0x001b7310.cpp
// sym: ?update@Object@fn_fbeebd58@@QAEXPBDIE@Z @47d51bc1d74e @w4f714e7335e3
// STATUS: equivalent (tools/equiv.py level 3: 74 inputs, branch coverage 6/6)
// FUN_001b7310 @ 0x001b7310
void Object::update(const char* source, unsigned int parameterValue, unsigned char flagValue) {
    if (source && state->value != 7) {
        flag = flagValue;
        parameter = parameterValue;
        char* destination = text;
        char c;
        do {
            c = *source++;
            *destination++ = c;
        } while (c != 0);
        ((owners::Target_863e0 *)state)->FUN_000863e0(7);
        active = 1;
    }
}

} // namespace fn_fbeebd58

// 0x001b7360 FUN_001b7360 (79 B): equivalent/0x001b7360.cpp [wrapped: conflict: Object]
// sym: ?FUN_001b7360@Object@fn_001b7360@@QAEXPBDH@Z @784e58e84526 @w70817c7bb7a6
namespace fn_001b7360 {
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 6/6)
// FUN_001b7360 @ 0x001b7360
struct State { int mode;  };
struct Object {
    char pad0[8];
    unsigned char active;
    char pad1[7];
    int value;
    char text[256];
    unsigned char pending;
    char pad2[3];
    State *state;
    void FUN_001b7360(const char *source, int number);
};
void Object::FUN_001b7360(const char *source, int number) {
    if (source && state->mode != 7) {
        value = number;
        pending = 1;
        char *dest = text;
        char c;
        do {
            c = *source++;
            *dest++ = c;
        } while (c);
        ((owners::Target_863e0 *)state)->FUN_000863e0(7);
        active = 1;
    }
}
} // namespace fn_001b7360

namespace fn_fbeebd58 {

// 0x001b73c0 FUN_001b73c0 (224 B): equivalent/0x001b73c0.cpp
// sym: ?FUN_001b73c0@fn_fbeebd58@@YGPBXPBD@Z @c668d9450eab @wdadc82a09b99
// STATUS: equivalent (tools/equiv.py level 3: 20034 inputs, branch coverage 18/18)
// FUN_001b73c0 @ 0x001b73c0
const void* __stdcall FUN_001b73c0(const char* name) {
    if (memcmp_lit(name, "dolby", 6) == 0 || memcmp_lit(name, "radical", 8) == 0)
        return ((unsigned char*)&DAT_00434270);
    if (memcmp_lit(name + 3, "anim", 5) != 0 &&
        memcmp_lit(name, "transformation", 15) != 0 &&
        memcmp_lit(name, "dintro", 7) != 0 &&
        memcmp_lit(name, "attract", 8) != 0)
        return ((unsigned char*)&DAT_00434250);
    if (!(*(unsigned char*)&DAT_004dd839))
        return ((unsigned char*)&DAT_00434270);
    const char* language = DAT_004dd700->manager->FUN_00086280()->FUN_000bb670();
    if (memcmp_lit(language, "fr", 3) == 0)
        return ((unsigned char*)&DAT_0041dbe8);
    if (memcmp_lit(language, "it", 3) == 0)
        return ((unsigned char*)&DAT_0041dbf0);
    return ((unsigned char*)&DAT_00434270);
}


// 0x001b7590 FUN_001b7590 (59 B): matches/0x001b7590.cpp
// sym: ?target@fn_fbeebd58@@YIXPAUObj_1b7590@1@@Z
void __fastcall target(Obj_1b7590* p) {
    u32_1b7590 x = p->field;
    if (x) {
        thunk(x);
        p->field = 0;
    }
    p->field = 0;
    hulk_at_004dd700->value->method_001bf860(1);
}


// 0x001b75d0 FUN_001b75d0 (23 B): matches/0x001b75d0.cpp
// sym: ?Set@Owner_1b75d0@fn_fbeebd58@@QAEPAV12@PAVRef_1b75d0@2@@Z
Owner_1b75d0* Owner_1b75d0::Set(Ref_1b75d0* r) {
    mRef = r;
    if (r)
        r->F();
    return this;
}


// 0x001b7620 FUN_001b7620 (42 B): matches/0x001b7620.cpp
// sym: ?Set@Holder_1b7620@fn_fbeebd58@@QAEPAVItem_1b7620@2@PAV32@@Z
Item_1b7620* Holder_1b7620::Set(Item_1b7620* item) {
    Item_1b7620* old = mItem;
    if (old != item) {
        mItem = item;
        if (item)
            item->Add();
        if (old)
            old->Release();
    }
    return mItem;
}


// 0x001b7670 FUN_001b7670 (23 B): matches/0x001b7670.cpp
// sym: ?Set@Owner_1b7670@fn_fbeebd58@@QAEPAV12@PAVRef_1b7670@2@@Z
// Same code shape as 0x001b75d0 (propagated; names are from that function)
Owner_1b7670* Owner_1b7670::Set(Ref_1b7670* r) {
    mRef = r;
    if (r)
        r->F();
    return this;
}


// 0x001b76c0 FUN_001b76c0 (23 B): matches/0x001b76c0.cpp
// sym: ?Set@Owner_1b76c0@fn_fbeebd58@@QAEPAV12@PAVRef_1b76c0@2@@Z
// Same code shape as 0x001b75d0 (propagated; names are from that function)
Owner_1b76c0* Owner_1b76c0::Set(Ref_1b76c0* r) {
    mRef = r;
    if (r)
        r->F();
    return this;
}


// 0x001b7740 FUN_001b7740 (72 B): matches/0x001b7740.cpp
// sym: ?FUN_001b7740@fn_fbeebd58@@YIPAUCRadMovieRenderLoop_1b7740@1@PAU21@@Z
CRadMovieRenderLoop_1b7740* __fastcall FUN_001b7740(CRadMovieRenderLoop_1b7740* self) {
    self->vptr = (hulk_uintptr)&hulk_at_0041dc30;
    self->state = -2;
    self->zero = 0;
    hulk_intptr t = alloc(32);
    Made_1b7740* m;
    if (t)
        m = ((Shader_nv_1b7740*)(((pure3d::Shader*)(((pure3d::Shader*)t)))))->make_0028edb0();
    else
        m = 0;
    self->made = m;
    m->p->g(0x444d4c42, 1);
    return self;
}

} // namespace fn_fbeebd58

// 0x001b7790 CRadMovieRenderLoop::vfunc_2 (45 B): matches/0x001b7790.cpp [wrapped: conflict: CRadMovieRenderLoop]
// sym: ?vfunc_2@CRadMovieRenderLoop@fn_001b7790@@UAEPAV12@E@Z
namespace fn_001b7790 {
class RenderThing_1b7790 {
  public:
    virtual void f0();
    virtual void f1();
};
extern int rad_vtable;
extern int hulk_at_003f6098;
class CRadMovieRenderLoop {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual CRadMovieRenderLoop* vfunc_2(unsigned char);
    virtual void vfunc_3();
    char pad[8];
    RenderThing_1b7790* member;
};
extern void destroy_0008d330(CRadMovieRenderLoop*);
CRadMovieRenderLoop* CRadMovieRenderLoop::vfunc_2(unsigned char flags) {
    *(hulk_intptr*)this = (hulk_intptr)&rad_vtable;
    member->f1();
    *(hulk_intptr*)this = (hulk_intptr)&hulk_at_003f6098;
    if (flags & 1)
        destroy_0008d330(this);
    return this;
}
} // namespace fn_001b7790

namespace fn_fbeebd58 {

// 0x001b77e0 FUN_001b77e0 (189 B): matches/0x001b77e0.cpp
// sym: ?Run@Target_1b77e0@fn_fbeebd58@@QAEXXZ
void Target_1b77e0::Run() {
    mMgr->Fn_002088a0();
    int saved = FUN_00266da0(7);
    void* mem = Alloc_0008d710(0x10, 7);
    RC* s;
    if (mem)
        s = (RC*)((CRadMovieRenderLoop_nv_1b77e0*)(((CRadMovieRenderLoop*)(((CRadMovieRenderLoop*)mem)))))->Init_001b7740();
    else
        s = 0;
    mSub = s;
    if (s)
        s->AddRef();
    RC* a = FUN_00334910(7);
    if (a)
        a->AddRef();
    Obj3_1b77e0* nw = GetB_00334010(7);
    Obj3_1b77e0* old = mObj;
    if (old != nw) {
        mObj = nw;
        if (nw)
            nw->AddRef();
        if (old)
            old->Release();
    }
    mObj->Fn3(s, a);
    if (a)
        a->Release();
    if (s)
        s->Release();
    FUN_00266da0(saved);
}


// 0x001b78a0 FUN_001b78a0 (42 B): equivalent/0x001b78a0.cpp
// sym: ?FUN_001b78a0@Owner@fn_fbeebd58@@QAEXXZ @99f90a2b8e74 @w49359f4e2c90
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 4/4)
// FUN_001b78a0 @ 0x001b78a0
void Owner::FUN_001b78a0() {
    if (object) object->slot7();
    Obj *old = object;
    if (old) {
        object = 0;
        old->slot1();
    }
    state = 0;
}

} // namespace fn_fbeebd58

// 0x001b7910 FUN_001b7910 (65 B): matches/0x001b7910.cpp [wrapped: conflict: State]
// sym: ?Check@Obj@fn_001b7910@@QAEHXZ
namespace fn_001b7910 {
class State {
  public:
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
    virtual void f10();
    virtual void f11();
    virtual int Get();
};
class Obj {
  public:
    char pad[8];
    char flag;
    char pad2[3];
    State* state;
    int Check();
};
int Obj::Check() {
    int v;
    State* s;
    if (!(((s = state) && ((v = s->Get()) == 4 || v == 3)) ||
          ((s = state) && ((v = s->Get()) == 1 || v == 2)) || flag))
        return 0;
    return 1;
}
} // namespace fn_001b7910

namespace fn_fbeebd58 {

// 0x001b7960 FUN_001b7960 (13 B): matches/0x001b7960.cpp
// sym: ?FUN_001b7960@ThisWrap_001b7960@fn_fbeebd58@@QAEXHH@Z
void ThisWrap_001b7960::FUN_001b7960(hulk_intptr a, int b) {
    this->FUN_001b7360(a, 3000);
}

} // namespace fn_fbeebd58
