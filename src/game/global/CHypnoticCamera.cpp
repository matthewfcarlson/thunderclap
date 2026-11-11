// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x000a9e50..0x000ac2c0 (kind game, layer game, confidence high), dominant class CHypnoticCamera
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/global.h"
#include "gen/owners.h"
#define TREE_TU_BEGIN namespace fn_f9c37f09 {
#define TREE_TU_END }
namespace fn_f9c37f09 {} using namespace fn_f9c37f09;
#include "game/global.h"

// ---- declarations shared by the functions below
namespace fn_f9c37f09 {
class C_a9e50 {
  public:
    C_a9e50();
};
extern void* g_vftable_aa0d0[];
class Ref_aa0d0 {
  public:
    void* vptr;
    virtual void f0();
    virtual void f1();
};
struct CHypnoticCamera_nv_aa0d0 {
    void Fn();
};
class CHypnoticCamera_aa0d0 {
  public:
    void* vptr;
    char p[0x420];
    Ref_aa0d0* m424;
    Ref_aa0d0* m428;
    char p42c[0x4c];
    Ref_aa0d0* m478;
    void f();
};
struct Vec3_aa130 { float x, y, z;  };
struct Mat_aa130 {
    float m[16];
};
class Target_aa130 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5();
    virtual void v6(float f, int i);
    virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(int a);
    virtual void v13(); virtual void v14x(); virtual void v15(); virtual void v16();
    virtual void v17(); virtual void v18(); virtual void v19(); virtual void v20();
    virtual void v21(); virtual void v22(); virtual void v23();
    virtual void v24(int a, int b, int c);
};
class Source_aa130 {
public:
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
    virtual void v12(); virtual void v13();
    virtual Mat_aa130* v14();
};
class Obj_aa130 {
public:
    char pad04[0x424];
    Target_aa130* target;
    Source_aa130* source;
    bool FUN_000aa130(int a, Mat_aa130* b, float* out);
};
struct V3_aa450 {
    float x, y, z;
};
struct Entry_aa450 {
    V3_aa450 pos;
    int rest[9];
};
struct Probe_aa450 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void setRange(float range, int flag);   // 0x18
    virtual void v7();
    virtual void v8();
    virtual void reset();                           // 0x24
};
struct Sink_aa450 {
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
    virtual void commit(int flag);                  // 0x30
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
    virtual void hit(int target, int a, int b);     // 0x60
};
struct Source_aa450 {
    bool FUN_00035350(V3_aa450 *out);
};
class Tracer_aa450 {
public:
    char pad0[0x170];
    Source_aa450 *source;                 // 0x170
    int field174;                   // 0x174
    V3_aa450 origin;                      // 0x178
    char pad184[0x190 - 0x184];
    Entry_aa450 best;                     // 0x190
    int field1c0;                   // 0x1c0
    char pad1c4[0x424 - 0x1c4];
    Sink_aa450 *sink;                     // 0x424
    char pad428[4];
    float matrix[16];               // 0x42c
    char pad46c[0x478 - 0x46c];
    Probe_aa450 *probe;                   // 0x478
    unsigned char flag47c;          // 0x47c
    unsigned char flag47d;          // 0x47d

    V3_aa450 *FUN_000a92c0(V3_aa450 *out, int a, Source_aa450 *s);
    char FUN_000aa130(int target, float *m, Entry_aa450 *out);
    char FUN_000aa450(int a1, float *m, int *targets, int count, Source_aa450 *src, int a6, int a7);
};


// 0x000a9e50 FUN_000a9e50 (3 B): matches/0x000a9e50.cpp
// sym: ??0C_a9e50@fn_f9c37f09@@QAE@XZ
C_a9e50::C_a9e50() {}


// 0x000a9e90 CHypnoticCamera::vfunc_28 (1 B): matches/0x000a9e90.cpp
// sym: ?FUN_000a9e90@fn_f9c37f09@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000a9e90() {}


// 0x000a9ea0 CHypnoticCamera::vfunc_29 (1 B): matches/0x000a9ea0.cpp
// sym: ?FUN_000a9ea0@fn_f9c37f09@@YAXXZ
// Same code shape as 0x00025410 (propagated; names are from that function)
void FUN_000a9ea0() {}

} // namespace fn_f9c37f09

