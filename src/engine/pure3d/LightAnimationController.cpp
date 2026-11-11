// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002a87c0..0x002a9410 (kind game, layer engine, confidence high), dominant class pure3d::LightAnimationController
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/game/global.h"
#include "gen/owners.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f5607ee0 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f5607ee0 {} using namespace fn_f5607ee0;
#include "engine/pure3d.h"
// (ren2) __RTDynamicCast's own name (CRT, C linkage)
extern "C" void* __cdecl __RTDynamicCast(void*, long, void*, void*, int);

// ---- declarations shared by the functions below
namespace fn_f5607ee0 {
class BlendFrameController_2a87c0 {
  public:
    virtual void Fn();
    BlendFrameController_2a87c0();
};
struct Obj_2a8800 {
    char pad[0x1c];
    int tag;
    char pad2[8];
    int count;
};
struct Vec3_2a8840 { float x, y, z; };
union Scalar_2a8840 {
    float f;
    int i;
    unsigned char b;
};
class Channel {
public:
    virtual void vf0();
    virtual void vf1();
    virtual void vf2();
    virtual void vf3();
    virtual void sampleVec3(float frame, Vec3_2a8840 *out);
    void FUN_0028ac90(float frame, unsigned char *out);
};
struct ChannelSet_2a8840 {
    Channel *FUN_00288960(unsigned int tagLo, unsigned int tagHi);
};
struct Source_2a8840 {
};
struct Track {
    char data[0x110 - 0x2c];
    float FUN_00284f70();
};
class Light {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void setDirection(Vec3_2a8840 *dir);
    void FUN_002a07a0(int color);
    void FUN_002a0820(int value);
    void FUN_002a2fc0(Vec3_2a8840 *dir);
    void FUN_002c4250(Vec3_2a8840 *dir);
    void FUN_002c3d00(float x, float y, float z);
    void FUN_002c41a0(float x, float y, float z);
    void FUN_002c3f00(float x, float y, float z);
    void FUN_002c41e0(float x, float y, float z);
};
class LightAnimationController : public BlendFrameController_2a87c0 {
  public:
    virtual void _m_vf1();
    virtual void _m_vf2();
    virtual void _m_vf3();
    virtual void _m_vf4();
    virtual void _m_vf5();
    virtual void _m_vf6();
    virtual void _m_vf7();
    virtual void _m_vf8();
    virtual void _m_vf9();
    virtual void _m_vf10();
    virtual void _m_vf11();
    virtual void _m_vf12();
    virtual void _m_vf13();
    virtual void _m_vf14();
    virtual void _m_vf15();
    virtual void _m_vf16();
    virtual void _m_vf17();
    virtual void _m_vf18();
    virtual void _m_vf19();
    virtual void _m_vf20();
    virtual void _m_vf21();
    virtual void _m_vf22();
    virtual void _m_vf23();
    virtual void _m_vf24();
    virtual void _m_vf25();
    virtual void _m_vf26();
    virtual void vfunc_27();
    virtual void _m_vf28();
    virtual void _m_vf29();
    LightAnimationController();
    char _m_pad_4[0x28];
    Track track;
    union { int a; int mode; };
    union { int b; Light *light; };
};
struct Sink_2a8840 {
};
struct Globals_2a8840 {
    char pad[8];
    Sink_2a8840 *sink;
};
extern void* hulk_at_0042ddb4[];
class Ref_2a8a70 {
  public:
    virtual void F0();
    virtual void Release();
};
class BlendFrameController_2a8a70 {
  public:
    void* vptr;
    void Fin_00285f50();
};
class LightAnimationController_2a8a70 : public BlendFrameController_2a8a70 {
  public:
    char pad[272];
    Ref_2a8a70* m;
    ~LightAnimationController_2a8a70();
};
struct Object { virtual void AddRef(); virtual void Release(); };
extern char DAT_004c532c, DAT_004c534c, DAT_004c5368, DAT_004cf634, DAT_004cf658;
extern void* __cdecl FUN_00344e74(Object*, int, const void*, const void*, int);
struct LightAnimationController_2a8aa0 {
 char pad[0x110];
 int kind;
 Object* object;
 void Set(Object* value);
};
extern void* g_vftable_2a9300[];
} // namespace fn_f5607ee0
void operator delete(void*);
namespace fn_f5607ee0 {
class Ref_2a9300 {
  public:
    virtual void F0();
    virtual void Release();
};
class BlendFrameController_2a9300 {
  public:
    void* vptr;
    void Fin_00285f50();
};
class LightAnimationController_2a9300 : public BlendFrameController_2a9300 {
  public:
    char pad[0x114 - 4];
    Ref_2a9300* m;
    LightAnimationController_2a9300* f2(unsigned char flags);
};
typedef unsigned int u32_2a9380;
struct LightAnimationController_2a9380 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    virtual void f3();
    virtual LightAnimationController_2a9380* f4();
    virtual void f5();
    virtual void f6();
    virtual void f7();
    virtual void f8();
    virtual void f9();
    virtual void f10();
    virtual void f11();
    virtual void f12();
    virtual void f13();
    virtual void f14();
    virtual void f15();
    virtual void f16();
    virtual void f17();
    virtual void f18();
    virtual void f19();
    virtual void f20();
    virtual void f21();
    virtual void f22();
    virtual void f23();
    virtual void f24();
    virtual void f25();
    virtual void f26();
    virtual void f27();
    virtual void f28();
    virtual void f29();
    char pad[0x10c];
    u32_2a9380 field110;
    u32_2a9380 field114;
    void init_00285d70(LightAnimationController_2a9380*);
    void finish_002a8aa0(u32_2a9380);
};
extern "C" void* __cdecl alloc(hulk_uintptr);
extern u32_2a9380 camera_vtable_2a9380;
typedef unsigned int U_2a93e0;
extern char hulk_at_0048f610;
struct LightAnimationController_nv_2a93e0 {
    void Finish_002a8aa0(U_2a93e0);
};


