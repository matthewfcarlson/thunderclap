// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x002c25b0..0x002c26d0 (kind game, layer engine, confidence medium), dominant class pure3d::TextureLoader
#include "tree_prelude.h"
#include "compat/ptr.h"
#include "gen/pure3d.h"
#define TREE_TU_BEGIN namespace fn_f0efd7bc {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
#define TREE_LOCAL_CEffectStopTrack
namespace fn_f0efd7bc {} using namespace fn_f0efd7bc;
#include "engine/pure3d.h"

// ---- declarations shared by the functions below
void* operator new(size_t n) HULK_NEW_THROW;
namespace fn_f0efd7bc {
class A_2c25b0 {
  public:
    A_2c25b0() throw();
    char p[0xa4];
};
class ImageConverter_2c25b0 {
  public:
    ImageConverter_2c25b0() throw();
    char p[4];
};
class SimpleChunkHandler_2c25b0 {
  public:
    SimpleChunkHandler_2c25b0() {
        m4 = 0;
        m8 = 0x19000;
        mc = 0;
        m10 = 0;
    }
    virtual void f0();
    int m4, m8, mc, m10;
};
class TextureLoader : public SimpleChunkHandler_2c25b0 {
  public:
    TextureLoader();
    virtual void f0();
    A_2c25b0* m14;
    ImageConverter_2c25b0* m18;
};
extern int vt1_2c2620, vt2;
extern void Free(void*);
extern void Free2(void*);
class Obj_2c2620 {
  public:
    void Fini();
};
class Ref_2c2620 {
  public:
    virtual void Del(int);
};
class TextureLoader_2c2620 {
  public:
    void* vptr;
    char p[0x10];
    Obj_2c2620* a14;
    Ref_2c2620* a18;
    TextureLoader_2c2620* vfunc2(unsigned char f);
};
typedef unsigned int u32_2c2670;
struct Result_2c2670 {
    char pad[8];
    u32_2c2670 a;
    u32_2c2670 b;
};
struct This_FUN_002c2370 {
    Result_2c2670* FUN_002c2370(hulk_uintptr);
};


// 0x002c25b0 FUN_002c25b0 (105 B): matches/0x002c25b0.cpp
// sym: ??0TextureLoader@fn_f0efd7bc@@QAE@XZ
TextureLoader::TextureLoader() {
    m14 = new A_2c25b0;
    m18 = new ImageConverter_2c25b0;
}


// 0x002c2620 pure3d::TextureLoader::vfunc_2 (75 B): matches/0x002c2620.cpp
// sym: ?vfunc2@TextureLoader_2c2620@fn_f0efd7bc@@QAEPAV12@E@Z
TextureLoader_2c2620* TextureLoader_2c2620::vfunc2(unsigned char f) {
    Obj_2c2620* o = a14;
    vptr = &vt1_2c2620;
    if (o) {
        o->Fini();
        Free2(o);
    }
    if (a18)
        a18->Del(1);
    vptr = &vt2;
    if (f & 1)
        Free(this);
    return this;
}

} // namespace fn_f0efd7bc

// 0x002c2670 pure3d::TextureLoader::vfunc_5 (38 B): matches/0x002c2670.cpp
// sym: ?vfunc_5@TextureLoader@pure3d@@UAEXPAX00H@Z
void pure3d::TextureLoader::vfunc_5(void* __p0, void* __p1, void* __p2, hulk_intptr __p3) { u32_2c2670 * p2 = (u32_2c2670 *)__p0; u32_2c2670 * p3 = (u32_2c2670 *)__p1; hulk_uintptr p4 = (hulk_uintptr)__p2; u32_2c2670 unused = (u32_2c2670)__p3;

    Result_2c2670* r = ((This_FUN_002c2370*)this)->FUN_002c2370(p4);
    if (r) {
        *(hulk_uintptr*)p2 = (hulk_uintptr)r;
        *p3 = r->a;
        p3[1] = r->b;
    }
}