// 0x000a9f00 CHypnoticCamera::vfunc_36 (346 B): matches/0x000a9f00.cpp [wrapped: conflict: CHypnoticCamera]
// sym: ?vfunc_36@CHypnoticCamera@fn_000a9f00@@UAEXXZ
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_000a9f00 {
// CHypnoticCamera::vfunc_36 @ 0x000a9f00
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

class Input_a9f00 {
public:
    char FUN_00092940(int button);
};

class Pad_a9f00 {
public:
    Input_a9f00 *FUN_00086340();
};

struct World {
    char pad0[0x54];
    Pad_a9f00 *pad;
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
    virtual void v54();
    virtual void v55();
    virtual void v56();
    virtual void v57();
    virtual void v58();
    virtual void v59();
    virtual void v60(int a);
    virtual int v61();
    virtual void v62(int a);
    virtual char v63();
};

class Cam_a9f00 {
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
    virtual void v13(int a);
    virtual void v14();
    virtual void v15(int a);
    virtual void v16(int a);
};

class Clock_a9f00 {
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
    virtual float v16();
};

class Target_a9f00 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(int a, int b);
};

class Renderer_a9f00 {
public:
    Cam_a9f00 *cam;
    void FUN_00293da0(float a, float b, float c);
    void FUN_00293d40(int a, int b, float c);
};


class CHypnoticCamera {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22();
    virtual void vfunc_23();
    virtual void vfunc_24();
    virtual void vfunc_25();
    virtual void vfunc_26();
    virtual void vfunc_27();
    virtual void vfunc_28();
    virtual void vfunc_29();
    virtual void vfunc_30();
    virtual void vfunc_31();
    virtual void vfunc_32();
    virtual void vfunc_33();
    virtual void vfunc_34();
    virtual void vfunc_35();
    virtual void vfunc_36();
    char pad04[0x478 - 4];
    Target_a9f00 *target;
    char active;
};

void CHypnoticCamera::vfunc_36()
{
    Input_a9f00 *input = DAT_004dd700->pad->FUN_00086340();
    if (input->FUN_00092940(0xe))
        return;
    if (input->FUN_00092940(0xd))
        return;
    if (!active)
        return;
    if (!target)
        return;
    union {
        char b;
        int w;
    } saved;
    int prev = DAT_0052c2a8->v25();
    DAT_0052c2a8->v24(1);
    saved.b = DAT_0052c2a8->v63();
    DAT_0052c2a8->v62(0);
    int mode = DAT_0052c2a8->v61();
    DAT_0052c2a8->v60(1);
    (*(Renderer_a9f00**)&DAT_0052c2ac)->cam->v15(0);
    (*(Renderer_a9f00**)&DAT_0052c2ac)->cam->v13(0);
#if defined(__clang__)
    // MSVC evaluates the arguments (the clock call) before loading the renderer; clang loads the object first
    float aspect = 1.0f / (*(Clock_a9f00**)&DAT_0052c2a4)->v16();
    (*(Renderer_a9f00**)&DAT_0052c2ac)->FUN_00293da0(1.0f, aspect, 1.0f);
#else
    (*(Renderer_a9f00**)&DAT_0052c2ac)->FUN_00293da0(1.0f, 1.0f / (*(Clock_a9f00**)&DAT_0052c2a4)->v16(), 1.0f);
#endif
    (*(Renderer_a9f00**)&DAT_0052c2ac)->FUN_00293d40(0, 0, 1.0f);
    target->v8(0, 0);
    (*(Renderer_a9f00**)&DAT_0052c2ac)->cam->v16(0);
    DAT_0052c2a8->v60(mode);
    DAT_0052c2a8->v62(saved.w);
    DAT_0052c2a8->v24(prev);
}
} // namespace fn_000a9f00
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