// 0x002a87c0 FUN_002a87c0 (38 B): matches/0x002a87c0.cpp
// sym: ??0LightAnimationController@fn_f5607ee0@@QAE@XZ
LightAnimationController::LightAnimationController() {
    a = -1;
    b = 0;
}

} // namespace fn_f5607ee0

// 0x002a87f0 pure3d::LightAnimationController::vfunc_3 (3 B): matches/0x002a87f0.cpp
// sym: ?vfunc_3@LightAnimationController@pure3d@@UAE_NXZ
// Same code shape as 0x0032fce0 (propagated; names are from that function)
bool pure3d::LightAnimationController::vfunc_3() {
    return true;
}


// 0x002a8800 pure3d::LightAnimationController::vfunc_26 (39 B): matches/0x002a8800.cpp
// sym: ?vfunc_26@LightAnimationController@pure3d@@UAE_NPAX@Z
bool pure3d::LightAnimationController::vfunc_26(void* __p0) { void * p = (void *)__p0;

    if (p && ((Obj_2a8800*)p)->count > 0)
        return ((Obj_2a8800*)p)->tag == 0x4554494c;
    return false;
}

namespace fn_f5607ee0 {

// 0x002a8840 pure3d::LightAnimationController::vfunc_27 (556 B): equivalent/0x002a8840.cpp
// sym: ?vfunc_27@LightAnimationController@fn_f5607ee0@@UAEXXZ @9142e47bbf31 @wad894f8a699a
// STATUS: equivalent (tools/equiv.py level 3: 3027 inputs, branch coverage 30/30)
// pure3d::LightAnimationController::vfunc_27 @ 0x002a8840
void LightAnimationController::vfunc_27()
{
    struct Frame {
        Scalar_2a8840 s;
        Vec3_2a8840 v;
    } fr;
    Source_2a8840 *src = ((Source_2a8840 *)((owners::Target_284f50 *)&track)->FUN_00284f50());
    fr.s.f = track.FUN_00284f70();
    ChannelSet_2a8840 *cs = ((ChannelSet_2a8840 *)((owners::Target_288a10 *)src)->FUN_00288a10(0));
    Channel *c;

    if (light == 0) {
        c = cs->FUN_00288960(0x524c43, 0x524c43);
        if (c != 0) {
            ((owners::Track_28ad20 *)c)->FUN_0028ad20(fr.s.f, (unsigned int *)(&fr.s.i));
            if ((*(Globals_2a8840**)&DAT_0052c2b4)->sink != 0) {
                ((owners::C_293e90 *)((*(Globals_2a8840**)&DAT_0052c2b4)->sink))->FUN_00293e90(fr.s.i);
            }
        }
        return;
    }

    c = cs->FUN_00288960(0x524c43, 0x524c43);
    float frame = fr.s.f;
    if (c != 0) {
        ((owners::Track_28ad20 *)c)->FUN_0028ad20(frame, (unsigned int *)(&fr.s.i));
        light->FUN_002a07a0(fr.s.i);
    }

    c = cs->FUN_00288960(0x4d524150, 0x54434556);
    if (c != 0) {
        c->sampleVec3(frame, &fr.v);
        light->setDirection(&fr.v);
    }

    c = cs->FUN_00288960(0x524944, 0x54434556);
    if (c != 0) {
        c->sampleVec3(frame, &fr.v);
        if (mode == 2) {
            light->FUN_002a2fc0(&fr.v);
        } else if (mode == 3) {
            light->FUN_002c4250(&fr.v);
        }
    }

    c = cs->FUN_00288960(0x4e545441, 0x54434556);
    if (c != 0) {
        c->sampleVec3(frame, &fr.v);
        if (mode == 1) {
            light->FUN_002c3f00(fr.v.x, fr.v.y, fr.v.z);
        } else if (mode == 3) {
            light->FUN_002c41a0(fr.v.x, fr.v.y, fr.v.z);
        } else if (mode == 4) {
            light->FUN_002c3d00(fr.v.x, fr.v.y, fr.v.z);
        }
    }

    c = cs->FUN_00288960(0x454e4f43, 0x54434556);
    if (c != 0 && mode == 3) {
        c->sampleVec3(frame, &fr.v);
        light->FUN_002c41e0(fr.v.x, fr.v.y, fr.v.z);
    }

    c = cs->FUN_00288960(0x4c424145, 0x4c4f4f42);
    if (c != 0) {
        c->FUN_0028ac90(frame, &fr.s.b);
        light->FUN_002a0820(fr.s.i);
    }
}


// 0x002a8a70 FUN_002a8a70 (42 B): matches/0x002a8a70.cpp
// sym: ??1LightAnimationController_2a8a70@fn_f5607ee0@@QAE@XZ
LightAnimationController_2a8a70::~LightAnimationController_2a8a70() {
    vptr = hulk_at_0042ddb4;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_00285f50();
}


// 0x002a8aa0 FUN_002a8aa0 (263 B): equivalent/0x002a8aa0.cpp
// sym: ?Set@LightAnimationController_2a8aa0@fn_f5607ee0@@QAEXPAUObject@2@@Z @4b8d6e798317 @wb06df9fe8e8b
// STATUS: equivalent (tools/equiv.py level 3: 3000 inputs, branch coverage 12/12)
// FUN_002a8aa0 @ 0x002a8aa0
void LightAnimationController_2a8aa0::Set(Object* value) {
 if (value) value->AddRef();
 if (object) object->Release();
 object = value;
 kind = -1;
 if (!object) { kind = 0; return; }
 if (FUN_00344e74(object,0,&DAT_004c534c,&DAT_004cf658,0)) { kind=2; return; }
 if (FUN_00344e74(object,0,&DAT_004c534c,&DAT_004c532c,0)) { kind=1; return; }
 if (FUN_00344e74(object,0,&DAT_004c534c,&DAT_004c5368,0)) { kind=3; return; }
 kind = FUN_00344e74(object,0,&DAT_004c534c,&DAT_004cf634,0) ? 4 : 0;
}

} // namespace fn_f5607ee0

