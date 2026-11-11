// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002d6720..0x002d6bb0 (kind game, layer engine, confidence high), dominant class pure3d::SpriteParticleRenderer
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "decls/data/engine/pure3d/prop.h"
#include "decls/data/game/global.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f3423c77 {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f3423c77 {} using namespace fn_f3423c77;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
namespace fn_f3423c77 {
extern void* vftable_2d6760;
class SpriteParticleRenderer {
  public:
    SpriteParticleRenderer();
    void* vf;
    int x;
};

} // namespace fn_f3423c77

// 0x002d6720 pure3d::SpriteParticleRenderer::vfunc_3 (6 B): matches/0x002d6720.cpp
// sym: ?vfunc_3@SpriteParticleRenderer@pure3d@@UAEIXZ
// Same code shape as 0x002d1230 (propagated; names are from that function)
unsigned int pure3d::SpriteParticleRenderer::vfunc_3() {
    return 0x54525053;
}


// 0x002d6740 pure3d::ParticleRenderer::vfunc_2 (31 B): matches/0x002d6740.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002d6740@@UAEPAV123@E@Z
namespace fn_002d6740 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class NonCopyable_2d6740 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public NonCopyable_2d6740 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002d6740

namespace fn_f3423c77 {

// 0x002d6760 FUN_002d6760 (16 B): matches/0x002d6760.cpp
// sym: ??0SpriteParticleRenderer@fn_f3423c77@@QAE@XZ
SpriteParticleRenderer::SpriteParticleRenderer() {
    x = 0;
    vf = &vftable_2d6760;
}

} // namespace fn_f3423c77

// 0x002d6770 pure3d::SpriteParticleRenderer::vfunc_2 (31 B): matches/0x002d6770.cpp [wrapped: conflict: pure3d::NonCopyable]
// sym: ?f2@NonCopyable@pure3d@fn_002d6770@@UAEPAV123@E@Z
namespace fn_002d6770 {
// Same code shape as 0x00045800 (propagated; names are from that function)
class ParticleRenderer_2d6770 {
  public:
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
extern void* refcount_vftable[];
namespace pure3d {
class NonCopyable : public ParticleRenderer_2d6770 {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable* f2(unsigned char);
};
} // namespace pure3d
void thunk_FUN_00267090(pure3d::NonCopyable*);
pure3d::NonCopyable* pure3d::NonCopyable::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}
} // namespace fn_002d6770