namespace fn_f9c37f09 {

// 0x000aa0d0 FUN_000aa0d0 (92 B): matches/0x000aa0d0.cpp
// sym: ?f@CHypnoticCamera_aa0d0@fn_f9c37f09@@QAEXXZ
void CHypnoticCamera_aa0d0::f() {
    vptr = g_vftable_aa0d0;
    _ReadWriteBarrier();
    if (m478) {
        m478->f1();
        m478 = 0;
    }
    if (m424) {
        m424->f1();
        m424 = 0;
    }
    if (m428) {
        m428->f1();
        m428 = 0;
    }
    ((CHypnoticCamera_nv_aa0d0*)(((CHypnoticCamera*)this)))->Fn();
}


// 0x000aa130 FUN_000aa130 (372 B): equivalent/0x000aa130.cpp
// sym: ?FUN_000aa130@Obj_aa130@fn_f9c37f09@@QAE_NHPAUMat_aa130@2@PAM@Z
// STATUS: equivalent (tools/equiv.py level 3: 20024 inputs, branch coverage 2/2)
// FUN_000aa130 @ 0x000aa130
bool Obj_aa130::FUN_000aa130(int a, Mat_aa130* b, float* out)
{
    if (target == 0)
        return false;
    target->v24(a, 0, 0);
    target->v12(0);
    target->v7();
    Mat_aa130 view = *source->v14();
    Mat_aa130 res;
    ((owners::Matrix_22ca90 *)&res)->FUN_0022ca90((const owners::Matrix_22ca90 *)(Mat_aa130 *)(&view), (const owners::Matrix_22ca90 *)(Mat_aa130 *)b);
    view = res;
    out[0] = view.m[12];
    out[1] = view.m[13];
    out[2] = view.m[14];
    out[3] = view.m[8];
    out[4] = view.m[9];
    out[5] = view.m[10];
    out[6] = view.m[4];
    out[7] = view.m[5];
    out[8] = view.m[6];
    target->v6(1.0f, 1);
    target->v7();
    Mat_aa130* sm = source->v14();
    Vec3_aa130 t;
    t.x = sm->m[12];
    t.y = sm->m[13];
    t.z = sm->m[14];
    ((owners::Obj_22d210 *)&t)->FUN_0022d210((owners::Obj_22d210 *)(struct Mat_aa130 *)b);
    hulk_freg dx = t.x - out[0];
    volatile float dy = t.y - out[1];
    volatile float dz = t.z - out[2];
    out[9] = dx * 999.99994f;
    out[10] = dy * 999.99994f;
    out[11] = dz * 999.99994f;
    return true;
}

} // namespace fn_f9c37f09

// 0x000aa2b0 FUN_000aa2b0 (382 B): equivalent/0x000aa2b0.cpp [wrapped: conflict: World]
// sym: ?FUN_000aa2b0@fn_000aa2b0@@YGMPAUVec3_aa2b0@1@0MMM@Z
namespace fn_000aa2b0 {
// STATUS: equivalent (tools/equiv.py level 3: 20013 inputs, branch coverage 16/16)
// FUN_000aa2b0 @ 0x000aa2b0
// Pinned prototypes of address-named globals and functions that many sources declare (docs/source-tree.md,
// "Pinned address names"). A source includes this instead of declaring them itself; tools/migrate_gen.py
// --family pin does the rewrite and keeps only what still verifies. Hand-maintained: one line per name.
//
// The pointed-to classes are declared, not defined: each source still defines the members it uses as its own
// `struct World { ... };` stub, and tools/gen_tree.py merges those stubs into one class where the layouts agree.

struct World;                     // the game world object (0x004dd700); was World*/Context*/Game*/Global_xxx* in sources
extern "C" {

#define DAT_004dd700 (*(World* *)&::DAT_004dd700)


struct Gfx;                       // the graphics device / context object (0x0052c2a8); was Gfx*/Screen_xxx*/Renderer_xxx*

#define DAT_0052c2a8 (*(Gfx* *)&::DAT_0052c2a8)


struct Singleton_4dd6ec;          // object with getters FUN_00086280/FUN_000862e0 (0x004dd6ec); placeholder name

#define DAT_004dd6ec (*(Singleton_4dd6ec* *)&::DAT_004dd6ec)

}

unsigned __int64 FUN_0027b020(const char* s);                 // string hash
unsigned __int64 FUN_002672f0(const char* s, int a, int b);   // string hash with seed/length
char FUN_001d04d0(const void* typeInfo);                      // type_info test (compares against DAT_0048e100, ...)

struct Vec3_aa2b0 { float x, y, z; };

class Query_aa2b0 {
public:
    bool FUN_00201e00(Vec3_aa2b0 *a, Vec3_aa2b0 *b, int one, Vec3_aa2b0 *out2, Vec3_aa2b0 *out1, int z1, int z2);
};

struct World {
    char pad0[0x24];
    Query_aa2b0 *query;
};


hulk_freg __stdcall FUN_000aa2b0(Vec3_aa2b0 *v1, Vec3_aa2b0 *v2, float a3, float a4, float a5)
{
    hulk_freg m = (v1->y < v2->y) ? v2->y : v1->y;
    if (a3 < m)
        a3 = m;
    float lim = a5 + 0.2f;
    float c = a3 - a4;
    hulk_freg s = (c < lim) ? lim : c;

    Vec3_aa2b0 B = *v2;
    Vec3_aa2b0 A = *v1;
    Vec3_aa2b0 out1;
    Vec3_aa2b0 out2;
    B.y = s;
    A.y = s;
    bool ok = DAT_004dd700->query->FUN_00201e00(&A, &B, 1, &out2, &out1, 0, 0);
    float lo = s;
    float hi;
    if (!ok) {
        hi = s;
    } else {
        hi = 200.0f;
        if (hi - lo > 5.0f) {
            do {
                hulk_freg mid = (hi + lo) * 0.5f;
                B.y = mid;
                A.y = mid;
                ok = DAT_004dd700->query->FUN_00201e00(&A, &B, 1, &out1, &out2, 0, 0);
                if (!ok)
                    hi = mid;
                else
                    lo = mid;
            } while (hi - lo > 5.0f);
        }
    }
    hulk_freg r = hi + a4;
    return (a3 < r) ? r : a3;
}
} // namespace fn_000aa2b0
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8