// 0x002a8bb0 pure3d::LightAnimationController::vfunc_28 (1853 B): equivalent/0x002a8bb0.cpp [wrapped: conflict: Light; LightAnimationController]
// sym: ?v28@LightAnimationController@fn_002a8bb0@@UAEXXZ @eeaded3d3c7f @w21ec0d2610b5
namespace fn_002a8bb0 {
// STATUS: equivalent (tools/equiv.py level 3: 145 inputs, branch coverage 76/84, incomplete)
// pure3d::LightAnimationController::vfunc_28 @ 0x002a8bb0

struct V3_2a8bb0 {
    float x, y, z;
};

class VChan {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4(unsigned int t, V3_2a8bb0 *out);
};

struct ColChan {
    void FUN_0028ad20(unsigned int t, unsigned int *out);
};

struct BoolChan {
    void FUN_0028ac90(unsigned int t, char *out);
};

struct Chans_2a8bb0 {
    void *FUN_00288960(int a, int b);
};

struct Anim_2a8bb0 {
    Chans_2a8bb0 *FUN_00288a10(int i);
};

struct Elem_2a8bb0 {
    char pad[0x2c];
    Anim_2a8bb0 *FUN_00284f50();
    float FUN_00284f70();
    float FUN_00284f60();
};

class Light {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual void v7();
    virtual void v8(V3_2a8bb0 *out);
    void FUN_002c3f00(float x, float y, float z);
    void FUN_002a2fc0(V3_2a8bb0 *v);
    void FUN_002c4250(V3_2a8bb0 *v);
    void FUN_002c41a0(float x, float y, float z);
    void FUN_002c41e0(float x, float y, float z);
    void FUN_002c3d00(float x, float y, float z);
    void FUN_002a07a0(unsigned int color);
    void FUN_002a0820(char flag);
};

struct Sink_2a8bb0 {
    void FUN_00293e90(unsigned int color);
};
struct SinkHolder_2a8bb0 {
    char pad0[8];
    Sink_2a8bb0 *f8;
};

union Slot_2a8bb0 {
    volatile float f;
    unsigned int u;
    int i;
};

struct Frame_2a8bb0 {
    Slot_2a8bb0 s0, s4, s8, sc;                // 0x00..0x0c
    volatile float acc0, acc1, acc2, acc3;  // 0x10..0x1c
    char pad20[3];
    char flag;                          // 0x23
    volatile float cx, cy, cz;          // 0x24
    volatile float dx, dy, dz;          // 0x30
    volatile float ax, ay, az;          // 0x3c
    volatile float e;                   // 0x48
    volatile float bx, by, bz;          // 0x4c
    int idx;                            // 0x58
    V3_2a8bb0 tdir;                            // 0x5c
    V3_2a8bb0 tcone;                           // 0x68
    V3_2a8bb0 tattn;                           // 0x74
    V3_2a8bb0 tpos;                            // 0x80
};

class LightAnimationController {
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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    char pad04[0x28 - 4];
    unsigned int count;         // 0x28
    Elem_2a8bb0 elems[1];              // 0x2c
    char pad58[0x110 - 0x58];
    int mode;                   // 0x110
    Light *light;               // 0x114
};

void LightAnimationController::v28()
{
    Frame_2a8bb0 f;
    unsigned int cnt = count;
    unsigned int color;
    int c0, c1, c2, c3;

    f.acc3 = 0.0f;
    f.acc2 = 0.0f;
    f.acc1 = 0.0f;
    f.acc0 = 0.0f;
    if (light != 0) {
        f.ax = 0.0f;
        f.ay = 0.0f;
        f.az = 0.0f;
        f.bx = 0.0f;
        f.by = 0.0f;
        f.bz = 0.0f;
        f.cx = 0.0f;
        f.cy = 0.0f;
        f.cz = 0.0f;
        f.dx = 0.0f;
        f.dy = 0.0f;
        f.dz = 0.0f;
        f.e = 0.0f;
        f.idx = 0;
        if (cnt != 0) {
            Elem_2a8bb0 *el = &elems[0];
            do {
                Chans_2a8bb0 *Y = el->FUN_00284f50()->FUN_00288a10(0);
                f.s8.f = el->FUN_00284f70();
                f.s4.f = el->FUN_00284f60();
                f.s0.f = 1.0f - f.s4.f;
                unsigned int t = f.s8.u;
                void *clr = Y->FUN_00288960(0x524c43, 0x524c43);
                if (clr != 0) {
                    ((ColChan *)clr)->FUN_0028ad20(t, &f.sc.u);
                    unsigned int col = f.sc.u;
                    f.s8.i = (col >> 16) & 0xff;
                    f.acc0 = (float)f.s8.i * f.s4.f + f.s0.f * f.acc0;
                    f.s8.i = (col >> 8) & 0xff;
                    f.acc1 = (float)f.s8.i * f.s4.f + f.s0.f * f.acc1;
                    f.s8.i = col & 0xff;
                    f.acc2 = (float)f.s8.i * f.s4.f + f.s0.f * f.acc2;
                    f.s8.i = col >> 24;
                    f.acc3 = (float)f.s8.i * f.s4.f + f.s0.f * f.acc3;
                }
                void *pv = Y->FUN_00288960(0x4d524150, 0x54434556);
                if (pv != 0) {
                    ((VChan *)pv)->v4(t, &f.tpos);
                    f.az = f.az * f.s0.f;
                    f.ax = f.tpos.x * f.s4.f + f.ax * f.s0.f;
                    f.ay = f.tpos.y * f.s4.f + f.ay * f.s0.f;
                    f.az = f.tpos.z * f.s4.f + f.az;
                }
                void *pd = Y->FUN_00288960(0x524944, 0x54434556);
                if (pd != 0) {
                    ((VChan *)pd)->v4(t, &f.tdir);
                    f.bz = f.tdir.z * f.s0.f;
                    f.bx = f.tdir.x * f.s4.f + f.tdir.x * f.s0.f;
                    f.by = f.tdir.y * f.s4.f + f.tdir.y * f.s0.f;
                    f.bz = f.tdir.z * f.s4.f + f.bz;
                }
                void *pa = Y->FUN_00288960(0x4e545441, 0x54434556);
                if (pa != 0) {
                    ((VChan *)pa)->v4(t, &f.tattn);
                    f.cz = f.cz * f.s0.f;
                    f.cx = f.tattn.x * f.s4.f + f.cx * f.s0.f;
                    f.cy = f.tattn.y * f.s4.f + f.cy * f.s0.f;
                    f.cz = f.tattn.z * f.s4.f + f.cz;
                }
                void *pc = Y->FUN_00288960(0x454e4f43, 0x54434556);
                if (pc != 0) {
                    ((VChan *)pc)->v4(t, &f.tcone);
                    f.dz = f.dz * f.s0.f;
                    f.dx = f.tcone.x * f.s4.f + f.dx * f.s0.f;
                    f.dy = f.tcone.y * f.s4.f + f.dy * f.s0.f;
                    f.dz = f.tcone.z * f.s4.f + f.dz;
                }
                void *pe = Y->FUN_00288960(0x4c424145, 0x4c4f4f42);
                if (pe != 0) {
                    ((BoolChan *)pe)->FUN_0028ac90(t, &f.flag);
                    f.e = (f.flag == 1 ? 1.0f : 0.0f) * f.s4.f + f.s0.f * f.e;
                }
                f.idx++;
                el++;
            } while ((unsigned int)f.idx < count);
        }
        switch (mode) {
        case 1:
            light->v8((V3_2a8bb0 *)&f.ax);
            light->FUN_002c3f00(f.cx, f.cy, f.cz);
            break;
        case 2:
            light->FUN_002a2fc0((V3_2a8bb0 *)&f.bx);
            break;
        case 3:
            light->v8((V3_2a8bb0 *)&f.ax);
            light->FUN_002c4250((V3_2a8bb0 *)&f.bx);
            light->FUN_002c41a0(f.cx, f.cy, f.cz);
            light->FUN_002c41e0(f.dx, f.dy, f.dz);
            break;
        case 4:
            light->FUN_002c3d00(f.cx, f.cy, f.cz);
            break;
        default:
            break;
        }
        c0 = (int)f.acc0;
        if (c0 < 0)
            c0 = 0;
        else if (c0 > 0xff)
            c0 = 0xff;
        c1 = (int)f.acc1;
        if (c1 < 0)
            c1 = 0;
        else if (c1 > 0xff)
            c1 = 0xff;
        c2 = (int)f.acc2;
        if (c2 < 0)
            c2 = 0;
        else if (c2 > 0xff)
            c2 = 0xff;
        c3 = (int)f.acc3;
        if (c3 < 0)
            c3 = 0;
        else if (c3 > 0xff)
            c3 = 0xff;
        color = (((c3 << 8 | c0) << 8 | c1) << 8) | c2;
        light->FUN_002a07a0(color);
        if (f.e > 0.5f)
            light->FUN_002a0820(1);
        else
            light->FUN_002a0820(0);
        return;
    }

    if (cnt != 0) {
        Elem_2a8bb0 *el = &elems[0];
        unsigned int i = 0;
        do {
            Chans_2a8bb0 *Y = el->FUN_00284f50()->FUN_00288a10(0);
            f.sc.f = el->FUN_00284f70();
            f.s0.f = el->FUN_00284f60();
            f.s4.f = 1.0f - f.s0.f;
            void *clr = Y->FUN_00288960(0x524c43, 0x524c43);
            if (clr != 0) {
                ((ColChan *)clr)->FUN_0028ad20(f.sc.u, &f.s8.u);
                unsigned int col = f.s8.u;
                f.sc.i = (col >> 16) & 0xff;
                f.acc0 = (float)f.sc.i * f.s0.f + f.s4.f * f.acc0;
                f.sc.i = (col >> 8) & 0xff;
                f.acc1 = (float)f.sc.i * f.s0.f + f.s4.f * f.acc1;
                f.sc.i = col & 0xff;
                f.acc2 = (float)f.sc.i * f.s0.f + f.s4.f * f.acc2;
                f.sc.i = col >> 24;
                f.acc3 = (float)f.sc.i * f.s0.f + f.s4.f * f.acc3;
            }
            i++;
            el++;
        } while (i < count);
    }
    c0 = (int)f.acc0;
    if (c0 < 0)
        c0 = 0;
    else if (c0 > 0xff)
        c0 = 0xff;
    c1 = (int)f.acc1;
    if (c1 < 0)
        c1 = 0;
    else if (c1 > 0xff)
        c1 = 0xff;
    c2 = (int)f.acc2;
    if (c2 < 0)
        c2 = 0;
    else if (c2 > 0xff)
        c2 = 0xff;
    c3 = (int)f.acc3;
    if (c3 < 0)
        c3 = 0;
    else if (c3 > 0xff)
        c3 = 0xff;
    Sink_2a8bb0 *sink = (*(SinkHolder_2a8bb0**)&DAT_0052c2b4)->f8;
    if (sink != 0) {
        color = (((c3 << 8 | c0) << 8 | c1) << 8) | c2;
        sink->FUN_00293e90(color);
    }
}
} // namespace fn_002a8bb0