// 0x002d6790 pure3d::SpriteParticleRenderer::vfunc_4 (977 B): equivalent/0x002d6790.cpp [wrapped: conflict: SpriteParticleRenderer]
// sym: ?vfunc_4@SpriteParticleRenderer@fn_002d6790@@UAEXPAVEmitter_2d6790@2@@Z
extern "C" { extern void* DAT_004dd6ec; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_004dd700; }   // (pinned global: one C name for every view)
extern "C" { extern void* DAT_0052c2a8; }   // (pinned global: one C name for every view)
namespace fn_002d6790 {
// STATUS: equivalent (tools/equiv.py level 3: 159 inputs, branch coverage 8/10, incomplete)
// pure3d::SpriteParticleRenderer::vfunc_4 @ 0x002d6790
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


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double cos(double);
#endif


#if !defined(HULK_COMPAT_CRT)   // (native builds: include/compat/crt.h)
extern "C" double sin(double);
#endif


struct Vec3_2d6790 {
    float x, y, z;
};

struct Matrix {
    float m[16];
};

struct MatrixProvider {
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
    virtual Matrix *v13();
};

struct Inner_2d6790 {
    char pad00[0x18];
    MatrixProvider *provider;
};

struct Holder_2d6790 {
    char pad00[8];
    Inner_2d6790 *inner;
};

class Device2_2d6790 {
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

struct Owner2_2d6790 {
    Device2_2d6790 *device;
};

class VertexBuffer_2d6790;

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
    virtual void v24();
    virtual void v25();
    virtual void v26();
    virtual void v27();
    virtual void v28();
    virtual void v29();
    virtual VertexBuffer_2d6790 *v30(void *handle, int a, int flags, int size, int b);
    virtual void v31(VertexBuffer_2d6790 *vb);
};

class VertexBuffer_2d6790 {
public:
    char pad00[8];
    Vec3_2d6790 *pos;
    char padc[4];
    unsigned int *color;
    float *uv;
    void FUN_0008ef00();
};

struct Handle_2d6790 {
    char pad00[0x10];
    void *handle;
};

struct Particle_2d6790 {
    Vec3_2d6790 pos;
    unsigned int color;
    float size;
    float angle;
    char pad18;
    signed char index;
};

struct Atlas {
    char pad00[0x10];
    float *cols;
};

class Emitter_2d6790 {
public:
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    virtual void v4();
    virtual void v5();
    virtual void v6();
    virtual Handle_2d6790 *v7();
    virtual void v8();
    virtual void v9();
    virtual void v10();
    virtual void v11();
    virtual void v12();
    virtual unsigned int v13();
    char pad04[0x1bc - 4];
    Atlas *atlas;
    char pad1c0[0x1c8 - 0x1c0];
    Particle_2d6790 **particles;
};

extern "C" int FUN_0034483c();

static inline void Emit(VertexBuffer_2d6790 *vb, unsigned int color, float u, float v, float x, float y, float z)
{
    *vb->color = color;
    vb->uv[0] = u;
    vb->uv[1] = v;
    vb->pos->x = x;
    vb->pos->y = y;
    vb->pos->z = z;
    vb->FUN_0008ef00();
}

class SpriteParticleRenderer {
public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4(Emitter_2d6790 *e);
};

void SpriteParticleRenderer::vfunc_4(Emitter_2d6790 *e)
{
    unsigned int count = e->v13();
    Atlas *atlas = e->atlas;
    if (count == 0) {
        return;
    }
    Matrix m = *(*(Holder_2d6790**)&DAT_0052c2b4)->inner->provider->v13();
    (*(Owner2_2d6790**)&DAT_0052c2ac)->device->v21(0);
    void *handle = e->v7()->handle;
    VertexBuffer_2d6790 *vb = DAT_0052c2a8->v30(handle, 0, 0x2021, count * 6, 0);
    for (unsigned int i = 0; i < count; i++) {
        Particle_2d6790 *p = e->particles[i];
        hulk_freg a = p->angle + 0.7853982f;
        hulk_freg c = (float)cos(a) * p->size;
        hulk_freg s = (float)sin(a) * p->size;
        hulk_freg x = (m.m[0] * p->pos.x + m.m[8] * p->pos.z) + m.m[4] * p->pos.y + m.m[12];
        hulk_freg y = (m.m[1] * p->pos.x + m.m[9] * p->pos.z) + m.m[5] * p->pos.y + m.m[13];
        hulk_freg z = (m.m[2] * p->pos.x + m.m[10] * p->pos.z) + m.m[6] * p->pos.y + m.m[14];
        hulk_freg ax = x + c;
        hulk_freg ay = y + s;
        hulk_freg bx = x - s;
        hulk_freg by = y + c;
        hulk_freg cx = x - c;
        hulk_freg cy = y - s;
        hulk_freg dx = x + s;
        hulk_freg dy = y - c;
        hulk_freg az = z;
        hulk_freg bz = z;
        hulk_freg cz = z;
        hulk_freg dz = z;
        float *cols = atlas->cols + p->index;
        hulk_freg u0 = cols[0];
        hulk_freg u1 = cols[1];
        unsigned int color = p->color;
        hulk_freg r = p->size / z;
        hulk_freg r2 = r * r;
        if (r2 > 0.225f) {
            if (r2 > 0.45f) {
                az = -1.0f;
                bz = -1.0f;
                cz = -1.0f;
                dz = -1.0f;
            } else {
                int alpha = (int)((1.0f - (r2 - 0.225f) * 4.4444447f) * (int)(color >> 24));
                color = (color & 0xffffff) | (alpha << 24);
            }
        }
        Emit(vb, color, u1, 1.0f, ax, ay, az);
        Emit(vb, color, u0, 0.0f, cx, cy, cz);
        Emit(vb, color, u0, 1.0f, bx, by, bz);
        Emit(vb, color, u1, 1.0f, ax, ay, az);
        Emit(vb, color, u1, 0.0f, dx, dy, dz);
        Emit(vb, color, u0, 0.0f, cx, cy, cz);
    }
    DAT_0052c2a8->v31(vb);
    (*(Owner2_2d6790**)&DAT_0052c2ac)->device->v16(0);
}
} // namespace fn_002d6790
#undef DAT_004dd6ec
#undef DAT_004dd700
#undef DAT_0052c2a8

