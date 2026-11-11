// Merged source tree (docs/merge-once.md): one TU per recovered object; the functions are edited here.
// object 0x001c7ca0..0x001c7e60 (kind game, layer game, confidence high), dominant class Render::Room
#include "tree_prelude.h"
#include "gen/Render.h"
#define TREE_TU_BEGIN namespace fn_f54b098e {
#define TREE_TU_END }
#define TREE_LOCAL_CAction
#define TREE_LOCAL_CCollisionAction
namespace fn_f54b098e {} using namespace fn_f54b098e;
#include "game/Render.h"

// ---- declarations shared by the functions below
namespace fn_f54b098e {
struct StoreBase_1c7ca0 {
    virtual void f0();
    virtual void f1();
    virtual void f2();
};
struct Room_1c7ca0 {};
class StoreBase_1c7cb0 {
  public:
    virtual void x();
    char pad[0x118];
    unsigned char flag;
};
class ObjectTemplate_1c7cb0 {
  public:
    void f();
};
void __cdecl ReleaseTemplate(ObjectTemplate_1c7cb0*);
extern int g_vftable_1c7dc0;
struct Store_1c7dc0 {
    void* m_vptr;
    void base2_dtor();
    void* scalar_dtor(unsigned char flags);
};

} // namespace fn_f54b098e

// 0x001c7ca0 Render::Store<Render::Room>::vfunc_1 (7 B): matches/0x001c7ca0.cpp
// sym: ?vfunc_1@?$Store@VRoom@Render@@@Render@@UAEHH@Z
template <> int Render::Store<Render::Room>::vfunc_1(int __p0) { unsigned int x = (unsigned int)__p0;

    return (int)(x);
}


// 0x001c7cb0 Render::Store<Render::Room>::vfunc_2 (39 B): matches/0x001c7cb0.cpp
// sym: ?vfunc_2@?$Store@VRoom@Render@@@Render@@UAEXPAX@Z
// Same code shape as 0x001c5790 (propagated; names are from that function)
template <> void Render::Store<Render::Room>::vfunc_2(void* __p0) { ObjectTemplate_1c7cb0 * p = (ObjectTemplate_1c7cb0 *)__p0;

    if (this->f_11c && p) {
        p->f();
        ReleaseTemplate(p);
    }
}

namespace fn_f54b098e {

// 0x001c7dc0 Render::Store<Render::Room>::vfunc_0 (43 B): matches/0x001c7dc0.cpp
// sym: ?scalar_dtor@Store_1c7dc0@fn_f54b098e@@QAEPAXE@Z
// Same code shape as 0x0006fb50 (propagated; names are from that function)
void* Store_1c7dc0::scalar_dtor(unsigned char flags) {
    m_vptr = (void*)&g_vftable_1c7dc0;
    ((Render::StoreBase *)this)->FUN_001c7720();
    base2_dtor();
    if (flags & 1)
        thunk_delete(this);
    return this;
}

} // namespace fn_f54b098e