namespace fn_f5607ee0 {

// 0x002a9300 pure3d::LightAnimationController::vfunc_2 (63 B): matches/0x002a9300.cpp
// sym: ?f2@LightAnimationController_2a9300@fn_f5607ee0@@QAEPAV12@E@Z
LightAnimationController_2a9300* LightAnimationController_2a9300::f2(unsigned char flags) {
    vptr = g_vftable_2a9300;
    _ReadWriteBarrier();
    if (m) {
        m->Release();
        m = 0;
    }
    Fin_00285f50();
    if (flags & 1)
        operator delete(this);
    return this;
}


// 0x002a9380 pure3d::LightAnimationController::vfunc_4 (81 B): matches/0x002a9380.cpp
// sym: ?f4@LightAnimationController_2a9380@fn_f5607ee0@@UAEPAU12@XZ
// Same code shape as 0x00293910 (propagated; names are from that function)
LightAnimationController_2a9380* LightAnimationController_2a9380::f4() {
    LightAnimationController_2a9380* p = (LightAnimationController_2a9380*)alloc(0x118);
    if (p) {
        p->init_00285d70(this);
        *(hulk_uintptr*)p = (hulk_uintptr)&camera_vtable_2a9380;
        p->field110 = 0xffffffff;
        p->field114 = 0;
        p->finish_002a8aa0(field114);
        return p;
    }
    return 0;
}

} // namespace fn_f5607ee0

// 0x002a93e0 pure3d::LightAnimationController::vfunc_5 (42 B): matches/0x002a93e0.cpp
// sym: ?vfunc_5@LightAnimationController@pure3d@@UAEXPAX@Z
// Same code shape as 0x00293970 (propagated; names are from that function)
void pure3d::LightAnimationController::vfunc_5(void* __p0) { hulk_uintptr arg = (hulk_uintptr)__p0;

    U_2a93e0 x = ((U_2a93e0)(hulk_uintptr)__RTDynamicCast((void*)(arg), 0, (void*)(&hulk_at_0048f610), (void*)(&CameraRTTI), 0));
    ((LightAnimationController_nv_2a93e0*)this)->Finish_002a8aa0(x);
}

