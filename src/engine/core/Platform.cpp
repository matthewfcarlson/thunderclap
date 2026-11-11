// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x0026efc0..0x0026f070 (kind game, layer engine, confidence high), dominant class core::Platform
#include "tree_prelude.h"
#include "gen/core.h"
#define TREE_TU_BEGIN namespace fn_fb3b39af {
#define TREE_TU_END }
#define TREE_LOCAL_CSPHulkProp
#define TREE_LOCAL_pure3d
namespace fn_fb3b39af {} using namespace fn_fb3b39af;
#include "engine/core.h"

// ---- declarations shared by the functions below
namespace fn_fb3b39af {
class IRefCount_26efc0 {
  public:
    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    int mRefCount;
};
class X_26f000 {
  public:
    virtual void f();
    virtual void g_26f000();
    virtual void h(int);
    char pad[4];
    char b;
};
extern X_26f000* g_26f000;
extern "C" int* FUN_002705f0();
class Obj_26f020 {
  public:
    char pad[8];
    unsigned char initialized;
    void Init();
};
namespace pure3d {
class NonCopyable_26f050 : public ::core::IPlatform {
  public:
    virtual void f0();
    virtual void f1();
    virtual NonCopyable_26f050* f2(unsigned char);
};
}
void thunk_FUN_00267090(pure3d::NonCopyable_26f050*);

} // namespace fn_fb3b39af

// 0x0026efc0 core::Platform::vfunc_0 (4 B): matches/0x0026efc0.cpp
// sym: ?vfunc_0@Platform@core@@UAEXXZ
// Same code shape as 0x00018b30 (propagated; names are from that function)
void core::Platform::vfunc_0() {
    ++this->f_04;
}


// 0x0026efd0 core::Platform::vfunc_1 (4 B): matches/0x0026efd0.cpp
// sym: ?vfunc_1@Platform@core@@UAEXXZ
// Same code shape as 0x00268590 (propagated; names are from that function)
 // namespace core
void core::Platform::vfunc_1() {
    --this->f_04;
}

namespace fn_fb3b39af {

// 0x0026f000 FUN_0026f000 (18 B): matches/0x0026f000.cpp
// sym: _FUN_0026f000
extern "C" void FUN_0026f000() {
    X_26f000* p = g_26f000;
    p->b = 0;
    p->h(0);
}


// 0x0026f020 FUN_0026f020 (23 B): matches/0x0026f020.cpp
// sym: ?Init@Obj_26f020@fn_fb3b39af@@QAEXXZ
void Obj_26f020::Init() {
    FUN_002705f0();
    thunk_FUN_003eac33(0, 0);
    initialized = 1;
}


// 0x0026f050 core::Platform::vfunc_2 (31 B): matches/0x0026f050.cpp
// sym: ?f2@NonCopyable_26f050@pure3d@fn_fb3b39af@@UAEPAV123@E@Z
// Same code shape as 0x00045800 (propagated; names are from that function)
pure3d::NonCopyable_26f050* pure3d::NonCopyable_26f050::f2(unsigned char param) {
    *(void**)this = refcount_vftable;
    if ((param & 1) != 0)
        thunk_FUN_00267090(this);
    return this;
}

} // namespace fn_fb3b39af
