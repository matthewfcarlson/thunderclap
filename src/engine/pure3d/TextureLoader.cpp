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
// (x64t7) the image registry and the image converter, named by their constructors' addresses (0x002af2d0,
// 0x002de230; were local classes whose constructors were declared only), each allocated natively at HULK_X2 of its
// 32-bit size (compat/ptr.h); the loader's words with its vftable stored by address (the local class's own was a
// stub natively)
struct FUN_002af2d0 {
    FUN_002af2d0() throw();
    char p[HULK_X2(0xa4)];
};
struct FUN_002de230 {
    FUN_002de230() throw();
    char p[HULK_X2(4)];
};
extern int hulk_at_0042ec44;
class TextureLoader {
  public:
    TextureLoader();
    void* vftable;
    int m4;   // content::LoadObject's reference count
    int m8, mc, m10;
    FUN_002af2d0* m14;
    FUN_002de230* m18;
};
extern int hulk_at_003f6098;
extern void Free_00263f30(void*);
extern void Free2_0008d330(void*);
class Obj_2c2620 {
  public:
    void Fini_002ae910();
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
    m4 = 0;
    m8 = 0x19000;
    mc = 0;
    m10 = 0;
    vftable = &hulk_at_0042ec44;
    m14 = new FUN_002af2d0;
    m18 = new FUN_002de230;
}


// 0x002c2620 pure3d::TextureLoader::vfunc_2 (75 B): matches/0x002c2620.cpp
// sym: ?vfunc2@TextureLoader_2c2620@fn_f0efd7bc@@QAEPAV12@E@Z
TextureLoader_2c2620* TextureLoader_2c2620::vfunc2(unsigned char f) {
    Obj_2c2620* o = a14;
    vptr = &hulk_at_0042ec44;
    if (o) {
        o->Fini_002ae910();
        Free2_0008d330(o);
    }
    if (a18)
        a18->Del(1);
    vptr = &hulk_at_003f6098;
    if (f & 1)
        Free_00263f30(this);
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