// 0x000aa430 CHypnoticCamera::vfunc_2 (30 B): matches/0x000aa430.cpp
// sym: ??_GCHypnoticCamera@@UAEPAXI@Z
// Same code shape as 0x00021840 (propagated; names are from that function)
// scalar deleting destructor: FUN_00019420() is the base destructor, thunk_FUN_00267090() operator delete
CHypnoticCamera::~CHypnoticCamera() {}

namespace fn_f9c37f09 {

// 0x000aa450 FUN_000aa450 (552 B): equivalent/0x000aa450.cpp
// sym: ?FUN_000aa450@Tracer_aa450@fn_f9c37f09@@QAEDHPAMPAHHPAUSource_aa450@2@HH@Z
// STATUS: equivalent (tools/equiv.py level 3: 64 inputs, branch coverage 18/18)
// FUN_000aa450 @ 0x000aa450
char Tracer_aa450::FUN_000aa450(int a1, float *m, int *targets, int count, Source_aa450 *src, int a6, int a7)
{
    struct Frame {
        float bestDist;
        V3_aa450 tmp;
        Entry_aa450 e[4];
    } f;

    source = src;
    if (!src->FUN_00035350(&origin)) {
        V3_aa450 *p = FUN_000a92c0(&f.tmp, a1, source);
        origin = *p;
    }

    int idx = -1;
    f.bestDist = 1.0e12f;
    for (int i = 0; i < count; ++i) {
        if (FUN_000aa130(targets[i], m, &f.e[i])) {
            float dx = f.e[i].pos.x - origin.x;
            float dy = f.e[i].pos.y - origin.y;
            float dz = f.e[i].pos.z - origin.z;
            double len = sqrt((double)(dz * dz + dy * dy + dx * dx));
            if (idx < 0 || len < f.bestDist) {
                f.bestDist = (float)len;
                idx = i;
            }
        }
    }

    if (idx < 0)
        return 0;
    if (f.bestDist > 1000.0f)
        return 0;

    best = f.e[idx];
    sink->hit(targets[idx], 0, 0);
    sink->commit(0);
    for (int i = 0; i < 16; ++i)
        matrix[i] = m[i];
    field174 = a6;
    field1c0 = a7;
    if (probe) {
        probe->reset();
        probe->setRange(300.0f, 0);
    }
    flag47c = 0;
    flag47d = 0;
    return 1;
}

} // namespace fn_f9c37f09
